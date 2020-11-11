#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

int main () {
    int sem1_2 = sem_create(12, 0);
    int sem1_3 = sem_create(13, 0);
    int sem2_1 = sem_create(21, 0);
    int sem2_3 = sem_create(23, 0);
    int sem3_1 = sem_create(31, 0);
    int sem3_2 = sem_create(32, 0);
    sem_delete(sem1_2);
    sem_delete(sem1_3);
    sem_delete(sem2_1);
    sem_delete(sem2_3);
    sem_delete(sem3_1);
    sem_delete(sem3_2);
}