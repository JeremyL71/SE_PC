#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h> 

/*
 Ecrire un programme C qui prend en paramètre une série de fichiers source .c, les
compile en simultané puis édite les liens pour produire un exécutable. Ce programme doit :

• lancer un processus fils pour chacun des fichiers passés en paramètre ;
• chaque processus fils doit exécuter la commande gcc -c sur le fichier dont il s'occupe ;
• le père doit attendre la terminaison de tous ses fils [de toutes les compilations] ;
• si l'ensemble des fils ont terminés sans erreur, le père génère un exécutable - Phase d'édition de liens en exécutant gcc -o sur les fichiers.o produits par les fils. 
*/

int main(int argc, char * argv[]) {

}