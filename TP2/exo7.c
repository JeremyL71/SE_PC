#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h> 

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