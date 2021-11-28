// Sintese
// Objetivo : Converter unidades de medidas;
// Entrada : Peso em quilos;
// Saída : Peso em gramas e toneladas;
#include <stdio.h>

float leValidaPeso(float peso){
  printf("Digite o peso: ");
  scanf("%f", &peso);
  return peso;
}

void apresentaGrama(float peso){
  peso=(peso*1000);
  printf("Peso em gramas: %.2f\n", peso);
}

void apresentaTonelada(float peso){
  peso=(peso/1000);
  printf("Peso em toneladas: %f\n", peso);
}

int main(void) {
  float peso;

  peso=leValidaPeso(peso);
  apresentaGrama(peso);
  apresentaTonelada(peso);

  return 0;
}
