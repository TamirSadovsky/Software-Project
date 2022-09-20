/*
 * dominant-eigen-vector.c
 *
 */

#include "dominant-eigen-vector.h"

/* Fills the vector with random double values */
void getRandomVector(double *vector, int row)
{
    double num;
    int i;
    srand(time(NULL));
    for (i = 0; i < row; i++)
    {
    	num = rand();
    	vector[i] = num;
    	/* vector[i] = 1; */
    }
}

/* Calculates the size of vector norm */
double normaOfVector(double *vector, int rows)
{
	int k;
	double sum = 0;
	for (k = 0; k < rows; k++)
	{
		sum = sum + (vector[k] * vector[k]);
	}
	sum = fabs(sqrt(sum));
	return sum;
}

/* Calculates the eigenVector */
void calculatesLastVector(double *vector1, double *vector2 , modularityMatrix *B)
{
    int i;
    int flag = 0;

    while (flag == 0) /* stops when vector1 == vector2 */
    {
         normalize(vector1, B->size);

         calcVector(B, vector1, vector2);

		 normalize(vector2, B->size);
		 /* printArrayDouble(vector2, B->size); */

		 flag = compare(vector1, vector2, B->size);

		 for(i = 0; i < B->size; i++){
            vector1[i] = vector2[i];
		 }

		 /* printArrayDouble(vector2, B->size); */
    }
}

/* Normalize vector */
void normalize(double *vector, int size)
{
	int i;
	double norma = normaOfVector(vector , size);
	for (i = 0; i < size; i++)
	{
		vector[i] = (vector[i]) / norma;
	}
}

/* Checks how similar are the vectors */
int compare(double *vector1, double *vector2, int size)
{
	int epsilon = 1; int k = 0;
	while (epsilon == 1 && k < size)
	{
	    epsilon = epsilonSize(vector1[k] , vector2[k]);
	    /* printf("epsilon is: %d \n" , epsilon); */
	    k++;
	}

    if (epsilon == 1)
    {
        return 1;
    }
    return 0;
}

/* Calculates the epsilon between two vectors */
int epsilonSize(double x , double y){
    if (fabs(x-y) < 0.00001)
    	return 1; /* good difference */
    else
        return 0; /* bad difference */
}

/* Manages the sub-functions */
void computeDominantEigenVector(modularityMatrix *B, double *vector)
{
    double *vectorStart;
    vectorStart = allocateArrayDouble(B->size);

    getRandomVector(vectorStart, B->size);
    calculatesLastVector(vectorStart, vector , B);

    /* free the allocated memory*/
    free(vectorStart);
}

/* Multiplies the vector with the modularity matrix */
void calcVector(modularityMatrix* B, double* vector1, double* vector2)
{
    int i;
    double kSum = 0;
    int n;

    n = B->size;

    for (i = 0; i < n; i++)
    {
        vector2[i] = 0;
        kSum += (B->k[i]) * vector1[i];
    }

    multCalc(B->sp, vector1, vector2);

    for (i = 0; i < n; i++)
    {
        vector2[i] -= ((double) (B->k[i] * kSum) / B->M) ;
    }

    for (i = 0; i < n; i++)
    {
        vector2[i] += (B->norm) * vector1[i];
        vector2[i] -= (B->f)[i] * vector1[i];
    }
}
