#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

int main () {
    int sem1_2 = sem_create(12, 0);
    int sem1_3 = sem_create(13, 0);
    int sem2_1 = sem_create(21, 0);
    int sem3_1 = sem_create(31, 0);
    printf("P1 : T1\n");
    printf("P1 : T2\n");
    printf("P1 : T3\n");
    V(sem1_2);
    V(sem1_3);
    P(sem2_1);
    P(sem3_1);
    printf("P1 : RENDEZ-VOUS\n");
}