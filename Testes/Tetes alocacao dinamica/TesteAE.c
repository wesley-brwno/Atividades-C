#include <stdio.h>
#include <stdlib.h>

int main() {
  int x, *y; // y é um ponteiro para inteiro;

  x=5;
  y = malloc(sizeof(int)); // y aponta para área de memoria alocada pela função malloc;
  printf("%i\n", *y);
  *y = 3; // o lugar para onde y aponta recebe 3
  printf("%i\n", *y);
  free(y);
  y = &x; // y aponta para a área de dados de x;
  printf("%i\n", *y);
  *y = 1;
  printf("%i\n", *y);

  return 0;
}
