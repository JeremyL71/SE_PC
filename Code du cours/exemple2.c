#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h> 

int main( ) {
   int i=0;
   fork( );   
   fork( );   
   i++;
   fork( );
   i++;
   printf("%d\n",i);
   return 0 ;
}


/*schema 2^3process

P
|----|----|
f1   f2   f3
|    |
|    f1
|
|----|
f1   f2
|
f1