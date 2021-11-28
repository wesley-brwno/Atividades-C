// Sintese
// Objetivo : Apresentar media aritmetica de alturas;
// Entrada : Alturas;
// Saída : Media das alturas;
#include <stdio.h>
#include <stdlib.h>

int operacao(int a, int b, int c);
float parOuImpar(int resultado);

int main(void) {

  int valor1, valor2, valor3;
  printf("Primeiro numero: \n");
  scanf("%i", &valor1);
  printf("Segundo numero: \n");
  scanf("%i", &valor2);
  printf("Terceiro numero: \n");
  scanf("%i", &valor3);
  system("cls");
  printf("%i\n",operacao(valor1,valor2, valor3));
  if (parOuImpar(operacao(valor1,valor2,valor3))==0)
    printf("Par");
  else
    printf("Impar");
  return 0;
}

int operacao(int a, int b, int c){
  int resultado;
  resultado=(a+b*c);
  return resultado;
}

float parOuImpar(int resultado){
  float imparOuPar, verifica;
  int verifica2;
  verifica=(resultado*0.5); //verifica=(resultado/2); Nao funciona!?
  verifica2=verifica;
  imparOuPar=verifica-verifica2;
  return imparOuPar;
}
