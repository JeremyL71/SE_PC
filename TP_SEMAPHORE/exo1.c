#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define CLE 123
int main(){
    int semid;

    /* Création de 4 sémaphore */
    if ( (semid = semget( (key_t)CLE, 4, IPC_CREAT | IPC_EXCL | 0666)) == -1){
        perror("Echec de semget");
        exit(1);
    }
    printf("le semid de l'emsemble de semaphoreest :%d\n", semid);
    printf(" cet ensemble est identifie par la cle unique : %d\n" , (key_t)CLE) ;
    return 0;
}