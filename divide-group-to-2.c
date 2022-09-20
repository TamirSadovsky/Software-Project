/*
 * divide-group-to-2.c
 *
 */

#include "divide-group-to-2.h"

/* Computes the division of the group to 2 groups */
Division *divideGroupTwoGroups(modularityMatrix *B, int *g, int ng)
{
	modularityMatrix *Bghat = computeModularityMatrixHat(B, g , ng);
	/* printModularityMatrix(Bghat); */
	Division *div = divideTwoGroups(Bghat);
	destroyModularityMatrix(Bghat);
	return div;

}

/* Computes the new modularity matrix from the old modularity matrix */
modularityMatrix *computeModularityMatrixHat(modularityMatrix* B,  int* g, int ng)
{
	modularityMatrix *Bghat;
    int i; int j; int M;
    double norm; double max; double value;
    double rowSumAbs;
    double kSum;
    int* vectorToAdd;
    int* k; double* f;
    spmat *spm; spnode *temp;

    M = 0; norm = 0;
    max = 0; j = 0;
    kSum = 0;
    vectorToAdd = allocateArrayInt(ng); /* holds the row to insert in sub spmat each iteration */
    spm = allocateSpmat(ng); /* sub spmat to hold new adjacency matrix  */
    f = allocateArrayDouble(ng);
    k = allocateArrayInt(ng);

    for (i = 0; i < ng; i++)
    {
    	k[i] = (B->k)[g[i]];
    	kSum += k[i];
    }
    M = B->M;


    for (i = 0; i < ng; i++)
    {
    	addSpmatSubRow(B, spm, i, g , ng, vectorToAdd); /* adds a row to sub spmat  */

    	j = 0; temp = spm->spl->list[i]->next;
    	value = 0;
    	while (temp != NULL)
    	{
    		vectorToAdd[j] = temp->col;
    		value += (2 * (double) (k[i] * B->k[temp->col]) / M); /* computes the unnecessary part for the rowSumAbs */
    		temp = temp->next;
    		j++;
    	}

    	f[i] = j - (double) (k[i] * kSum) / M;
    	rowSumAbs = j  + (double) (k[i] * kSum) / M - value + f[i];

    	if (rowSumAbs > max)
    	{
    		max = rowSumAbs;
    		norm = max;
    	}
    }

    free(vectorToAdd);
    if (M == 0)
	{
		printf("empty graph\n");
		exit(1);
	}

    Bghat = allocateModularityMatrix(spm, k, M, f, g, norm, ng);
    return Bghat;
}

/* Adds a sub row to the new modularity matrix */
void addSpmatSubRow(modularityMatrix* B, spmat* sp, int i, int* g, int ng, int* vectorToAdd)
{
    int rowToAddInGArray; /* actual row from g array */
    int gIndicator; /* elements inserted  */
    int j;
    spnode *temp;
    splist* spl = B->sp->spl;

    gIndicator = 0; /* the amount of elements in the adjacency matrix for B[g] */
    rowToAddInGArray = g[i];

	temp = spl->list[rowToAddInGArray]->next; /* first node of big spmat */

    while(temp != NULL)
    {
    	for (j = 0; j < ng; j++)
    	{
    		if (temp->col == g[j]) /* find out if temp->col is in g */
    		{
    			vectorToAdd[gIndicator] = j;
    			gIndicator++;
    		}
    	}
        temp = temp->next;
    }
    addRow(sp, vectorToAdd, i, gIndicator); /* add sub row to sp */
}
