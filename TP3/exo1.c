#define _POSIX_SOURCE 1
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define S_BUF 100

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
    if ((n = read(tubeDesc[0], buffer, S_BUF)) == -1) {
      perror("read");
      exit(1);
    } else {
      close(tubeDesc[1]); read(tubeDesc[0], buffer, S_BUF);
      buffer[n] = '\0';
      printf("%s\n", buffer);
    }
    exit(0);
  } else {
    /*père */
    close(tubeDesc[0]);
    if (write(tubeDesc[1], "Bonjour", 7) == -1) {
      perror("read");
      exit(1);
    }
    close(tubeDesc[1]);
    wait(NULL);
  }
  return (EXIT_SUCCESS);
}