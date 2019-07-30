#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  char *argv[] = {NULL};
  pid_t pid=fork();
  if(pid == -1)
   {
    printf("Fork fallido.\n");
   }
  else if (pid == 0)
   {
    execvp("./shell2",argv);
   }
  else
   {
    wait(NULL);
   }
  return 0;
}
