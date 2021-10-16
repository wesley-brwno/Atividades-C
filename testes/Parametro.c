#include <stdio.h>
int main(void){
  void soma10p(int *x);
  void soma10(int x);


  int numero;
  printf("Digite um numero\n");
  scanf("%d", &numero);

  printf("O numero digitado foi: %d\n", numero);
  soma10(numero);
  printf("Agora o numero vale: %d\n", numero);

  soma10p(&numero);
  printf("Agora o numero vale: %d\n", numero);
  return 0;
}
void soma10(int x){
  x=x+10;
  printf("%d na funcao\n", x);
  return;
}

void soma10p(int *x){
  *x = *x + 10;
  printf("%d na funcao por parametro\n", *x);
  return;
}
