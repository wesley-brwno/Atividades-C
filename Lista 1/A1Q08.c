// Sintese
// Objetivo: Identificar maior idade;
// Entrada: Idades;
// Saída: Maior idade e posições onde se encontra;
#include <stdio.h>
int main(void) {
  int idade[100],maiorIdd=0, i;
  float total=0;

  for( i = 0; i < 100; i++){
    printf("Digite a idade %i : ", i+1);
    scanf("%i", &idade[i]);
    total = total + idade[i];
    fflush(stdin);
    if(maiorIdd < idade[i]){
      maiorIdd = idade[i];
    }
  }
  printf("\nA maior idade foi: %i \n", maiorIdd);
  printf("Nas posicoes :");
  for (i = 0; i < 100; i++){
    if(idade[i] == maiorIdd)
    printf(" %i", i);
  }
  printf("\nA media foi : %.2f", (total/100));
  return 0;
}
