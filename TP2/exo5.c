#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

/*
 Ecrire un programme C qui prend en paramètre une série de fichiers source .c, les
compile en simultané puis édite les liens pour produire un exécutable. Ce programme doit :

• lancer un processus fils pour chacun des fichiers passés en paramètre ;
• chaque processus fils doit exécuter la commande gcc -c sur le fichier dont il s'occupe ;
• le père doit attendre la terminaison de tous ses fils [de toutes les compilations] ;
• si l'ensemble des fils ont terminés sans erreur, le père génère un exécutable - Phase d'édition de liens en exécutant gcc -o sur les fichiers.o produits par les fils. 
*/

int main(int argc, char *argv[])
{
	int etat, cpt = 0, j;
	char **command, *name;
	command = malloc(10 * sizeof(char *));
	command[0] = "gcc";

	if (argc == 1)
	{
		printf("Passez des arguments à ce programme\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
        int retourFork = fork();
		if (retourFork == 0)
		{
			execlp("/usr/bin/gcc", "gcc", "-c", argv[i], NULL);
			exit(-2);
		}
		else
		{
			wait(&etat);
			if (WIFEXITED(etat))
			{
				cpt++;
			}
			else
			{
				return 1;
			}
			if (cpt == argc - 1)
			{
				for (j = 1; j <= (argc - 1); j++)
				{
					name = strtok(argv[j], ".");
					strcat(name, ".o");
					command[j] = name;
				}
				command[j++] = "-o";
				command[j++] = "result";
				command[j++] = NULL;

				execvp("/usr/bin/gcc", command);
			}
		}
	}
	return 0;
}