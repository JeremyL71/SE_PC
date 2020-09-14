#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

/*
Ecrire un programme C équivalent aux commandes shell suivantes : 

• who & ps & ls –l Les commandes séparées par & s'exécutent simultanément.
• who ; ps ; ls -l Les commandes séparées par ; s'exécutent successivement.
*/

void simultanement();
void successivement();

int main() {
    printf("Le shell a pour PID %d\n", getppid());
    int pid = fork();
    if (pid == 0){
        successivement();
    }
    waitpid(pid, NULL, 0);
    printf("\n\n");
    simultanement();
}

void simultanement(){
    printf("Le shell a pour PID %d\n", getppid());
    if(!fork())
    {
        printf("Je suis le processus: %d (mon PID), mon Pere est %d \n", getpid(), getppid());
        execlp("who", "who", NULL);
    }
    if(!fork())
    {
        printf("Je suis le processus: %d (mon PID), mon Pere est %d \n", getpid(), getppid());
        execlp("ps", "ps", NULL);
    }
    printf("Je suis le processus: %d (mon PID), mon Pere est %d \n", getpid(), getppid());
    execlp("ls", "ls", "-l", NULL);
    
}

void successivement(){
    int retourExit;
    printf("Le shell a pour PID %d\n", getppid());
    if(!fork())
    {
        printf("Je suis le processus: %d (mon PID), mon Pere est %d \n", getpid(), getppid());
        execlp("who", "who", NULL);
    }
    wait(&retourExit);
    if(!fork())
    {
        printf("Je suis le processus: %d (mon PID), mon Pere est %d \n", getpid(), getppid());
        execlp("ps", "ps", NULL);
    }
    wait(&retourExit);
    printf("Je suis le processus: %d (mon PID), mon Pere est %d \n", getpid(), getppid());
    execlp("ls", "ls", "-l", NULL);
}