/*
 * allocate.c
 *
 */

#include "allocate.h"

/* allocates a matrix of the given dimensions */
double **allocateMatrix(int rows, int cols)
{
	int row; int col;
	double **matrix = malloc(sizeof(double*) * rows);

	if (matrix == NULL)
	{
		printf("couldn't allocate matrix\n");
		exit(1);
	}

	for (row = 0; row < rows; row++)
	{
		matrix[row] = malloc(sizeof(double) * cols);
		if (matrix[row] == NULL)
		{
			printf("couldn't allocate matrix\n");
			exit(1);
		}
	    for (col = 0; col < cols; col++)
	    {
	    	matrix[row][col] = 0;
	    }
	}
	return matrix;
}

/* frees a matrix of the given rows */
void freeMatrix(double **matrix, int rows)
{
	int i;
	for (i = 0; i < rows; i++)
	{
	    double* currentIntPtr = matrix[i];
	    free(currentIntPtr);
	}
	free(matrix);
}

/* allocates a vector of the given dimension */
int *allocateArrayInt(int row)
{
	int i;
    int *vector = malloc(sizeof(int*) * row);
    if (vector == NULL)
    {
    	printf("couldn't allocate vector\n");
    	exit(1);
    }

    for (i = 0; i < row; i++)
    {
    	vector[i] = 0;
    }

    return vector;
}

/* allocates a vector of the given dimension */
double *allocateArrayDouble(int row)
{
	int i;
    double *vector = malloc(sizeof(double*) * row);
    if (vector == NULL)
    {
    	printf("couldn't allocate vector\n");
    	exit(1);
    }

    for (i = 0; i < row; i++)
    {
    	vector[i] = 0;
    }

    return vector;
}
