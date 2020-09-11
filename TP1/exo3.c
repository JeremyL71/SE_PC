#include<stdio.h>
#include<string.h>
 
int main(int argc, char *argv[]) {
    char temp;
    char *string;
    int i, j;

    printf("Nom du programme: %s\n", argv[0]);
    printf("Nombre d'arguments de la ligne de commande: %d\n", argc-1);
    printf("Les arguments sont: ");

    for(int x=1; x<argc ; x++){
        printf("\n %d: %s\n",x,argv[x]);

        string = argv[x] ;
        i = 0; 
        j = strlen(string) - 1; 

        while (i < j) {
            temp = string[i];
            string[i] = string[j];
            string[j] = temp;
            i++;
            j--;
        }

        printf("%s\n",string);
    }
   return 0;
}