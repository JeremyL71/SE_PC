#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h> 

/*
1  Donnez l’arbre généalogique des processus engendrés par ce programme.
2. Quels sont les affichages possibles ?
3. Sans modifier les lignes de 2 à 5, modifiez ce programme de façon à ce que les processus fassent leur affichage par ordre alphabétique inversé du nom. 
*/

int main() {
  int i, delai;
  for (i = 0; i < 4; i++)
    if (fork()) break;
  srand(getpid());
  delai = rand() % 4;
  sleep(delai);
  printf("Mon nom est %c, j’ai dormi pendant %d secondes\n", 'A' + i, delai);
  exit(0);
}

/*
La ligne de  if (fork()) break; au fils d'être générée et de sortir de la boucle.

P
|  |  |  |
f1 f2 f3 f4

Mon nom est D, j’ai dormi pendant 0 secondes
Mon nom est B, j’ai dormi pendant 1 secondes
Mon nom est A, j’ai dormi pendant 2 secondes
Mon nom est C, j’ai dormi pendant 2 secondes
Mon nom est E, j’ai dormi pendant 3 secondes


*/