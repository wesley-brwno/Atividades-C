// Operador sizeof
#include <stdio.h>

struct x {
  int a,c;
  double b;
};

int main() {
  struct x estrutura;

  int vetor[10];

  printf("%i", sizeof(estrutura));


  return 0;
}
