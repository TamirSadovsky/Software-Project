/*
 * divide-network-to-2.c
 *
 */

#include "divide-network-to-2.h"

#define IS_POSITIVE(X) ((X) > 0.0001)

/* Computes the division of the network to 2 groups */
Division *divideNetworkTwoGroups(char* path)
{
	modularityMatrix *B = loadModularityMatrix(path);
	/* printModularityMatrix(B); */
	Division *div = divideTwoGroups(B);
	free(B->g);
	destroyModularityMatrix(B);
	return div;
}

/* Performs the division of a group to 2 groups */
Division *divideTwoGroups(modularityMatrix *B)
{
	double m; int *s; Division *div;
	eigenPair *pair = getEigenPair(B);  /* 1 */

	s = compute_S(pair->eigenVector, B->size); /* 3 */

	if (!IS_POSITIVE(pair->eigenValue)) /* 2 */
	{
		/* printf("the group is indivisible - eigenValue is negative \n"); */
		div = allocateDivision(s, B->g ,B->size);
		free(s);
		destroyEigenPair(pair);
		return div;
	}

	/* 4 */
	m = computeModularity(B, s);

	if (!IS_POSITIVE(m))
	{
		/*
		 * if the computed modularity is non-positive then the group is indivisible
		 */
	}

	modularityMaximization(B, s);

	div = allocateDivision(s, B->g ,B->size);
	free(s);
	destroyEigenPair(pair);
	return div; /* 5 */
}


/* loads the modularity matrix of the network from the input file path */
modularityMatrix *loadModularityMatrix(char* path)
{
	FILE* inputFile;
	modularityMatrix *B;
	int n = 0;

	inputFile = fopen(path , "r");
	if (inputFile == NULL)
	{
		printf("couldn't open input file\n");
		exit(1);
	}

	B = computeModularityMatrix(inputFile);

	n = fclose(inputFile);
	if (n != 0)
	{
		printf("couldn't close file\n");
		exit(1);
	}

	return B;
}

/* loads the content of the modularity matrix form the file */
modularityMatrix *computeModularityMatrix(FILE* file)
{
	int arr[1]; /* fread needs an array */
	int n; int i;
	int *row; int *k;
	int *g; double *f;
	modularityMatrix *B;
	spmat *spm;
	int M = 0;
	double sum; double max = 0;
	spnode *temp;

	fread(arr, sizeof(int), 1, file);
	n = arr[0];

	g = allocateArrayInt(n);
	for (i = 0; i < n; i++)
	{
		g[i] = i;
	}

	spm = allocateSpmat(n);
	k = allocateArrayInt(n);
	f = allocateArrayDouble(n);

	row = allocateArrayInt(n); /* allocate memory one time for the whole run */

	for (i = 0; i < n; i++)
	{
		fread(arr, sizeof(int), 1, file);
		k[i] = arr[0]; M += arr[0];
		fread(row, sizeof(int), arr[0], file);

		addRow(spm, row, i, arr[0]);
	}
	free(row);

	if (M == 0)
	{
		printf("empty graph\n");
		exit(1);
	}

	for (i = 0; i < n; i++)
	{
		sum = k[i]; /* sum of the row without adjacency  matrix */
		temp = spm->spl->list[i]->next;
		while (temp != NULL)
		{
			sum += (1 - (double) (2 * k[i] * k[temp->col]) / M); /* remove unnecessary parts from the sum of the row before */
			temp = temp->next;
		}

		if (sum > max)
			max = sum;
	}

	B = allocateModularityMatrix(spm, k, M, f, g, max, n);

	return B;
}

/* Computes the vector S based on the eigenVector */
int *compute_S(double *u , int n)
{
    int i;
    int *vector;
    vector = allocateArrayInt(n);

    for(i = 0; i < n; i++)
    {
       if (IS_POSITIVE(u[i]))
        vector[i] = 1;
       else
        vector[i] = -1;
    }

    return vector;
}
