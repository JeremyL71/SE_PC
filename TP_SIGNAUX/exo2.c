#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int);

int main () {
   signal(SIGINT, sighandler);

   while(1) {
      printf("Going to sleep for a second...\n");
      signal(SIGINT , SIG_IGN); 
      sleep(1); 
   }
   return(0);
}

void sighandler(int signum) {
   printf("\nCaught signal %d, coming out...\n", signum);
   exit(1);
}