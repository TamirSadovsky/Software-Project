/*
 * modularity-maximization.c
 *
 */

#include "modularity-maximization.h"

#define IS_NEGATIVE(X) ((X) < (-0.0001))

/* Performs the modularity maximization on the modularity matrix and division represented by the s vector */
void modularityMaximization(modularityMatrix *Bghat, int *s)
{
	int i; int j; int d;
	double deltaQ = -1;
	int *indices = allocateArrayInt(Bghat->size);
	double *improve = allocateArrayDouble(Bghat->size);
	double *score = allocateArrayDouble(Bghat->size);

	while (IS_NEGATIVE(deltaQ))
	{
		for (i = 0; i < Bghat->size; i++)
		{
			if (i == 0)
			{
				computeScore(Bghat, s, score);
			}

			j = getMaxValueIndex(score, Bghat->size);
			s[j] = s[j] * (-1);
			indices[i] = j;

			if (i == 0)
				improve[i] = score[j];
			else
				improve[i] = improve[i-1] + score[j];

			updateScore(Bghat, s, score, j);
		}

		d = getMaxValueIndex(improve, Bghat->size);

		for (i = (Bghat->size - 1); i > d; i--)
		{
			j = indices[i];
			s[j] = s[j] * (-1);
		}

		if (d == (Bghat->size - 1))
			deltaQ = 0.0;
		else
			deltaQ = improve[d];
	}

	free(indices);
	free(improve);
	free(score);
}

/* Gets the index in the array with the max value */
int getMaxValueIndex(double *score, int size)
{
	int i; double max; int index;
	if (size == 0)
	{
		printf("error occurred\n");
		exit(1);
	}

	 max = score[0]; index = 0;

	for (i = 0; i < size; i++)
	{
		if (score[i] > max)
		{
			max = score[i];
			index = i;
		}
	}

	return index;
}

/* Computes the score vector for the first iteration */
void computeScore(modularityMatrix *Bg, int *s, double *score)
{
    int i;
    double kSum = 0;
    int ng = Bg->size;
    double *x = allocateArrayDouble(ng);
    double *temp = allocateArrayDouble(ng);

    for (i = 0; i < Bg->size; i++)
    {
    	temp[i] = (double) s[i];
    }


    for (i = 0; i < ng; i++)
    {
        kSum += (Bg->k[i]) * s[i];
    }

    multCalc(Bg->sp, temp, x);
    free(temp);

    for (i = 0; i < ng; i++)
    {
        x[i] -= ((double) (Bg->k[i] * kSum) / Bg->M) ;
    }

    /* x is computed */

    for (i = 0; i < ng; i++)
    {
    	score[i] = -2 * (s[i]*x[i] + ((double)(Bg->k[i])*(Bg->k[i])) / (Bg->M));
    }
    free(x);
}

/* Updates the score for all of the iterations except for the first one */
void updateScore(modularityMatrix *Bg, int *s, double *score, int j)
{
	int i; spnode *temp; double element;

	for (i = 0; i < Bg->size; i++)
	{
		temp = Bg->sp->spl->list[i]->next;;

		if (i == j)
			score[i] = score[i] * (-1);
		else
		{
			element = (double) (Bg->k[i] * Bg->k[j]) / Bg->M;
			while (temp != NULL && temp->col < j)
			{
				temp = temp->next;
			}
			if (temp != NULL)
			{
				if (temp->col == j)
					element += 1;
			}
			score[i] -= 4 * s[i] * s[j] * element;
		}
	}
	/* assert(1==0); */
}


