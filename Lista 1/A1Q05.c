// Sintese
// Objetivo: Verificar se há elementos iguais;
// Entrada: 80 números do vetor e um número para verificar se há outros iguais no vetor;
// Saída: Quantidade de números iguais e posições;
#include <stdio.h>
int main(void) {
  int vetor[10],i,verificar,iguais=0,posicao[10];

  for ( i = 0; i < 8; i++) {
    printf("Posicao %i: ", i);
    scanf("%i", &vetor[i]);
  }
  printf("=====\n");
  scanf("%i", &verificar);
    printf("=====\n");
  for (i = 0; i < 8; i++) {
    if (verificar == vetor[i]) {
      iguais = iguais + 1;
    }
  }

  printf("Elementos iguais %i\nPosicoes", iguais);
  for (i = 0; i < 8; i++) {
    if (verificar == vetor[i]) {
      posicao[i] = i;
      printf("%i ", posicao[i]);
    }
  }

  return 0;
}
