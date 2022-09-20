
/**
 * Division Summary:
 *
 * A class that represents the 2 groups of the division - the values are the indexes of the nodes.
 *
 * allocateDivision    - Allocates a division according to a size
 * destroyDivision     - Frees a division
 * printDivision       - Prints two groups of the division
 *
 */

#ifndef DIVISION_H_
#define DIVISION_H_

#include <stdio.h>
#include <stdlib.h>
#include "allocate.h"
#include "basic-print.h"

typedef struct _Division{
	int *group1;
	int *group2;
	int size1;
	int size2;
} Division;

/**
 * On success, this function allocates the 2 arrays with a size according to the given arrays.
 * If an error occurs in allocating memory, then the function prints an error message and exit from the program.
 *
 * @param s - first array
 * @param g - second array
 * @param size - total size
 * return allocated division
 *
 */

Division *allocateDivision(int* s, int *g, int size);

/**
 * This function frees the allocated fields of the division and the division itself.
 *
 * @param s - first array
 * @param g - second array
 * @param size - total size
 * return
 *
 */

void destroyDivision(Division *div);

/**
 * This function prints the division.
 *
 * @param div - division to print
 * return
 */

void printDivision(Division *div);


#endif /* DIVISION_H_ */
