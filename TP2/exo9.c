#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h> 


/*
Ajoutez à l'endroit indiqué dans le programme ci dessous des instructions permettant de gérer les processus nécessaires pour avoir 4 N fois l'affichage du message «Bonjour». 

- Vous ne pouvez pas insérer du code supplémentaire ailleurs qu'à l'endroit indiqué (sauf si vous voulez ajouter des déclarations de variables), 

- vous ne pouvez plus ajouter d'appels printf(). 

- Vous devez donner une solution utilisant des fork( ), avec éventuellement des wait( ). Donnez toutes les justifications nécessaires.
*/

#define N 3
int main(int argc, char * argv[]) {
  int i, pid1, pid2;
  for (i = 0; i < N; i++) {
    /* __________debut des ajouts__________ */
    /* __________fin des ajouts__________ */
  }
  printf("Bonjour\n");
  return 0;
}