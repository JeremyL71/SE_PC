#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 

/*
L’appel à fork() dans une boucle : Ecrire un programme qui fait appel à la fonction fork() dans une boucle for (k=0 ; k<3 ; k++).

A chaque itération le programme affichera les informations suivantes :
    (k = valeur de k) : je suis le processus : pid, mon pere est : ppid , retour : retour

où
    • pid est le PID du processus courant,
    • ppid est le PID du processus père du processus courant,
    • retour est la valeur du code retour de l'appel à la fonction fork().

Dessiner l'arbre des processus correspondant à l'exécution de ce programme. 
*/

int main() {
    int i, retourExit, retourFork = 1, pid;

    printf("Le shell a pour PID %d\n", getppid());
    for(i = 0; i < 3; i++) {
        retourFork = fork();
        printf("Je suis le processus: %d (mon PID), mon Pere est %d (i=%d)\n", getpid(), getppid(), i);
    }

    while((pid = wait(&retourExit)) > 0) {
        printf("Code de retour du fils %d: WEXITSTATUS:%d\n", pid, WEXITSTATUS(retourExit));
    }
    
    sleep(3);
    exit(i);

}