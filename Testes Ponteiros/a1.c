#include <stdio.h>

int main() {

  int x = 10;
  int *ponteiro;
  ponteiro = &x;

  int y=20;
  *ponteiro = y; // O ponteiro aponta para o endereço de memoria de x;


  printf("%i %i\n", x, y);
  return 0;
}
