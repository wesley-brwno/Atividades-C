// Sintese
// Objetivo : Apresentar media aritmetica de alturas;
// Entrada : Alturas;
// Saída : Media das alturas;
#include <stdio.h>
#include <stdlib.h>
int main (void){
  float mediaAritmetica(float x, float y);
  float altura, pessoas=0, total=0;

  do {
    printf("Digite a altura da pessoa, ou 0 para parar: ");
    scanf("%f", &altura);
    total = total + altura;
    if (altura==0)
      break;
    else
    pessoas++;
  } while((altura != 0)&&(pessoas < 5));
  mediaAritmetica(total, pessoas);
  return 0;
}
float mediaAritmetica (float altura, float pessoas){
  float media = (altura/pessoas);
  system("cls");
  printf("A media das altura e %.2f", media);
  return(media);
}
