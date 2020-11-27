#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

int main () {
    int sem1_3 = sem_create(13, 0);
    int sem2_3 = sem_create(23, 0);
    int sem3_1 = sem_create(31, 0);
    int sem3_2 = sem_create(32, 0);
    printf("P3 : T1\n");
    printf("P3 : T2\n");
    printf("P3 : T3\n");
    V(sem3_1);
    V(sem3_2);
    P(sem1_3);
    P(sem2_3);
    printf("P3 : RENDEZ-VOUS\n");
}