/**
 * Vector Summary:
 *
 * A class that represents a struct of array and a size.
 *
 * allocateVector    - Allocates a vector according to a size
 * destroyVector     - Frees a vector
 * printVector       - Prints the vector
 *
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "allocate.h"
#include "basic-print.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _Vector{
	int *array;
	int size;
} Vector;

/**
 * On success, this function allocates a new  vector of size n .
 * If an error occurs in allocating memory, then the function prints an error message and exit from the program.
 *
 * @param size - size of the vector
 * return
 *
 */


Vector *allocateVector(int size);

/**
 * This function frees the array and the whole allocated vector.
 *
 * @param v - vector to destroy
 * return
 *
 */

void destroyVector(Vector *v);

/**
 * This function prints the vector.
 *
 * @param v - vector to print
 * return
 *
 */

void printVector(Vector *v);

#endif /* VECTOR_H_ */
