#include <stdio.h>
#include <string.h>
int main(void) {
  char str1[4]="abd";
  char str2[4]="abd";
  int retorno;

  retorno=strcmp(str1, str2);
  printf("%d o retorno\n", retorno);

  return 0;
}
