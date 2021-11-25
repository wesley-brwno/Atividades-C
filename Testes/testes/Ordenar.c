#include <stdio.h>
int main (void){
  int i, num[5], aux, contador;

  for (i=0; i<5; i++){
    printf("Entre com numeros :");
    scanf("%i", &num[i]);
  }

  for (contador = 1; contador <5; contador++){
    for (i = 0; i < 5 - 1; i++){
      if (num[i] > num[i+1]){
        aux = num[i];
        num[i] = num[i+1];
        num[i+1] = aux;
      }
    }
  }
  for (i=0;i<5;i++){
    printf("%i\n", num[i]);
  }
  return 0;
}
