#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char palabras[100];
void ejecucionProcesos(char *parsed[])
{
  pid_t pid=fork();
  if(pid == -1)
   {
    printf("\nFork fallido.");
    return;
   }
 else if (pid == 0)
   {
    execv(parsed[1],parsed);
    exit(0);
   }
 else
   {
    wait(NULL);
   }
}

void capturadora()
{
  printf("\n ****** BIENVENIDO A MI SHELL ******\n");
  scanf("%s", palabras);
  printf("\n %s \n",palabras);
}


int main(int argc, char *argv[])
{
 capturadora();
 return 0;
}
