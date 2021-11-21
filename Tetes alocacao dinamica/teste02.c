#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int *p = malloc(5 * sizeof(int));

  for (int i = 0; i < 5; i++) {
    printf("Endereco de p%i = %p | Valor de p%i = %i\n",i, &p[i], i, *(p+i));
  }


  return 0;
}
