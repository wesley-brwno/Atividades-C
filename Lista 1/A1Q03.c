// Sintese
// Objetivo: Calcular somatória de valores armazenados;
// Entrada: 100 valores;
// Saída: Somatória;
#include <stdio.h>
int main(void) {
  float dados[100],total=0;
  int i;

  for ( i = 0; i < 100; i++) {
    printf("Digite o valor %i:\n", i+1);
    scanf("%f", &dados[i]);
  }
  for ( i = 0; i < 100; i++) {
    total=total+dados[i];
  }
  printf("A somatoria e: %.2f\n", total);

  return 0;
}
