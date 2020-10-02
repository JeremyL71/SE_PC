#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

int main(int argc, char *argv[]) {
    int tube1[2],tube2[2]; 
    int pid1,pid2;
    int file1, file2;
    
    file1 = open(argv[1], O_RDONLY);
    if (file1 == -1){
        printf("Erreur ouverture du fichier");
        exit(1);
    }

    file2 = open(argv[2], O_CREAT | O_RDWR, 0644);
    if (file2 == -1){
        printf("Erreur creation du fichier");
        exit(1);
    }

    pipe(tube1);
    pipe(tube2);
    
    pid2=fork();
    pid1=fork();
    
    if (pid2 == 0) {
        close(tube1[0]);
        close(tube1[1]);
        close(tube2[1]); 
        dup2(tube2[0],0); 
        close(tube2[0]);
        dup2(file2,1);
        close(file2);
        execlp("tail", "tail", "-n", "5", NULL);
    }
    else if (pid1 == 0) {
        close(tube2[0]);
        close(tube1[1]);
        dup2(tube2[1],1);
        close(tube2[1]);
        dup2(tube1[0],0); 
        close(tube1[0]);
        execlp("grep", "grep", argv[3], NULL);
    } else {
        close(tube2[0]);
        close(tube2[1]);
        close(tube1[0]);
        dup2(tube1[1],1);
        dup2(file1,0);
        close(file1);
        close(tube1[1]);
        execlp("sort", "sort", NULL);
    }

    return 0;
}
