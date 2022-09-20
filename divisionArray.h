
/**
 * divisionArray Summary:
 *
 * A class that represents a list of groups using an array that
 * its values are the group identifiers of the nodes with the matching indices.
 *
 * allocateDivisionArray    - Allocates a division according to a size
 * destroyDivisionArray     - Frees a division array
 * isEmpty                  - Checks if the array is empty
 * getNextG                 - Gives the next group to divide
 * getGroupSize             - Calculates the size of a group with given index
 * addGroup                 - Adds a group to the division array
 *
 */

#ifndef DIVISIONARRAY_H_
#define DIVISIONARRAY_H_

#include "allocate.h"
#include "basic-print.h"
#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _divisionArray{
	int *array;
	int size;
	int max; /* maximum group identifier */
	int min; /* minimum group identifier */
} divisionArray;

/**
 * On success, this function allocates the division array.
 * If an error occurs in allocating memory, then the function prints an error message and exit from the program.
 *
 * @param size - size to allocate
 * return allocated division array
 *
 */

divisionArray *allocateDivisionArray(int size);

/**
 * This function frees the division array.
 *
 * @param divArray
 * return
 *
 */

void destroyDivisionArray(divisionArray *divArray);

/**
 * This function checks if the division array is empty.
 *
 * @param divArray - division array
 * return true if the array is empty. else return false
 *
 */

bool isEmpty(divisionArray *divArray);

/**
 * This function gets a group from the division array.
 * It chooses the group with the minimal identifier value
 * and deletes it from the division array.
 *
 * @param divArray - division array
 * return next vector to check
 *
 */

Vector *getNextG(divisionArray *divArray);

/**
 * This function computes the size of the group in
 * the division array with the given group identifier value
 *
 * @param divArray - division array
 * @param i - index of group
 * return group size of the i index
 *
 */

int getGroupSize(divisionArray *divArray, int i);

/**
 * This function adds the group g of size ng to the division array.
 *
 * @param divArray - first array
 * @param g - second array
 * @param ng - size of g
 * return
 *
 */

void addGroup(divisionArray *divArray, int *g, int ng);

#endif /* DIVISIONARRAY_H_ */
