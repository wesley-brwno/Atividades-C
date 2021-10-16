// Sintese
// Objetivo: Escrever letras em ordem invertida;
// Entrada: 30 letras;
// Saída: Letras em ordem invertida;
#include <stdio.h>
int main(void) {
  char letra[30];
  int i;

  for (i=0; i<30; i++){
    printf("Digite a letra %i\n", i+1);
    scanf("%c", &letra[i]);
    fflush(stdin);
  }
  printf("====================\n");
  for (i=29; i>=0; i--){
    printf("%c\n", letra[i]);
  }

  return 0;
}
