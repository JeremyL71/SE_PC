#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, char *argv[]) {
    int note, total=0;
    double moyenne;
    int i,j;
    int isNumber;
    int length;
    char *string;
 
    if (argc <=1) {
        printf("Aucune moyenne a calculer\n");
        return 1;
    }
 
    for(i=1;i<argc;i++) {
        string=argv[i];
        length = strlen(string);
        isNumber = 1;
        for(j=0;j<length;j++) {
            if (!isdigit(string[j])){
                isNumber = 0;
            }
        }
        note = atoi(string);
        if (note>=0 && note<=20 && isNumber){
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