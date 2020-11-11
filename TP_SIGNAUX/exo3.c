#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
int FIN = 0;

void sighandler(int);

int main () {

    signal(SIGINT, sighandler);
    int compte_a_rebours = 4;

    while(1) {
        printf("je tourne en boucle et la variable fin vaut: %d\n", FIN); 
        sleep(1);
        if (FIN == 1) {
            compte_a_rebours--;
            if (compte_a_rebours != 0)
            {
                printf("\nFin dans %d\n", compte_a_rebours);
            }
            else return 0;
        }
    }
    }

void sighandler(int signum) {
    printf("\nUn signal d'interruption !, je passe la variable fin à 1\n");
    FIN = 1;
}