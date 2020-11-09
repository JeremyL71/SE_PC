#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h> 


int main(int argc, char * argv[]) {
  char * f[20];
  int status, i, j = 0;
  for (i = 1; i <= argc; i++) {
    if (fork() == 0) {
      execlp(argv[i], argv[i], NULL);
      exit(3);
    }
    wait( & status);
    if (WIFEXITED(status)) {
      printf("Terminaison normale du processus fils.\n");
      if (WEXITSTATUS(status) == 3) { 
            printf("error: %s, doesn't work \n", argv[i]);
            //récupérer le code de retour 
            f[j] = (char * ) malloc(strlen(argv[i]) + 1);
            strcpy(f[j], argv[i]); 
            // strcpy(s1, s2) : copie la chaîne de caractère s2 dans s1
            j++;
      }
    }
  }
  if (j != 0)
    printf("les commandes qui n'ont pas fonctionné: \n");
    for (i = 0; i < j; i++) printf(" %s \n", f[i]);
  return 0;
}
