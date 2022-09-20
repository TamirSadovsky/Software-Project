
 /**
 * modularityMatrix Summary:
 *
 * A class that represents a modularity matrix that holds this fields for efficient calculations.
 *
 * allocateModularityMatrix     - Allocates a modularity matrix
 * destroyModularityMatrix      - Frees a modularity matrix
 * destroyModularityMatrixWithG - Frees a modularity matrix
 * printModularityMatrix        - Prints all the fields of the modularity matrix
 *
 */

#ifndef MODULARITYMATRIX_H_
#define MODULARITYMATRIX_H_

#include "allocate.h"
#include "Vector.h"
#include "spmat.h"
#include "basic-print.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _modularityMatrix{
	spmat *sp;
	int *k; /* degrees array */
	int M; /* sum of degrees */
	double *f;
	int *g; /* given group of nodes */
	int size; /* size of g group */
	double norm;
} modularityMatrix;

/**
* This function allocates the modularity matrix.
*
* @param sp - spmat holds the adjacency matrix according to g group
* @param k - array holds the degree of each row
* @param M - sum of degrees
* @param f - sum of cols / rows
* @param g - given group of nodes
* @param norm - biggest col of absolute values
* @param size - size of g group
* return allocated modularity matrix
*
*/

modularityMatrix *allocateModularityMatrix(spmat *sp, int *k, int M, double *f, int *g, double norm, int size);

/**
* This function frees spmat, each array and the whole allocated modularityMatrix.
*
* @param B - modularity matrix to destroy
* return
*
*/

void destroyModularityMatrix(modularityMatrix *B);

/**
 * This function frees spmat, each array and the whole allocated modularityMatrix.
 *
 * @param B - modularity matrix to destroy
 * return
 *
 */
void destroyModularityMatrixWithG(modularityMatrix *B);

/**
* This function prints the modularity matrix.
*
* @param B - modularity matrix to print
* return
*
*/

void printModularityMatrix(modularityMatrix *B);

#endif /* MODULARITYMATRIX_H_ */
