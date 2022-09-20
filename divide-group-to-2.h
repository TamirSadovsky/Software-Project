
/**
 * divide-group-to-2 Summary:
 *
 * A class that represents the operations to divide a specific group of nodes from the graph to 2 groups.
 *
 * divideGroupTwoGroups            - Computes the division of the group to 2 groups
 * computeModularityMatrixHat      - Computes the new modularity matrix from the old modularity matrix
 * addSpmatSubRow                  - Adds a sub row to the new modularity matrix
 *
 */

#ifndef DIVIDE_GROUP_TO_2_H_
#define DIVIDE_GROUP_TO_2_H_

#include "divide-network-to-2.h"

/**
 * This function manages other functions that gives the data to create the division.
 *
 * @param B - old modularity matrix
 * @param g - the group of nodes from the graph to divide
 * @param ng - size of group g
 * return a division of the group
 *
 */

Division *divideGroupTwoGroups(modularityMatrix *B, int *g, int ng);

/**
 * On success, this function makes the calculations for the new modularity matrix respectively to the g group.
 * If the there are no edges in the graph, then the function prints an error message and exit from the program.
 *
 * @param B - old modularity matrix
 * @param g - the group of nodes from the graph to divide
 * @param ng - size of group g
 * return new modularity matrix
 *
 */

modularityMatrix *computeModularityMatrixHat(modularityMatrix *B, int* g, int ng);

/**
 * This function adds a row to sub spmat with the proper values from g group.
 *
 * @param B - old modularity matrix
 * @param sp - sp matrix
 * @param i - the row index
 * @param g - the group of nodes from the graph to divide
 * @param ng - size of group g
 * @param vectorToAdd - where we hold the values
 * return
 *
 */

void addSpmatSubRow(modularityMatrix* B, spmat* sp, int i, int* g , int ng, int* vectorToAdd);


#endif /* DIVIDE_GROUP_TO_2_H_ */
