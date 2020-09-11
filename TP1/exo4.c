#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, char *argv[]) {
    int note, total=0;
    double moyenne;
    int i;
 
    if (argc <=1) {
        printf("Aucune moyenne a calculer\n");
        return 1;
    }
 
    for(i=1;i<argc;i++) {
        int conv = sscanf(argv[i],"%d",&note);
        if (note>=0 && note<=20 && conv!=0){
            total = total + note;
        } else {
            printf("Notes non valide\n");
            return 1;
        }
    }
 
    moyenne = (float)total / (argc-1);
    printf("Moyenne est : %.2f\n",moyenne);
    return 0;
}