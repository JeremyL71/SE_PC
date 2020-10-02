#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <time.h>

int check_pair(int x);

int main(int argc, char *argv[]) {

    pid_t fork_1, fork_2;

    int NombresPairs[2], NombresImpaires[2], SommePairs[2], SommeImpaire[2];
    int nb , somme_pair, somme_impaire = 0;
    pipe(NombresImpaires);
    pipe(NombresPairs);
    pipe(SommeImpaire);
    pipe(SommeImpaire);

    fork_1 = fork();
    fork_2 = fork();

    if(fork_1 == 0){
        for(int i=0; i<atoi(argv[1]); i++){
            srand(time(NULL));   
            nb = rand();  
            printf("mon nombre est: %d\n", nb);
            if(check_pair(nb)){
                /* Si le nombre est pair
                --> fermeture de la sortie de NombrePair et Impaire */
                close(NombresPairs[0]);
                close(NombresImpaires[0]);
                // Fermture des tubes Sommes
                close(SommeImpaire[1]);
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
                close(SommeImpaire[1]);
                close(SommePairs[1]);
                // Fermeture de l'entree nombresPairs
                close(NombresPairs[1]);
                // Envoi dans le tube
                write(NombresImpaires[1], &nb, sizeof(nb));
            }
        }
        // Envoi du --1 pour les deux tubes
        int fin = -1;
        write(NombresImpaires[1], &fin, sizeof(fin));
        write(NombresPairs[1], &fin, sizeof(fin));
        somme_pair = read(SommePairs[0], &somme_pair, sizeof(somme_pair));
        somme_impaire = read(SommePairs[0], &somme_impaire, sizeof(somme_impaire));
        int somme_totale = somme_impaire + somme_pair;
        printf("somme_pair: %d + somme_impaire: %d = somme_totale: %d\n", somme_pair, somme_impaire, somme_totale);
        exit(0); 
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
        while(read(NombresPairs[0], &nb, sizeof(nb)) == -1){
            somme_pair = somme_pair + nb;
        }
        write(SommePairs[1], &somme_pair, sizeof(somme_pair));
        exit(0);
    }
    else if(fork_2==0){
        // Processus FiltreImpaire

         // Fermeture des tubes Nombres
        close(NombresImpaires[0]);
        close(NombresImpaires[0]);
        close(NombresImpaires[1]);
        // Fermeture des tubes Sommes
        close(SommeImpaire[0]);
        close(SommePairs[1]);
        close(SommePairs[0]);
        // Réalisation de la somme
        while(read(NombresImpaires[0], &nb, sizeof(nb)) == -1){
            somme_impaire = somme_impaire + nb;
        }
        write(SommeImpaire[1], &somme_impaire, sizeof(somme_impaire));
        exit(0);
    }
}


int check_pair(int x){
    if(x%2)return 1;
    else return 0;
}