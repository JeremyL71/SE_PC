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