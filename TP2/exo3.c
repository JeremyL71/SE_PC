#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h> 

/*
Effet du fork() : Le programme suivant ouvre deux fichiers:
    - le premier [entrée] en mode LECTURE
    - le second [sortie] en mode ECRITURE

puis créé un processus fils et recopie le fichier d’entrée dans le fichier de sortie.

Les descripteurs df1 et df2 désignent les 2 mêmes fichiers dans les deux processus, car l’ouverture des 2 fichiers
correspondant est faite avant la création du processus fils (héritage). Exécutez plusieurs fois ce programme (sur
un gros fichier texte d’entrée) et commentez son résultat. Vous pouvez également examiner la trace
d’exécution dans le fichier trace. 
*/


int main() {
    int pid, df1, df2;
    char carac;
    df1 = open("entree", O_RDONLY);
    df2 = creat("sortie", 0666);

    FILE * trace = fopen("trace", "w");

    fprintf(trace, "Le caractère '#' indique que c’est le processus fils qui s'exécute \n");
    fprintf(trace, "Le caractère '$' indique que c’est le processus père qui s’exécute \n");

    fflush(trace);

    pid = fork();

    printf("Création de Processus \n");

      while (read(df1, & carac, sizeof(char)) > 0) {
        if (pid == 0) fprintf(trace, "# % c", carac);
        else fprintf(trace, "$ % c", carac);
        fflush(trace);
        write(df2, & carac, sizeof(char));
      }

      printf("Sortie de la boucle while \n"); close(df1); close(df2);
      return 0;
    }
