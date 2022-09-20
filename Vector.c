/*
 * Vector.c
 *
 */

#include "Vector.h"

/* Allocates a vector according to a size */
Vector *allocateVector(int size)
{
	Vector *vector = malloc(sizeof(Vector));
	if (vector == NULL)
	{
		printf("couldn't allocate memory for vector");
		exit(1);
	}
	vector->array = allocateArrayInt(size);
	vector->size = size;
	return vector;
}

/* Frees a vector */
void destroyVector(Vector *vector)
{
	free(vector->array);
	free(vector);
}

/* Prints the vector */
void printVector(Vector *vector)
{
	printArrayInt(vector->array, vector->size);
}
