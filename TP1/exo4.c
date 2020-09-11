#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

int main(int argc, char *argv[]) {

    printf("Nom du programme: %s\n", argv[0]);
    printf("Nombre d'arguments de la ligne de commande: %d\n", argc-1);

    if(argc=0) perror("Aucune moyenne a calculer");

    /*
     * On passe le nom de l'exécutable qui est
     * en première position dans les arguments.
     */
    argc--;   argv++;

    int sum = 0;
    int t = 0;

    /*
     * On somme toutes les valeurs passées en arguments du programme.
     * Pour ce faire on déplace le pointeur argv pour scanner tous les arguments.
     */
    while ( argc != 0 ) {
        if(0 >= *argv || 20 <= *argv) perror("Note non valide, pas entre 0 et 20");
        if(!isdigit(*argv)) perror("Note non valide, ce n'est pas un int");

        printf("\nLa valeur actuelle: %s",*argv);
        sum += atoi( *argv++ );
        argc--;
        t++;
    }
    
    printf("\nla somme: %d: \n", sum);
    float average = sum / (float)t;
    printf("\nVotre moyenne est: %.2f\n", average);
    return(0);

} //fin du main