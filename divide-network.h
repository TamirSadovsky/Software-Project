
/**
 * divide-network Summary:
 *
 * A class that represents the operations to divide the whole network from the graph to groups.
 *
 * divideNetworkGroups   - Computes the division of the network to groups
 * writeDivisionToFile   - Writes the division of the network to the output file
 *
 */

#ifndef DIVIDE_NETWORK_H_
#define DIVIDE_NETWORK_H_

#include "divide-group-to-2.h"
#include "divisionArray.h"
#include <stdbool.h>


/**
 * On success, this function manages the other functions that gives it the data to create the whole network division.
 * If an error occurs in the sub functions in opening the file or the graph is empty,
 * then the function prints an error message and exit from the program.
 *
 * @param path - the path of the input file
 * @param B - modularity matrix
 * return
 *
 */

void divideNetworkGroups(char *path, modularityMatrix *B);

/**
 * On success, this function writes the division of the network given from divideNetworkGroups to the output file. If an error occurs
 * in opening or closing the file, then the function prints an error message and exit from the program.
 *
 * @param path - path to write to file
 * @param O - represents the division to groups
 * return
 *
 */

void writeDivisionToFile(char *path, divisionArray* O);


#endif /* DIVIDE_NETWORK_H_ */
