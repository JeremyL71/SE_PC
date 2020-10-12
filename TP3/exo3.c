#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int NombresPairs[2], NombresImpairs[2], SommePairs[2], SommeImpairs[2];
    int pipeNombresPairs, pipeNombresImpairs, pipeSommePairs, pipeSommeImpairs;
    int FiltrePair,FiltreImpair;
    int RandomNumber = 0, i = 0, numberSommePairs = 0, numberSommeImpairs = 0;

    srand(time(NULL));

    //Création des pipes
    pipeNombresPairs = pipe(NombresPairs);
    pipeNombresImpairs = pipe(NombresImpairs);
    pipeSommePairs = pipe(SommePairs);
    pipeSommeImpairs = pipe(SommeImpairs);

    if (pipeNombresPairs == -1 || pipeNombresImpairs == -1 || pipeSommePairs == -1 || pipeSommeImpairs == -1) {
        perror("Erreur création des pipes !");
        exit(2);
    }

    //Création des forks
    FiltrePair=fork();

    if (FiltrePair == -1) {
        perror("Erreur création du fork FiltrePair !");
        exit(2);
    }

    if (FiltrePair != 0) {
        FiltreImpair=fork();

        if (FiltreImpair == -1) {
            perror("Erreur création fork FiltreImpair !");
            exit(2);
        }
    }

    //Differents programmes
    if (FiltrePair == 0) {
        //Programme de FiltrePair
        //Fermeture des pipes Impairs + les mauvaises entrées sorties des s Pairs
        close(NombresImpairs[0]);
        close(NombresImpairs[1]);
        close(SommeImpairs[0]);
        close(SommeImpairs[1]);
        close(NombresPairs[1]);
        close(SommePairs[0]);

        //lecture et sommes des receptions jusqu'a recevoir -1
        while (RandomNumber != -1) {
            numberSommePairs = numberSommePairs + RandomNumber;
            read(NombresPairs[0], &RandomNumber, sizeof(RandomNumber));
            printf("FiltrePair : %d\n", RandomNumber);
        }
        close(NombresPairs[0]);
        write(SommePairs[1],&numberSommePairs, sizeof(numberSommePairs));
        close(SommePairs[1]);

    } else if (FiltreImpair == 0) {
        //Programme de FiltreImpair
        //Fermeture des pipes Impairs + les mauvaises entrées sorties des pipes Impairs
        close(NombresPairs[0]);
        close(NombresPairs[1]);
        close(SommePairs[0]);
        close(SommePairs[1]);
        close(NombresImpairs[1]);
        close(SommeImpairs[0]);

        //lecture et sommes des receptions jusqu'a recevoir -1
        while (RandomNumber != -1) {
            numberSommeImpairs = numberSommeImpairs + RandomNumber;
            read(NombresImpairs[0], &RandomNumber, sizeof(RandomNumber));
            printf("FiltreImpair : %d\n", RandomNumber);
        }
        close(NombresImpairs[0]);
        write(SommeImpairs[1],&numberSommeImpairs, sizeof(numberSommeImpairs));
        close(SommeImpairs[1]);

    } else {
        //Programme du Générateur
        //Fermeture des mauvaises entrées sorties des pipes Pairs et Impairs
        close(NombresPairs[0]);
        close(NombresImpairs[0]);
        close(SommePairs[1]);
        close(SommeImpairs[1]);

        //Generation des nombre et envoi aux fils
        for (i=0; i < atoi(argv[1]);i++) {
            RandomNumber = rand() % 100;
            printf("Générateur : %d\n", RandomNumber);
            if (RandomNumber % 2 == 0) {
                write(NombresPairs[1], &RandomNumber, sizeof(RandomNumber));
            } else {
                write(NombresImpairs[1], &RandomNumber, sizeof(RandomNumber));
            }
        }

        //Envoi des signaux de fin aux fils et fermeture des connexions d'envoi
        RandomNumber = -1;
        write(NombresPairs[1], &RandomNumber, sizeof(RandomNumber));
        write(NombresImpairs[1], &RandomNumber, sizeof(RandomNumber));
        close(NombresPairs[1]);
        close(NombresImpairs[1]);

        read(SommePairs[0], &numberSommePairs, sizeof(&numberSommePairs));
        read(SommeImpairs[0], &numberSommeImpairs, sizeof(&numberSommeImpairs));
        //Femeture des connexions de receptions
        close(SommePairs[0]);
        close(SommeImpairs[0]);

        printf("Somme des Pairs : %d\nSomme des Impairs : %d\nSomme Totale : %d\n", numberSommePairs, numberSommeImpairs, numberSommePairs+numberSommeImpairs);
    }
}