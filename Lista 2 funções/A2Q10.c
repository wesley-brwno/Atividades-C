// Sintese
// Objetivo : Calcular media de notas;
// Entrada : Duas notas;
// Saída : Media e situação(aprovado ou reprovado).
#include <stdio.h>

void situacao(float media){
  if (media>=7)
    printf("APROVADO");
  else
    printf("REPROVADO");
}

void media(float notaTeorica, float notaPratica){
  float media;
  media=((notaTeorica*3)+(notaPratica*7)/10);
  situacao(media);
}

int main (void){
  float notaTeorica, notaPratica;

  printf("Digite a nota Teorica: ");
  scanf("%f", &notaTeorica);
  printf("Digite a nota pratica: ");
  scanf("%f", &notaPratica);
  media(notaTeorica, notaPratica);
  return 0;
}
