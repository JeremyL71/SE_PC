#ifndef __Dijkstra__
#define __Dijkstra__

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int sem_create(key_t cle, int initval);
void P(int semid);
void V(int semid);
void sem_delete(int semid);

#endif /*__Dijkstra__*/