
/**
 * dominant-eigen-vector Summary:
 *
 * A class that represents all the operations to find the leading eigenVector according to the given modularity matrix.
 *
 * getRandomVector            - Fills the vector with random double values
 * epsilonSize                - Calculates the epsilon between two vectors
 * calculatesLastVector       - Calculates the eigenVector
 * normaOfVector              - Calculates the size of vector norm
 * normalize                  - Normalize vector
 * compare                    - Checks how similar are the vectors
 * computeDominantEigenVector - Manages the sub-functions
 * calcVector                 - Multiplies the vector with the modularity matrix
 *
 */

#ifndef DOMINANT_EIGEN_VECTOR_H_
#define DOMINANT_EIGEN_VECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "allocate.h"
#include "modularityMatrix.h"

/**
 * This function set a random double values into vector.
 *
 * @param vector - vector to set values
 * @param row - size of vector
 * return
 *
 */

void getRandomVector(double *vector, int row);

/**
 * This function calculates the epsilon between 2 double values.
 *
 * @param vector - vector to set values
 * @param row - size of vector
 * return difference between the values given
 *
 */

int epsilonSize(double x , double y);

/**
 * This main function manages the sub functions to calculate the eigenVector.
 *
 * @param vector1 - first vector
 * @param vector2 - second vector that holds the eigenVector in the end
 * @param B - modularity matrix
 * return
 *
 */

void calculatesLastVector(double *vector1, double *vector2 , modularityMatrix *B);

/**
 * This function calculates the norm of a vector by his size.
 *
 * @param vector - a given array
 * @param rows - size of a vector
 * return
 *
 */

double normaOfVector(double *vector, int rows);

/**
 * This function calculates the normalize vector using normaOfVector.
 *
 * @param vector - first vector
 * @param size - size of vector
 * return
 *
 */

void normalize(double *vector, int size);

/**
 * This function compares between 2 vectors and decides if they are similar enough using epsilonSize according to defined epsilon.
 *
 * @param vector1 - first vector
 * @param vector2 - second vector
 * @param size - size of vector
 * return result of comparison
 *
 */

int compare(double *vector1, double *vector2, int size);

/**
 * Main function - responsible to manage sub functions of the class and update the given vector to eigenVector.
 *
 * @param B - first vector
 * @param vector - second vector
 * return
 *
 */

void computeDominantEigenVector(modularityMatrix *B ,double *vector);

/**
 * This function multiplies the modularity matrix with vector1 and set the result to vector2.
 *
 * @param B - first vector
 * @param vector1 - first vector
 * @param vector2 - second vector
 * return
 *
 */

void calcVector(modularityMatrix* B, double* vector1, double* vector2);


#endif /* DOMINANT_EIGEN_VECTOR_H_ */
