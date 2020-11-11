#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

int main () {
    int sem1 = sem_create(123456, 0);
    printf("P1 : T1\n");
    printf("P1 : T2\n");
    V(sem1);
    printf("P1 : T3\n");
    printf("P1 : T4\n");
}