#define _POSIX_SOURCE 1
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define S_BUF 500

int main(int argc, char ** argv) {
  int tubeDesc[2];
  char buffer[S_BUF];
  int n;

  pid_t pid_fils;

  if (pipe(tubeDesc) == -1) {
      // En cas d'erreur création du tube
    perror("pipe");
    exit(1);
  }
  if ((pid_fils = fork()) == -1) {
      // En cas d'erreur création du fork
    perror("fork");
    exit(1);
  }

  if (pid_fils == 0) {
    /*fils */
    close(tubeDesc[1]);
    dup2(tubeDesc[0], 0);
    close(tubeDesc[0]);
    execlp("wc", "wc", NULL);
  } else {
    /*père */
    close(tubeDesc[0]);
    dup2(tubeDesc[1], 1);
    close(tubeDesc[1]);
    execlp("cat", "cat", argv[1], NULL);
  }
  return (EXIT_SUCCESS);
}