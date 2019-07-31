#include <unistd.h> // execvp()
#include <stdio.h>  // perror()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main(void) {
  char *const cmd1[] = {"cd","carpeta", NULL};
  char *const cmd2[] = {"clr", NULL};
  char *const cmd3[] = {"dir", NULL};
  char *const cmd4[] = {"environ", NULL};
  char *const cmd5[] = {"echo","something", NULL};
  char *const cmd6[] = {"help", NULL};
  char *const cmd7[] = {"pause", NULL};
  char *const cmd8[] = {"quit", NULL};
  execvp(cmd[0], cmd);
  perror("Return from execvp() not expected");
  exit(EXIT_FAILURE);
}
