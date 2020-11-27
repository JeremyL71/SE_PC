#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

int main () {
    int sem1_2 = sem_create(12, 0);
    int sem2_1 = sem_create(21, 0);
    int sem2_3 = sem_create(23, 0);
    int sem3_2 = sem_create(32, 0);
    printf("P2 : T1\n");
    printf("P2 : T2\n");
    printf("P2 : T3\n");
    V(sem2_1);
    V(sem2_3);
    P(sem1_2);
    P(sem3_2);
    printf("P2 : RENDEZ-VOUS\n");
}