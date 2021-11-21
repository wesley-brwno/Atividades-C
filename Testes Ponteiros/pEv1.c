#include <stdio.h>

int main(void) {

  int vetor[3] = {1,2,3};

  int *ponteiro = &vetor[0];

  //++ponteiro;
  *(ponteiro + 1) = 10;

  printf("%i\n", vetor[1]);



  return 0;
}
