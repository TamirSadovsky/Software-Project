
/**
 * mathematical-part Summary:
 *
 * A class that represents some of the mathematical calculations.
 *
 * getEigenPair             - Computes the leading eigenPair
 * getEigenValue            - Computes the eigenValue
 * Abs                      - Get absolute of value
 * computeModularity        - Computes the modularity to integer
 * computeModularityDouble  - Computes the modularity to double
 * dotProduct               - Multiplies two arrays to integer result
 * dotProductDouble         - Multiplies two arrays to double result
 *
 */

#ifndef MATHEMATICAL_PART_H_
#define MATHEMATICAL_PART_H_

#include "allocate.h"
#include "eigenPair.h"
#include "dominant-eigen-vector.h"
#include "modularityMatrix.h"
#include "basic-print.h"
/* #include "divide-network-to-2.h" */

/**
* This function computes the leading eigenPair of the given modularity matrix.
*
* @param B - modularity matrix
* return eigenPair
*
*/

eigenPair *getEigenPair(modularityMatrix *B);

/**
* This function computes the eigenValue from the initial modularity matrix and the final eigenVector.
*
* @param B - modularity matrix
* @param vector - eigenVector
* return eigenValue
*
*/

double getEigenValue(modularityMatrix *B, double *vector);

/**
* This function returns an absolute value.
*
* @param value - double value
* return an absolute value
*
*/

double Abs(double value);

/**
 * This function makes the calculations for the modularity respectively to the s group.
 *
 * @param B - modularity matrix
 * @param s - int array s represents the eigenVector
 * return double value of modularity
 *
 */

double computeModularity(modularityMatrix *B, int *s);

/**
 * This function makes the calculations for the modularity respectively to the s group.
 *
 * @param B - modularity matrix
 * @param s - double array s represents the eigenVector
 * return double value of modularity
 *
 */

double computeModularityDouble(modularityMatrix *B, double *v);

/**
 * This function multiples two arrays.
 *
 * @param a - first array
 * @param b - second array
 * @param size - size of array
 * return integer value of modularity
 *
 */

int dotProduct(int *a, int *b, int size);

/**
 * This function multiplies two arrays.
 *
 * @param a - first array
 * @param b - second array
 * @param size - size of array
 * return double value of modularity
 *
 */

double dotProductDouble(int *a, double *b, int size);

#endif /* MATHEMATICAL_PART_H_ */
