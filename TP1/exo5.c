#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[]) {
    extern char **environ;
    int i = 0;
 
    while(environ[i] != NULL){
        if(commence_par(argv[1],environ[i])){
            printf("%s\n", environ[i]);
        }
        i++;
    }
    return 0;
}
 
int commence_par(char *valeure, char *texte){
    int i;
    int return_var=1;
 
    for(i=0;i<strlen(valeure);i++){
        if(valeure[i]!=texte[i]){
            return_var=0;
        }
    }
    return return_var;
}

 /*
int main(int argc, char *argv[]) {
    extern char **environ;
    int i = 0;
 
    while(environ[i] != NULL){
        if(est_egale(argv[1],environ[i])){
            printf("%s\n", environ[i]);
        }
        i++;
    }
    return 0;
}
 
int est_egale(char *valeur, char *texte){
    int i=0;
    int return_var=1;
 
    while(i<strlen(texte) && texte[i]!='='){
        if(valeur[i]!=texte[i]){
            return_var=0;
        }
        i++;
    }
    return return_var;
}


const char* s;

int main(int argc, char *argv[])
{
    printf("Nom du programme: %s\n", argv[0]);
    printf("Nombre d'arguments de la ligne de commande: %d\n", argc-1);
    printf("Les arguments sont: ");
    for(int i=1; i<argc ; i++){
        s = getenv(argv[i]);
        printf("%s :%s\n",argv[i], (s!=NULL)? s : "getenv a retourner NULL");
    }
    return(0);
}


*/