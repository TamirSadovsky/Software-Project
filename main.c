/*
 * main.c
 */
typedef int make_iso_compilers_happy;


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "divide-network.h"



/* function declaration */

int main(int argc, char* argv[])
{
	modularityMatrix *B;

	if (argc != 3)
	{
		printf("wrong amount of parameters\n");
		exit(1);
	}

	B = loadModularityMatrix(argv[1]);
	divideNetworkGroups(argv[2], B);
	destroyModularityMatrixWithG(B);

	/* printf("%d %s\n", argc, argv[0]); */

	return 0; /* everything was OK */
}



