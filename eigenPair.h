
/**
 * eigenPair Summary:
 *
 * A class that represents the struct that holds the eigenVector and eigenValue.
 *
 * allocateEigenPair         - Allocates an eigenPair
 * destroyEigenPair          - Frees an eigenPair
 * printEigenPair            - Prints an eigenPair
 *
 */

#ifndef EIGENPAIR_H_
#define EIGENPAIR_H_


#include "allocate.h"
#include "basic-print.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _eigenPair{
	double eigenValue;
	int size;
	double *eigenVector;
} eigenPair;

/**
 * On success, this function allocates the eigenPair.
 * If an error occurs in allocating memory, then the function prints an error message and exit from the program.
 *
 * @param size - size of eigenPair to allocate
 * return allocated eigenPair
 *
 */

eigenPair *allocateEigenPair(int size);

/**
 * This function frees an eigenPair.
 *
 * @param pair - eigenPair to free
 * return
 *
 */

void destroyEigenPair(eigenPair *pair);

/**
 * This function prints an eigenPair.
 *
 * @param pair - eigenPair to print
 * return
 *
 */

void printEigenPair(eigenPair *pair);

#endif /* EIGENPAIR_H_ */
