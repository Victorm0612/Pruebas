#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX  1000  //Input
#define MAXP 10000 //Input Converted

void catching(char *origen)
{
  printf("\n ****** BIENVENIDO A MI SHELL ******\n");
  sleep(1);
  system("clear");
  printf("prompt> ");
  scanf("%[^\n]s", origen);
}

void inDir()
{}

void listDir()
{}

void route()
{}

void print()
{}

void help()
{}

void paus()
{}

void comandos(char *parsed)
{
  char* comandos[8];
  char  buff[strlen(comandos)+1];
  comandos[0]="cd";
  comandos[1]="clr";
  comandos[2]="dir";
  comandos[3]="environ";
  comandos[4]="echo";
  comandos[5]="help";
  comandos[6]="pause";
  comandos[7]="quit";

  int i=0;
  for(i; i<8; i++)
  {
    strcpy(buff,comandos[i]);
    if(buff[i]==parsed[0])
     {
      i=i+1;
      break;
     } 
  }
 switch(i)
  {
  case 1: 
   inDir();
   break;
  case 2:
   system("clear");
   break;
  case 3:
   listDir();
   break;
  case 4:
   route();
   break;
  case 5:
   print();
   break;
  case 6:
   help();
   break;
  case 7:
   pause();
   break;
  case 8:
   exit(0);
   break;
  default:
   break;
  }
}

void converted(char *args, char *conv)
{
 char comand[MAX];
 char arg[MAXP];
 //PASAR DE ["cd carpeta"] a ["c","d"," ","c"...]
 //AL LLEGAR AL PRIMER ESPACIO ENTONCES TENGO MI COMANDO
 //ESE COMANDO GUARDARLO EN OTRO ARREGLO EN LA PRIMERA POS
 //LO QUE HAYA DESPUES DEL ESPACIO EN LA SEGUNDA POS
 strcpy(conv,args);
 int i=0,j=0;
 for(i;i<(strlen(conv)+1);i++)
  {
    if(conv[i] == ' ') { break;}
    comand[i]=conv[i];
  }
  i=i+1;
  for(i;i<(strlen(conv)+1);i++)
  {
   if(conv[i] == '\0') {break;}
   arg[j]=conv[i];
   j+=1;
  }
  char total[2];
  total[0]=comand;
  total[1]=arg;
  comandos(total);
  }

int main()
{
 char args[MAX];
 char conv[MAXP];
 catching(args);
 converted(args, conv);
 return 0;
}
