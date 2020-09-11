#include<stdio.h>
#include<string.h>
 
int main(int argc, char *argv[]) {
   char temp;
   char *string;
   int i, j;
 
   /* Control du nombre d'argument*/
   if(argc!=2){
       printf("Manque une string\n");
       return 1;
   }
    
   string = argv[1]; 
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
   return 0;
}