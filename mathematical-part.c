/*
 * mathematical-part.c
 *
 */

#include "mathematical-part.h"

#define IS_POSITIVE(X) ((X) > 0.0001)

/* compute the leading eigenPair of the matrix B */
eigenPair *getEigenPair(modularityMatrix *B)
{
	eigenPair *pair = allocateEigenPair(B->size);
	/* printMatrix(A, n, n); */

	computeDominantEigenVector(B, pair->eigenVector);
	pair->eigenValue = getEigenValue(B, pair->eigenVector);

	return pair;
}

/* Computes the eigenValue */
double getEigenValue(modularityMatrix *B, double *vector)
{
	return computeModularityDouble(B, vector);
}

/* Get absolute of value */
double Abs(double value)
{
	if (value >= 0)
		return value;
	return -value;
}

/* Computes the modularity to integer */
double computeModularity(modularityMatrix *B, int *s)
{
    double sum = 0;

    sum = computeModularitySpmat(B->sp, s);
    sum -= dotProduct(B->k, s, B->size) * dotProduct(B->k, s, B->size) / B->M;

    return 0.5*sum;
}

/* Multiplies two arrays to integer result */
int dotProduct(int *a, int *b, int size)
{
	int i; int sum = 0;
	for (i = 0; i < size; i++)
	{
		sum += a[i] * b[i];
	}
	return sum;
}

/* Computes the modularity to double */
double computeModularityDouble(modularityMatrix *B, double *v)
{
	double sum = 0;

	sum = computeModularitySpmatDouble(B->sp, v);
	sum -= dotProductDouble(B->k, v, B->size) * dotProductDouble(B->k, v, B->size) / B->M;

	return 0.5*sum;
}

/* Multiplies two arrays to double result */
double dotProductDouble(int *a, double *b, int size)
{
	int i; double sum = 0;
	for (i = 0; i < size; i++)
	{
		sum += a[i] * b[i];
	}
	return sum;
}


