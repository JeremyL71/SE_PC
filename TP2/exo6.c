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

/*
  QUESTION 1): 
  fork retourne :
  · 0 si on se trouve dans le processus enfant
  · le PID du fils si on se trouve dans le processus parent
  · -1 en cas d'erreur

  Donc nous sommes dans le processus du pere

  QUESTION 2): Le WAIT(NULL) va obliger le processus père à attendre au moindre de ses fils 
    (Si l'enfant se termine avant que le processus parent n'atteigne, 
    wait(NULL)le processus enfant se transforme en a zombie process
    jusqu'à ce que son parent l'attende et qu'il soit libéré de la mémoire.)

  Ce programme est déterministe dans le sens ou chaque père va créer un fils puis attendre que celui-ci se termine.
  Le nombre de fils dépend du nombre de passage dans le boucle.

  le WAIT(NULL), nous permet de déterminé dans quel ordre les printf vont s'exécuter
  0, 8, 6, 4, 2,
  le premier 0 car le fils ne passe pas dans le if, donc n est toujours égale à 0
  le 8 correspond au dernier passage de la boucle for (donc au dernier fils crée) 4*2=8
  c'est un peu une sorte de FIFO

  QUESTION 3): Sans le WAIT(NULL), impossible de déterminé quel processus finira avant l'autre, donc la suite 0,8,6,4,2 n'est plus garantie, mais potentiellement 80642

  QUESTION 4): Le processus fork peut échouer  si on limite le nombre de ressource de programme exo6
