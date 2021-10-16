#include <stdio.h>
#include <stdlib.h>
int main (void){
  float calcularPoten(float x, int n);
  float x, potencia;
  int n;

  printf("Digite um numero real: ");
  scanf("%f", &x);
  printf("Digite um numero inteiro: ");
  scanf("%i", &n);
  system ("cls");
  potencia = calcularPoten(x,n);
  return 0;
}
float calcularPoten(float real, int inteiro){
  float potencia=1;
  int i;

  for(i = 0; i < inteiro; i++){
    potencia = (potencia * real);
  }
  printf("%.2f elavado a %i = %.2f ", real, inteiro, potencia);
  return (potencia);
}
