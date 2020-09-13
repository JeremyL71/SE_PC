#include <sys/types.h>

#include <unistd.h>

/*
 Questions cours : Soit un système qui exécute le programme suivant : 
    - Après la ligne étiquetée /2/, dans le bloc d’exécution du if, on se retrouve dans quel processus, le père ou le fils ? Pour qui la valeur de pid vaut 0 ?
    
    - Ce programme est-il déterministe? (Justifiez)

    - Même question si l’on supprime la ligne étiquetée /3/ - justifiez.

    - Si le programme est déterministe tel quel, indiquez exactement ce qui sera affiché à l’écran lors de son exécution. S’il n’est pas déterministe, donnez un des
      affichages possibles.

    - L’appel à fork(), ligne étiquetée /1/, peut-il échouer? Pourquoi? 
 
*/

int main() {
  int i, n = 0;
  pid_t pid;
  for (i = 1; i < 5; i++) {
    pid = fork(); /*1*/
    if (pid > 0) {
      /*2 */
      wait(NULL); /*3*/
      n = i * 2;
      break;
      /*sortie de la boucle*/
    }
  }
  printf("%d\n", n); /* 4 */
}