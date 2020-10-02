#define _POSIX_SOURCE 1
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define S_BUF 500

int main(int argc, char ** argv) {
  int mon_premier_tube[2];
  int mon_second_tube[2];
  char buffer[S_BUF];
  int n;

  pid_t fork_1;
  pid_t fork_2;

  if (pipe(mon_premier_tube) == -1 ) {
      // En cas d'erreur création du tube
    perror("pipe");
    exit(1);
  }
  if (pipe(mon_second_tube) == -1 ) {
      // En cas d'erreur création du tube
    perror("pipe");
    exit(1);
  }
  
  if (fork_1 == 0) {
    /*fils */
    /*configuration des tubes*/
    close(mon_premier_tube[0]);
    close(mon_premier_tube[1]);

    close(mon_second_tube[1]);
    dup2(mon_second_tube[0], 0);
    close(mon_second_tube[0]);
    /*execution*/
    execlp("tail", "tail", "-n", "5", NULL);
  }

  else if(fork_2 == 0){
    close(mon_premier_tube[1]);
    dup2(mon_premier_tube[0], 0);
    close(mon_premier_tube[0]);

    close(mon_second_tube[0]);
    dup2(mon_second_tube[1], 1);
    close(mon_second_tube[1]);
    execlp("grep", "grep", argv[2], NULL);
  }

  else {
    /*père */
    close(mon_second_tube[0]);
    close(mon_second_tube[1]);

    close(mon_premier_tube[0]);
    dup2(mon_premier_tube[1], 1);
    close(mon_premier_tube[1]);
    execlp("sort", "sort", argv[1], NULL);
  }
  return (EXIT_SUCCESS);
}