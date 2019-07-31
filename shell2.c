#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#define MAX  1000  //Input
#define MAXP 10000 //Input Converted

char cwd[1024];
char shell[1024];

void present()
{
 printf("\n ******** BIENVENIDO A MI SHELL ********\n");
 sleep(1);
 system("clear");
}
int catching(char *origen)
{
  printf("prompt> ");
  scanf("%[^\n]s", origen);
  
}

void inDir(char *arg)
{
  DIR *dir;
  dir = opendir(arg);
  if (dir == NULL)
    {
     printf("Error!! Al abrir el directorio.\n");
     } 
   else 
    {
     chdir(arg);

    }
}

void listDir(char *arg)
{
    DIR *mydir;
    struct dirent *myfile;
    mydir = opendir(arg);
    while((myfile = readdir(mydir)) != NULL)
    {
      printf("%s ", myfile->d_name);
    }
    closedir(mydir);
}

void route_shell()
{getcwd(shell,sizeof(shell));}

void route()
{
  getcwd(cwd,sizeof(cwd));
  printf("$PWD = %s:    $shell=%s\n",cwd,shell);
}

void print(char *arg)
{printf("%s\n",arg);}

void help() 
{
   printf("\n--- BIENVENIDO A SHELL ---"
          "\n La lista de comandos internos disponibles es:"
          "\n * cd <directorio>: Cambiar el directorio"
          "\n * clr: Limpiar la pantalla"
          "\n * dir: Listar el contenido del directorio"
          "\n * environ: Listar todas las cadenas de entorno"
          "\n * echo <comentario>: Desplegar el comentario en pantalla"
          "\n * help: Desplegar el manual de usuario"
          "\n * pause: Deterner la operación del shell hasta que el usuario desee"
          "\n * quit: Salir de SHELL\n"); 
}

void paus()
{
  char op;
  do
   {
    printf("Pausado..."
           "\nPresionar Enter para continuar...");
   }
  while(op != '\n');
}

void comandos(char *comand, char *arg)
{
  char* comandos[8];
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
    char buff[strlen(comandos[i])+1];
    strcpy(buff,comandos[i]);
    int j=0,flag=0;
    for(j;buff[j] != '\0' && comand[j] != '\0'; j++)
    {
     if(buff[j]==comand[j])
      {}
     else 
     {
      flag = 1;
      break; 
     }
    }
    if(flag==0)
         {i+=1; break;} //encontrado
    else {continue;}   //no encontrado
    }

 switch(i)
  {
  case 1: 
   inDir(arg);
   break;
  case 2:
   system("clear");
   break;
  case 3:
   listDir(arg);
   break;
  case 4:
   route();
   break;
  case 5:
   print(arg);
   break;
  case 6:
   help();
   break;
  case 7:
   paus();
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
 for(i; i<(strlen(conv)+1); i++)
  {
    if(conv[i] == ' ') { break;}
    comand[i]=conv[i];
  }
  i=i+1;
  for(i; i<(strlen(conv)+1); i++)
  {
   char uniones[MAXP];
   uniones[0]=conv[i];
   if(conv[i] == '\0') {break;}
   strcat(arg,uniones);
   j+=1;
  }
  comandos(comand,arg);
  }

int main()
{
  present();
  route_shell();
  char args[MAX];
  char conv[MAXP];
  catching(args);
  converted(args, conv);
 
  
 return 0;
}
