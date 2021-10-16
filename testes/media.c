#include <stdio.h>
float calcularMedia(float valor1, float valor2, float media);
int main (void){
  float nota1,nota2,p1,p2,cont=0;

  do {
    printf("Digite as notas 1 e 2 :");
    scanf("%f%f", &nota1,&nota2);
    printf("Digite os pesos 1 e 2 :");
    scanf("%f%f", &p1,&p2);
    calcularMedia(float);
    cont++;
  } while(cont < 5);


  return 0;
}
float calcularMedia(float valor1, float valor2, float media){
  media = valor1 *(p1/10)+ valor2 (p2/10);
  printf("%f", media);
  return media;
}
