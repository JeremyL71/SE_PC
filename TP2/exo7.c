#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

/*
Ecrire un programme C dont le fonctionnement est le suivant :
    - il lit sur la ligne de commande (utiliser argc et argv) le nombre N de processus à créer.
    - il crée ces N processus en faisant N appels à fork().
    - il se met en attente (appel à pid_fils = wait(&Etat)) de ces N processus fils et visualise leur identité (pid_fils et valeur de Etat) 
      au fur et à mesure de leurs terminaisons. Pour attendre la fin de tous les fils, utiliser 
      le fait que wait renvoie la valeur -1 quand il n'y a plus de processus fils à attendre

Chacun des processus fils Pi réalise le traitement suivant :
    - il visualise son PID ( getpid() ) et celui de son père ( getppid() ),
    - il se met en attente pendant 2*i secondes ( sleep (2*i) ), visualise la fin de l'attente,
    - il se termine par exit (i).

*/

int main(int argc, char *argv[]) {

    /* Control du nombre d'argument*/
    if(argc!=2){
        printf("Manque le nombre d'itération\n");
        return 1;
    }

    pid_t Etat, retourFork, pid_fils;
    int N = atoi(argv[1]);

    printf("N = %d\n", N);

    for(int i=0; i<N ;i++)
    {
        retourFork = fork();
        printf("Je suis le processus: %d (mon PID), mon Pere est %d (i=%d)\n", getpid(), getppid(), i);
        if(retourFork == 0){
            sleep(2*i);
            exit(i);
        }
    }
    while((pid_fils = wait(&Etat)) > 0) {
        printf("Code de retour du fils %d: WEXITSTATUS:%d\n", pid_fils, WEXITSTATUS(Etat));
    }
    return(0);

} //fin du main