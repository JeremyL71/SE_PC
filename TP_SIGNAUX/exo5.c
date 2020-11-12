#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h>
#include <signal.h>

void sighandler(int);

int main() {
    int retourFork = fork();

    if (retourFork > 0) {
        printf("\nJe suis le père");
        while(1) {
            printf("[PERE] Je suis le processus: %d (mon PID), mon Pere est %d\n", getpid(), getppid());
            sleep(1); 
        }
    }
    if (retourFork == 0) {
        printf("Et moi luke");
        signal(SIGINT, sighandler); 
        while(1) {
            printf("[FILS] Je suis le processus: %d (mon PID), mon Pere est %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    if (retourFork < 0) {
        perror("Erreur Fork");
        exit(2);
    }

}

void sighandler(int signum) {
   printf("\nsignal %d  reçu par le processus: %d\n", signum, getpid());
}