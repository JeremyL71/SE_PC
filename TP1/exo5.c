#include <stdio.h>
#include <stdlib.h>

const char* s;

int main(int argc, char *argv[])
{
    printf("Nom du programme: %s\n", argv[0]);
    printf("Nombre d'arguments de la ligne de commande: %d\n", argc-1);
    printf("Les arguments sont: ");
    for(int i=1; i<argc ; i++){
        s = getenv(argv[i]);
        printf("%s :%s\n",argv[i], (s!=NULL)? s : "getenv returned NULL");
    }
    return(0);
}
