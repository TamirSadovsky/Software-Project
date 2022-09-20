FLAGS = -ansi -Wall -Wextra -Werror -pedantic-errors
LIBS = -lm
FILES_O = allocate.o basic-print.o divide-group-to-2.o divide-network-to-2.o divide-network.o Division.o divisionArray.o dominant-eigen-vector.o eigenPair.o mathematical-part.o modularity-maximization.o modularityMatrix.o spmat.o Vector.o

all: main.o $(FILES_O)
	gcc main.o $(FILES_O) -o cluster $(LIBS)

clean:
	rm -rf *.o cluster


main.o: main.c divide-network.o
	gcc $(FLAGS) -c main.c

allocate.o: allocate.c allocate.h
	gcc $(FLAGS) -c allocate.c

basic-print.o: basic-print.c basic-print.h
	gcc $(FLAGS) -c basic-print.c

divide-group-to-2.o: divide-group-to-2.c divide-group-to-2.h divide-network-to-2.o
	gcc $(FLAGS) -c divide-group-to-2.c

divide-network.o: divide-network.c divide-network.h divide-group-to-2.o divisionArray.o
	gcc $(FLAGS) -c divide-network.c

divide-network-to-2.o: divide-network-to-2.c divide-network-to-2.h allocate.o basic-print.o mathematical-part.o modularityMatrix.o Division.o modularity-maximization.o
	gcc $(FLAGS) -c divide-network-to-2.c

Division.o: Division.c Division.h allocate.h basic-print.o
	gcc $(FLAGS) -c Division.c

divisionArray.o: divisionArray.c divisionArray.h allocate.o basic-print.o Vector.o
	gcc $(FLAGS) -c divisionArray.c

dominant-eigen-vector.o: dominant-eigen-vector.c dominant-eigen-vector.h allocate.o modularityMatrix.o
	gcc $(FLAGS) -c dominant-eigen-vector.c

eigenPair.o: eigenPair.c eigenPair.h allocate.o basic-print.o
	gcc $(FLAGS) -c eigenPair.c

mathematical-part.o: mathematical-part.c mathematical-part.h allocate.o eigenPair.o dominant-eigen-vector.o modularityMatrix.o basic-print.o
	gcc $(FLAGS) -c mathematical-part.c

modularityMatrix.o: modularityMatrix.c modularityMatrix.h allocate.o Vector.h spmat.o basic-print.o
	gcc $(FLAGS) -c modularityMatrix.c

modularity-maximization.o: modularity-maximization.c modularity-maximization.h allocate.o modularityMatrix.o mathematical-part.o
	gcc $(FLAGS) -c modularity-maximization.c

spmat.o: spmat.c spmat.h 
	gcc $(FLAGS) -c spmat.c

Vector.o: Vector.c Vector.h allocate.o basic-print.o
	gcc $(FLAGS) -c Vector.c
