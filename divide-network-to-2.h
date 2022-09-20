
 /**
 * divide-network-to-2 Summary:
 *
 * A class that represents the operations to divide the whole network from the graph to 2 groups.
 *
 * divideNetworkTwoGroups   - Computes the division of the network to 2 groups
 * loadModularityMatrix     - Loads the matrix B from the input file path
 * divideTwoGroups          - Performs the division of a group to 2 groups
 * computeModularityMatrix  - Computes the modularity matrix for the network/group
 * compute_S                - Computes the vector S based on the eigenVector
 *
 */

#ifndef DIVIDE_NETWORK_TO_2_H_
#define DIVIDE_NETWORK_TO_2_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "allocate.h"
#include "basic-print.h"
#include "mathematical-part.h"
#include "modularityMatrix.h"
#include "Division.h"
#include "modularity-maximization.h"

/**
 * On success, this function manages the other functions that gives it the data to create the division.
 * If an error occurs in the sub functions in opening the file or the graph is empty,
 * then the function prints an error message and exit from the program.
 *
 * @param path - the path of the input file
 * return a division of the network to 2 groups
 *
 */

Division *divideNetworkTwoGroups(char* path);

/**
 * This function computes the division of the network to 2 groups.
 *
 * @param B - modularity matrix
 * return a division of the network to 2 groups
 *
 */

Division *divideTwoGroups(modularityMatrix *B);

/**
 * This function loads the matrix from the file using computeModularityMatrix.
 *
 * @param path - path to the input file
 * return modularity matrix
 *
 */

modularityMatrix *loadModularityMatrix(char* path);

/**
 * On success, this function makes the calculations for the modularity matrix. If an error occurs
 * in opening the file or the graph is empty, then the function prints an error message and exit from the program.
 *
 * @param file - input file
 * return modularity matrix
 *
 */

modularityMatrix *computeModularityMatrix(FILE* file);

/**
 * On success, this function computes the array that represents eigenVector divide of the groups. If an error occurs
 * in opening the file or the graph is empty, then the function prints an error message and exit from the program.
 *
 * @param u - eigenVector
 * @param n - size of eigenVector
 * return array S
 *
 */

int *compute_S(double *u, int n);

/**
 * This function makes the calculations for modularity according to the vector s group and the modularity matrix B.
 *
 * @param B - modularity matrix
 * @param s - array s represents the eigenVector
 * return integer value of modularity
 *
 */

#endif /* DIVIDE_NETWORK_TO_2_H_ */
