/*
 * eigenPair.c
 *
 */

#include "eigenPair.h"

/* Allocates an eigenPair */
eigenPair *allocateEigenPair(int size)
{
	eigenPair *pair = malloc(sizeof(eigenPair));
	if (pair == NULL)
	{
		printf("couldn't allocate memory");
		exit(1);
	}
	pair->eigenVector = allocateArrayDouble(size);
	pair->size = size;
	return pair;
}

/* Frees an eigenPair */
void destroyEigenPair(eigenPair *pair)
{
	free(pair->eigenVector);
	free(pair);
}

/* Prints an eigenPair */
void printEigenPair(eigenPair *pair)
{
	printf("eigenValue: %f, size: %d\n", pair->eigenValue, pair->size);
	printf("eigenVector ");
	printArrayDouble(pair->eigenVector, pair->size);
}

