#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

int main () {
    int sem1 = sem_create(123456, 0);
    printf("P2 : T1\n");
    P(sem1);
    printf("P2 : T2\n");
    printf("P2 : T3\n");
}