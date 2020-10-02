#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <time.h>


int main(int argc, char *argv[]) {

    pid_t fork_1, fork_2;

    int NombresPairs[2], NombresImpaires[2], SommePairs[2], SommeImpaire[2];
    int nb;
    pipe(NombresImpaires);
    pipe(NombresPairs);
    pipe(SommeImpaire);
    pipe(SommeImpaire);

    fork_1 = fork();
    fork_2 = fork();

    if(fork_1 == 0){
        for(int i=0; i< argv[1]; i++){
            srand(time(NULL));   
            nb = rand();  
            printf("mon nombre est: %d", nb);
            if(has_even_parity(nb)){
                /* Si le nombre est pair
                --> fermeture de la sortie de NombrePair et Impaire */
                close(NombresPairs[0]);
                close(NombresImpaires[0]);
                // Fermture des tubes Sommes
                // close(SommeImpaire[0]);
                close(SommeImpaire[1]);
                // close(SommePairs[0]);
                close(SommePairs[1]);
                // Fermeture de l'entree nombresImpaire
                close(NombresImpaires[1]);
                // Envoi dans le tube
                write(NombresPairs[1], &nb, sizeof(nb));
            }
            else{
                /* Si le nombre est impaire
                --> fermeture de la sortie de NombrePair et Impaire */
                close(NombresPairs[0]);
                close(NombresImpaires[0]);
                // Fermeture des tubes Sommes
                // close(SommeImpaire[0]);
                close(SommeImpaire[1]);
                // close(SommePairs[0]);
                close(SommePairs[1]);
                // Fermeture de l'entree nombresPairs
                close(NombresPairs[1]);
                // Envoi dans le tube
                write(NombresImpaires[1], &nb, sizeof(nb));
            }
        }
        // Envoi du --1 pour les deux tubes
    }
    else if(fork_1 > 0)
    {
        // Processus FiltrePair
        
        // Fermeture des tubes Nombres
        close(NombresPairs[0]);
        close(NombresImpaires[0]);
        close(NombresImpaires[1]);
        // Fermeture des tubes Sommes
        close(SommeImpaire[0]);
        close(SommeImpaire[1]);
        close(SommePairs[0]);
        // Réalisation de la somme
        read(NombresPairs, &nb, sizeof(nb));
        while(nb == -1){

        }
        

    }
    else(fork_2==0){
        // Processus FiltreImpaire
    }
}


int check_pair(int x){
    if(x%2)return 1;
    else return 0;
}