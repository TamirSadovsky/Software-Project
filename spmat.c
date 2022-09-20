/*
 * spmat.c
 *
 */

#include "spmat.h"

/* Adds a row to spmat */
void addRow(struct _spmat *A, int *row, int i, int sizeRow)
{
	int j;
	spnode *temp1, *temp2;
	splist* spl = A->spl;

    for (j = 0; j < sizeRow; j++)
    {
        	temp1 = malloc(sizeof(spnode));
        	if(temp1 == NULL)
            {
                printf("couldn't allocate memory");
                exit(1);
            }

        	temp1->col = row[j];
        	temp1->next = NULL;

            temp2 = spl->list[i];
            while(temp2->next != NULL)
                temp2 = temp2->next;
            temp2->next = temp1;
    }
}

/* Multiplies spmat with a vector */
void multCalc(const struct _spmat *A, double *v, double *result)
{
	int i;
	splist* spl = A->spl;
	spnode *temp;
	double sum;

	for (i = 0; i < A->n; i++)
	{
		sum = 0;
	    temp = spl->list[i]->next; /* the first value in each row isn't used */

	    while (temp != NULL)
	    {
	    	sum += v[temp->col];
	    	temp = temp->next;
	    }

	    result[i] = sum;
	}
}

/* Calculates modularity of spmat */
double computeModularitySpmat(struct _spmat *A, int *s)
{
	int i;
	splist* spl = A->spl;
	spnode *temp;
	double sumRow;
	double sum = 0;

	for (i = 0; i < A->n; i++)
	{
		sumRow = 0;
		temp = spl->list[i]->next; /* the first value in each row isn't used */

		while (temp != NULL)
		{
			sumRow += s[temp->col];
		    temp = temp->next;
		}

		sum += sumRow * s[i];
	}
	return sum;
}

/* Calculates modularity of spmat */
double computeModularitySpmatDouble(struct _spmat *A, double *s)
{
	int i;
	splist* spl = A->spl;
	spnode *temp;
	double sumRow;
	double sum = 0;

	for (i = 0; i < A->n; i++)
	{
		sumRow = 0;
		temp = spl->list[i]->next; /* the first value in each row isn't used */

		while (temp != NULL)
		{
			sumRow += s[temp->col];
		    temp = temp->next;
		}

		sum += sumRow * s[i];
	}
	return sum;
}

/* Allocates a division according to a size */
spmat* allocateSpmat(int n)
{
    spmat* spm;
    splist* spl;
    int i;
    spm = malloc(sizeof(spmat));
    if(spm == NULL)
    {
		printf("couldn't allocate memory");
		exit(1);
	}
    spl = malloc(sizeof(splist));
	 if(spl == NULL)
    {
		printf("couldn't allocate memory");
		exit(1);
	}

    spm->n = n; /* the dimensions of the matrix is a given value */

    spl->list = malloc(sizeof(spnode*) * n);
    if(spl->list == NULL)
    {
		printf("couldn't allocate memory");
		exit(1);
	}

    for (i = 0; i < n; i++)
    {
    	spl->list[i] = malloc(sizeof(spnode));
        if(spl->list[i] == NULL)
        {
            printf("couldn't allocate memory");
            exit(1);
        }
    	spl->list[i]->col = -1;
    	spl->list[i]->next = NULL;
    }

    spm->spl = spl;

	return spm;
}

/* Frees a spmat struct including splists and spnodes */
void freeSpmat(struct _spmat *A)
{
    int i;
    spnode *temp1, *temp2;
	splist* spl = A->spl;
	for(i = 0; i < A->n; i++)
    {
        temp1 = spl->list[i];
        while (temp1 != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            free(temp2);
        }
	}

	free(spl->list);
	free(spl);
	free(A);
}

/* Prints spmat */
void printSp(struct _spmat *A)
{
	int i;
	splist *spl = A->spl;
	spnode* temp;

	printf("list:\n");

	for (i = 0; i < A->n; i++)
	{
		printf("row %d: ", i);
		temp = spl->list[i]->next;
		while (temp != NULL)
		{
			printf("%d ", temp->col);
			temp = temp->next;
		}
		printf("\n");
	}
	printf("\n");
}

