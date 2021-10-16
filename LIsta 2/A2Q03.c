#include <stdio.h>
#include <stdlib.h>
int main(void) {
  float mediaAritimetica(float x, float y);
  float mediaPonderada(float x, float y);
  float mediaPonderada2(float x, float y);
  float nota1, nota2, qtd;

  do {
    printf("Digite a primeira nota: ou numero negativo para parar ");
    scanf("%f", &nota1);
    if (nota1 < 0){
      break;
    }
    else{
      printf("Digite a segunda nota: ");
      scanf("%f", &nota2);
      system ("cls");
      mediaAritimetica(nota1,nota2);
      mediaPonderada(nota1,nota2);
      mediaPonderada2(nota1,nota2);
      qtd++;
    }
  } while((nota1 >= 0) && (qtd < 21));

  return 0;
}
float mediaAritimetica(float x, float y){
  float media = ((x+y)/2);
  printf("%.2f\n", media);
}
float mediaPonderada(float x, float y){
  float media = ((x*0.4) + (y*0.6));
  printf("%.2f\n", media);
}
float mediaPonderada2(float x, float y){
  float media = ((x*0.3) + (y*0.7));
  printf("%.2f\n\n", media);
}
