
/**
 * modularity-maximization Summary:
 *
 * A class that represents the functions needed for performing
 * a modularity maximization on the final output for the division.
 *
 * modularityMaximization    - Performs the modularity maximization on the modularity matrix and division represented by the s vector
 * getMaxValueIndex          - Gets the index in the array with the max value
 * computeScore              - Computes the score vector for the first iteration
 * updateScore               - Updates the score for all of the iterations except for the first one
 *
 */


#ifndef MODULARITY_MAXIMIZATION_H_
#define MODULARITY_MAXIMIZATION_H_

#include "allocate.h"
#include "modularityMatrix.h"
#include "mathematical-part.h"

/**
 * This function performs the modularity maximization on the
 * modularity matrix and division represented by the s vector.
 *
 * @param Bghat - modularity matrix
 * @param s - array that represents the calculated division
 * return
 *
 */

void modularityMaximization(modularityMatrix *Bghat, int *s);

/**
 * This function gets the index in the score array
 * with the max value.
 *
 * @param array - the given array
 * @param size - the size of the given array
 * return the index in improve array with the max value
 *
 */
int getMaxValueIndex(double *array, int size);

/**
 * This function computes the score for the first iteration.
 *
 * @param Bghat - modularity matrix
 * @param s - array that represents the calculated division
 * @param score - the score array we are writing to
 * return
 *
 */
void computeScore(modularityMatrix *Bg, int *s, double *score);

/**
 * This function updates the score for all of the iterations
 * except the first one.
 *
 * @param Bghat - modularity matrix
 * @param score - the score array we are writing to
 * @param j - the moved node from the score array (max value)
 * return
 *
 */
void updateScore(modularityMatrix *Bg, int *s, double *score, int j);

#endif /* MODULARITY_MAXIMIZATION_H_ */
