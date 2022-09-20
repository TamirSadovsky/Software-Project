/*
 * divisionArray.c
 *
 */

#include "divisionArray.h"

/* Allocates a division according to a size */
divisionArray *allocateDivisionArray(int size)
{
	divisionArray *divArray = malloc(sizeof(divisionArray));
	if (divArray == NULL)
	{
		printf("couldn't allocate memory");
		exit(1);
	}

	divArray->array = allocateArrayInt(size);
	divArray->size = size;
	divArray->max = 0;
	divArray->min = 0;

	return divArray;
}

/* Frees a division array */
void destroyDivisionArray(divisionArray *divArray)
{
	free(divArray->array);
	free(divArray);
}

/* Checks if the array is empty */
bool isEmpty(divisionArray *divArray)
{
    int i;
    for(i = 0; i < divArray->size; i++)
    {
        if (divArray->array[i] != -1)
            return false;
    }
    return true;
}

/* Gives the next group to divide */
Vector *getNextG(divisionArray *divArray)
{
	int i; int j = 0;
	int ng = getGroupSize(divArray, divArray->min);
	Vector *g = allocateVector(ng);

	for (i = 0; i < divArray->size; i++)
	{
		if ((divArray->array)[i] == divArray->min)
		{
			(g->array)[j] = i;
			j++;
			(divArray->array)[i] = -1;
		}
	}
	(divArray->min)++;

	return g;
}

/* Calculates the size of a group with given index */
int getGroupSize(divisionArray *divArray, int i)
{
	int j; int sum = 0;
	for (j = 0; j < divArray->size; j++)
	{
		if (divArray->array[j] == i)
			sum++;
	}
	return sum;
}

/* Adds a group to the division array */
void addGroup(divisionArray *divArray, int *g, int ng)
{
	 int i;
	 if (ng == 0)
		 return;
	 divArray->max++;

	 for (i = 0; i < ng; i++)
	 {
		 divArray->array[g[i]] = divArray->max;
	 }
}
