#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Le shell a pour PID %d\n", getppid());
    int i, delai;
    for(i=0; i<4;i++){
        if(fork()) 
        {
            break;
        }
    }
    srand(getpid());
    delai = rand()%4;
    sleep(delai);
    printf("Mon nom est %c, j’ai dormi pendant %d secondes\n", 'A' + i, delai);
    printf("Je suis le processus: %d (mon PID), mon Pere est %d\n", getpid(), getppid());
    exit(0);
}
