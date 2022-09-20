
/**
 * spmat Summary:
 *
 * A class that represents the adjacency matrix of the modularity matrix.
 * The first element in each row is artificial.
 *
 * allocateSpmat                  - Allocates a division according to a size
 * addRow                         - Adds a row to spmat
 * freeSpmat                      - Frees a spmat struct including splists and spnodes
 * multCalc                       - Multiplies spmat with a vector
 * computeModularitySpmat         - Calculates modularity of spmat
 * computeModularitySpmatDouble   - Calculates modularity of spmat
 * printSp                        - Prints spmat
 *
 */


#ifndef SPMAT_H_
#define SPMAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct _spnode{
    struct _spnode *next;
    int col;
} spnode;

typedef struct _splist{

    struct _spnode** list;

} splist;

typedef struct _spmat {
	/* Matrix size (n*n) */
	int	n;
	splist *spl;
} spmat;


/**
 * On success, this function allocates a new linked-lists sparse matrix of size n .
 * If an error occurs in allocating memory, then the function prints an error message and exit from the program.
 *
 * @param n - spmat size
 * @param g - second array
 * @param size - total size
 * return allocated spmat
 *
 */

spmat* allocateSpmat(int n);

/**
 * This function adds row i the matrix. Called before any other call,
 * exactly n times in order (i = 0 to n-1).
 *
 * @param A - spmat
 * @param row - values to insert
 * @param i - index of row to add
 * @param sizeRow - size of row to add
 * return
 *
 */

void addRow(struct _spmat *A, int *row, int i, int sizeRow);

/**
 * This function frees all resources used by A.
 *
 * @param A - spmat
 * return
 *
 */

void freeSpmat(struct _spmat *A);

/**
 * This function multiplies matrix A by vector v, into result (result is pre-allocated).
 *
 * @param A - spmat
 * @param v - vector to multiply
 * @param result - result of multiply
 * return
 *
 */

void multCalc(const struct _spmat *A, double *v, double *result);

/**
 * This function calculates the modularity of a given spmat.
 *
 * @param A - spmat
 * @param s - the vector to multiply
 * return
 *
 */

double computeModularitySpmat(struct _spmat *A, int *s);

/**
 * This function calculates the modularity of a given spmat.
 *
 * @param A - spmat
 * @param v - vector to multiply
 * return
 *
 */

double computeModularitySpmatDouble(struct _spmat *A, double *v);

/**
 * This function prints all the fields of spmat
 *
 * @param A - spmat
 * return
 *
 */

void printSp(struct _spmat *A);

#endif /* SPMAT_H_ */
