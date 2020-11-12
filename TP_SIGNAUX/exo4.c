#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h>
#include <signal.h>

int main() {
    int retourFork = fork();

    if (retourFork > 0) {
        printf("\nJe suis le père");
        int compte_a_rebours = 3;
        while(compte_a_rebours!=0) {
            printf("\n[PERE]: Fin dans %d\n", compte_a_rebours);
            compte_a_rebours--;
            sleep(1); 
        }
        printf("\n[PERE]: Envoi du signal au fils\n");
        kill(retourFork, SIGKILL);
        printf("\n[PERE] Adieu\n");
        return(0);
    }
    if (retourFork == 0) {
        printf("Et moi luke");
        while(1) {
            printf("\n[FILS]: Je tourne en boucle ! :D\n");
            sleep(1);
        }
    }
    if (retourFork < 0) {
        perror("Erreur Fork");
        exit(2);
    }

}