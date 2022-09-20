
/**
 * allocate Summary:
 *
 * A class that represents the allocation functions.
 *
 * allocateMatrix       - Allocates a matrix of doubles of the given dimensions
 * freeMatrix           - Frees a matrix of doubles of the given dimensions
 * allocateArrayInt     - Allocates an array of integers of the given dimension
 * allocateArrayDouble  - Allocates an array of doubles of the given dimension
 *
 */

#ifndef ALLOCATE_H_
#define ALLOCATE_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * On success, the function allocates a matrix of doubles. If an error occurs, then the
 * function prints an error message and exit from the program.
 *
 * @param rows - number of rows to allocate
 * @param cols - number of cols to allocate
 * return an allocated matrix of doubles
 *
 */

double **allocateMatrix(int rows, int cols);

/**
 * The function frees the allocated matrix, it frees each row.
 *
 * @param matrix - the matrix that needs to be freed
 * @param rows - number of rows to allocate
 * return
 *
 */

void freeMatrix(double **matrix, int rows);

/**
 * On success, the function allocates an array of integers. If an error occurs, then the
 * function prints an error message and exit from the program.
 *
 * @param row - size of array to allocate
 * return an allocated array of integers
 *
 */
int *allocateArrayInt(int row);

/**
 * On success, the function allocates an array of doubles. If an error occurs, then the
 * function prints an error message and exit from the program.
 *
 * @param row - size of array to allocate
 * return an allocated array of doubles
 *
 */

double *allocateArrayDouble(int row);

#endif /* ALLOCATE_H_ */
