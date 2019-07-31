#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main(int argc, char *argv[])
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
}*/

int main(int argc, char *argv[])
{ 
  char cen[5]={'h','o','l','a','\0'};
  char con[100];
  char can[10];
  int i=0;
 for(i; i<4; i++)
  {
   if(cen[i]=='\0'){break;}
   can[0]=cen[i];
   strcat(con,can);
  }
  printf("\n%s\n",con);
}

