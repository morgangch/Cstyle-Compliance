
#include <stdio.h>
int funky(int a, int b) { return a + b; }
#include <stdlib.h>
main(int argc, char *argv[]) {
  printf("Hello, World!\n") ;
  int i = 0 ;
  char a;  
  for (i = 0; i < funky(a, 10); i++)
  {
    printf("Hello, World! %i\n",i) ;
  }
    return 0; }