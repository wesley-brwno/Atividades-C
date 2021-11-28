#include <stdio.h>

void ordenar(float *peso){
  float aux;
  for (int i=0; i<2; i++){
    for(int k=0; k<2; k++){
      if (peso[k]>peso[k+1]) {
        aux=peso[k];
        peso[k]=peso[k+1];
        peso[k+1]=aux;
      }
    }
  }
}

int main(void) {
  float peso[3];
  int i;
  for(i=0; i<3; i++){
    printf("Digite o peso %i:\n", i+1);
    scanf("%f", &peso[i]);
  }
  ordenar(peso);
  for(i=0; i<3; i++){
    printf("Peso: %.2f Kg \n", peso[i]);
  }
  return 0;
}
