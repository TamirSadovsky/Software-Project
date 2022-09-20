/*
 * Division.c
 *
 */

#include "Division.h"

/* allocates a division */
Division *allocateDivision(int *s, int *g, int size)
{
	int i;
	int size1; int size2;
	int j = 0; int k = 0;

	Division *div = malloc(sizeof(Division));
	if (div == NULL)
	{
		printf("couldn't allocate memory");
		exit(1);
	}

	size1 = 0; size2 = 0;
	for (i = 0; i < size; i++)
	{
		if (s[i] == 1)
			size1++;
		else
			size2++;
	}

	div->group1 = allocateArrayInt(size1);
	div->group2 = allocateArrayInt(size2);
	div->size1 = size1;
	div->size2 = size2;

	for (i = 0; i < size; i++)
	{
		if (s[i] == 1)
		{
			(div->group1)[j] = g[i];
			j++;
		}
		else
		{
			(div->group2)[k] = g[i];
			k++;
		}
	}

	return div;
}

/* frees a division */
void destroyDivision(Division *div)
{
	free(div->group1);
	free(div->group2);
	free(div);
}

/* prints a division */
void printDivision(Division *div)
{
	printf("group 1: ");
	printArrayInt(div->group1, div->size1);
	printf("group 2: ");
	printArrayInt(div->group2, div->size2);
}



