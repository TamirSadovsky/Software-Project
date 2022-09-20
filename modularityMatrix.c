/*
 * modularityMatrix.c
 *
 */

#include "modularityMatrix.h"

/* Allocates a modularity matrix */
modularityMatrix *allocateModularityMatrix(spmat *sp, int *k, int M, double *f, int *g, double norm, int size)
{
	modularityMatrix *B = malloc(sizeof(modularityMatrix));
	if (B == NULL)
	{
		printf("couldn't allocate memory");
		exit(1);
	}

	B->sp = sp;
	B->k = k;
	B->M = M;
	B->f = f;
	B->g = g;
    B->norm = norm;
	B->size = size;

	return B;
}

/* Frees a modularity matrix */
void destroyModularityMatrix(modularityMatrix *B)
{
	freeSpmat(B->sp);
	free(B->k);
	free(B->f);
	free(B);
}

/* Frees a modularity matrix */
void destroyModularityMatrixWithG(modularityMatrix *B)
{
	freeSpmat(B->sp);
	free(B->k);
	free(B->g);
	free(B->f);
	free(B);
}

/* Prints all the fields of the modularity matrix */
void printModularityMatrix(modularityMatrix *B)
{
	printf("spmat:\n");
	printSp(B->sp);
	printf("\n");

	printf("k: ");
	printArrayInt(B->k, B->size);
	printf("M: %d\n\n", B->M);

	printf("f: ");
	printArrayDouble(B->f, B->size);
	printf("g: ");
	printArrayInt(B->g, B->size);

	printf("\n");
	printf("norm: %f\n", B->norm);
	printf("size: %d\n", B->size);
	printf("\n\n");
}
