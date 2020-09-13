#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 

 /*
 Introduction au fork() et exec() : Ecrire un programme qui de crée et lance deux processus, chacun
 réalisant son propre traitement. Tester l’appel execlp() en écrivant un programme qui lance un autre programme (exécutable).
 */


int main() {
    int retourFork = fork();
    printf("retourFork = %d\n", retourFork);
    if (retourFork > 0) {
        printf("Je suis ton père\n");
    }
    if (retourFork == 0) {
        printf("Et moi luke\n");
    }
    if (retourFork < 0) {
        perror("Erreur Fork");
        exit(2);
    }
}