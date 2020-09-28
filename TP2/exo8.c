#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h> 
#include <string.h>
#include <sys/wait.h>

/*
1  Donnez l’arbre généalogique des processus engendrés par ce programme.
2. Quels sont les affichages possibles ?
3. Sans modifier les lignes de 2 à 5, modifiez ce programme de façon à ce que les processus fassent leur affichage par ordre alphabétique inversé du nom. 
*/

int main() {
    printf("Le shell a pour PID %d\n", getppid());
    int i, delai;

    /* ne pas toucher */
    for(i=0; i<4;i++){
        if(fork()) 
        {
            break;
        }
    }
    srand(getpid());
    delai = rand()%4;
    sleep(delai);
    /* ne pas toucher */

    wait(NULL);
    
    printf("Mon nom est %c, j’ai dormi pendant %d secondes\n", 'A' + i, delai);
    printf("Je suis le processus: %d (mon PID), mon Pere est %d\n", getpid(), getppid());
    exit(0);
}

/*
La ligne de  if (fork()) break; permet au père de générée un fils qui ne rentrera pas dans la boucle.

P
| 
f1 
|
f2
...
f4

Mon nom est D, j’ai dormi pendant 0 secondes
Mon nom est B, j’ai dormi pendant 1 secondes
Mon nom est A, j’ai dormi pendant 2 secondes
Mon nom est C, j’ai dormi pendant 2 secondes
Mon nom est E, j’ai dormi pendant 3 secondes


*/