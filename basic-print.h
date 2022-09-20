
/**
 * basic-print Summary:
 *
 * A class that represents the basic print functions for testing the correctness of the code
 *
 * printMatrix      - Prints a matrix
 * printArrayInt    - Prints an array of integers
 * printArrayDouble - Prints an array of doubles
 *
 */

#ifndef BASIC_PRINT_H_
#define BASIC_PRINT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * This function prints the values of a matrix.
 *
 * @param matrix - a matrix of doubles to print
 * @param rows - number of rows to print
 * @param cols - number of cols to print
 * return
 *
 */

void printMatrix(double **matrix, int rows, int cols);

/**
 * This function prints the values of an array of integers.
 *
 * @param arr - an array of integers to print
 * @param n - size of row to print
 * return
 *
 */

void printArrayInt(int *arr, int n);

/**
 * This function prints the values of an array of doubles.
 *
 * @param arr - an array of doubles to print
 * @param n - size of row to print
 * return
 *
 */

void printArrayDouble(double *arr, int n);


#endif /* BASIC_PRINT_H_ */
