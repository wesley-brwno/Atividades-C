#include <stdio.h>
#include <stdlib.h>


struct produtos{
  char nome[10];
  float preco;
  int baixas;
};

int main (void){
  struct produtos prod[4][6];

  for( int i=0; i<1; i++){
    for (int j=0; j<6; j++){
      switch (j) {
        case 0: printf("Segunda |");break;
        case 1: printf("Terca   |");break;
        case 2: printf("Quarta  |");break;
        case 3: printf("Quinta  |");break;
        case 4: printf("Sexta   |");break;
        case 5: printf("Sabado  |");break;
      }
      printf("\n Digite o produto: ");
      fflush(stdin);
      gets(prod[i][j].nome);
      printf(" Digite o preco: ");
      scanf("%f", &prod[i][j].preco);
      printf(" Digite as baixas: ");
      scanf("%i", &prod[i][j].baixas);
    }
  }
  for( int i=0; i<1; i++){
    for (int j=0; j<6; j++){
      printf("%s\n%.2f\n%i\t", prod[i][j].nome, prod[i][j].preco, prod[i][j].baixas);

    }
  }

  return 0;
}
