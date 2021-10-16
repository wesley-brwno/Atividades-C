#include <stdio.h>



int main(void){
  int esquerda, direita, meio, busca;
  int i;
  int vetor[10];
  for(i=0; i<10; i++){
    printf("valor %i\n", i);
    scanf("%i", &vetor[i]);
  }
  esquerda=0;
  direita=9;
  printf("Digite o valor para busca");
  scanf("%i", &busca);
   do {
    meio=(esquerda+direita)/2;

    if(vetor[meio]==busca){
      printf("Valor encontrado %i no vetor %i", vetor[meio], meio);
    }
    if(vetor[meio]>busca){
      direita=meio-1;
    }
    else{
      esquerda=meio+1;
    }
  }while (esquerda<=direita);
  return 0;
}
