CC=gcc
OPTIONS=-Wall -Wextra
SRC_C=./src/
SRC_O=./src/o/

# General ================================================
all:exo1 exo2

$(SRC_O)Dijkstra.o:$(SRC_C)Dijkstra.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)Dijkstra.c -o $(SRC_O)Dijkstra.o

# Exo 1 ================================================
exo1:exo1_create_sem exo1_delete_sem exo1_1 exo1_2

exo1_create_sem:$(SRC_O)exo1_create_sem.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo1_create_sem $(SRC_O)exo1_create_sem.o $(SRC_O)Dijkstra.o

exo1_delete_sem:$(SRC_O)exo1_delete_sem.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo1_delete_sem $(SRC_O)exo1_delete_sem.o $(SRC_O)Dijkstra.o

exo1_1:$(SRC_O)exo1_1.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo1_1 $(SRC_O)exo1_1.o $(SRC_O)Dijkstra.o

exo1_2:$(SRC_O)exo1_2.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo1_2 $(SRC_O)exo1_2.o $(SRC_O)Dijkstra.o

$(SRC_O)exo1_create_sem.o:$(SRC_C)exo1_create_sem.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo1_create_sem.c -o $(SRC_O)exo1_create_sem.o

$(SRC_O)exo1_delete_sem.o:$(SRC_C)exo1_delete_sem.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo1_delete_sem.c -o $(SRC_O)exo1_delete_sem.o

$(SRC_O)exo1_1.o:$(SRC_C)exo1_1.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo1_1.c -o $(SRC_O)exo1_1.o

$(SRC_O)exo1_2.o:$(SRC_C)exo1_2.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo1_2.c -o $(SRC_O)exo1_2.o

# Exo 2 ================================================
exo2:exo2_1 exo2_2 exo2_3

exo2_create_sem:$(SRC_O)exo2_create_sem.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo2_create_sem $(SRC_O)exo2_create_sem.o $(SRC_O)Dijkstra.o

exo2_delete_sem:$(SRC_O)exo2_delete_sem.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo2_delete_sem $(SRC_O)exo2_delete_sem.o $(SRC_O)Dijkstra.o

exo2_1:$(SRC_O)exo2_1.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo2_1 $(SRC_O)exo2_1.o $(SRC_O)Dijkstra.o

exo2_2:$(SRC_O)exo2_2.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo2_2 $(SRC_O)exo2_2.o $(SRC_O)Dijkstra.o

exo2_3:$(SRC_O)exo2_3.o $(SRC_O)Dijkstra.o
	$(CC) $(OPTIONS) -o exo2_3 $(SRC_O)exo2_3.o $(SRC_O)Dijkstra.o

$(SRC_O)exo2_create_sem.o:$(SRC_C)exo2_create_sem.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo2_create_sem.c -o $(SRC_O)exo2_create_sem.o

$(SRC_O)exo2_delete_sem.o:$(SRC_C)exo2_delete_sem.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo2_delete_sem.c -o $(SRC_O)exo2_delete_sem.o

$(SRC_O)exo2_1.o:$(SRC_C)exo2_1.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo2_1.c -o $(SRC_O)exo2_1.o

$(SRC_O)exo2_2.o:$(SRC_C)exo2_2.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo2_2.c -o $(SRC_O)exo2_2.o

$(SRC_O)exo2_3.o:$(SRC_C)exo2_3.c $(SRC_C)Dijkstra.h
	$(CC) $(OPTIONS) -c $(SRC_C)exo2_3.c -o $(SRC_O)exo2_3.o