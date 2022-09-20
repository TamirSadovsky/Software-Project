/*
 * basic-print.c
 *
 */

#include "basic-print.h"

/* Prints a matrix */
void printMatrix(double **matrix, int rows, int cols)
{
    int row; int col;
    printf("printing matrix:\n");
    for (row = 0; row < rows; row++)
    {
    	for (col = 0; col < cols; col++)
    	{
    		printf("%f ", matrix[row][col]);
    	}
    	printf("\n");
    }
    printf("\n");
}

/* prints an array of integers */
void printArrayInt(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/* prints an array of doubles */
void printArrayDouble(double *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%f ", arr[i]);
	}
	printf("\n");
}
