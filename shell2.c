#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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



int main(int argc, char *argv[])
{
 printf("%s\n",argv[1]);
 return 0;
}
