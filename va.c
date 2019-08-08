#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  printf("localización del código: %p\n",main);
  printf("localización del heap: %p\n", malloc(100e6));
  int x = 3;
  printf("localización de la pila: %p\n",&x);
  return x;
}
