/*
 * divide-network.c
 *
 */
typedef int make_iso_compilers_happy;


#include "divide-network.h"

/* Computes the division of the network to groups */
void divideNetworkGroups(char *path, modularityMatrix *B)
{
	Vector *g;
	Division *div;
	divisionArray *P = allocateDivisionArray(B->size);
	divisionArray *O = allocateDivisionArray(B->size);

	/* while P doesn't contain only -1 = can't divide more groups = P is empty */
	while (!isEmpty(P))
	{
		g = getNextG(P);
		div = divideGroupTwoGroups(B, g->array, g->size);

		if (div->size1 == 0 || div->size2 == 0)
		{
		    addGroup(O, g->array, g->size);
		}
		else
		{
			if (div->size1 == 1)
				addGroup(O, div->group1, div->size1);
			else
				addGroup(P, div->group1, div->size1);

			if (div->size2 == 1)
				addGroup(O, div->group2, div->size2);
			else
				addGroup(P, div->group2, div->size2);
		}

		destroyDivision(div);
		destroyVector(g);
	}


	/* divideGroupTwoGroups(modularityMatrix *B, int *g, int ng) - Algorithm 2 */

	destroyDivisionArray(P);

	/* printArrayInt(O->array, B->size); */
	/* write to file */
	writeDivisionToFile(path, O);
	destroyDivisionArray(O);
}

/* Writes the division of the network to the output file */
void writeDivisionToFile(char *path, divisionArray* O)
{
	int n; int i; int groupSize;
	Vector *v; int arr[1];

	FILE *outputFile = fopen(path, "w");
	if (outputFile == NULL)
	{
		printf("could not write to file");
		exit(1);
	}

	arr[0] = O->max;
	O->min = 1;
	/* printf("max: %d, min: %d\n", O->max, O->min); */

	n = fwrite(arr, sizeof(int), 1, outputFile);
	if (n != 1)
	{
		printf("could not write to file");
		exit(1);
	}

	for (i = 1; i <= O->max; i++)
	{
		groupSize = getGroupSize(O, i);
		v = getNextG(O);

		/* printVector(v); */

		arr[0] = groupSize;
		n = fwrite(arr, sizeof(int), 1, outputFile);
		if (n != 1)
		{
			printf("could not write to file");
			exit(1);
		}

		n = fwrite(v->array, sizeof(int), groupSize, outputFile);
		if (n !=  groupSize)
		{
			printf("could not write to file");
			exit(1);
		}
		destroyVector(v);
	}

	n = fclose(outputFile);
	if (n != 0)
	{
		printf("couldn't close file\n");
		exit(1);
	}

}
