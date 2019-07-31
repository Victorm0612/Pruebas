#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
 char *palabras[10];
 palabras[0]="hola";
 if(strcmp(argv[1],palabras[0])==0)
  {
   printf("\nYeah\n");
  }
 else
  {
   printf("\nPALABRA: %s",palabras[0]);
   printf("\nARGV: %s\n",argv[1]);
  }
 return 0;
}

