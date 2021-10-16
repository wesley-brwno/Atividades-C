// Sintese
// Objetivo: Receber notas de alunos;
// Entrada: quantidade de alunos e notas;
// Saída:
#include <stdio.h>
int main (void){
  float vetor[50];
  int i, alunos;

  printf("Digite a quantidade de alunos:\n");
  scanf("%i", &alunos);

  for (i = 0; i < alunos; i++){
    printf("Digite a nota do aluno %i:\n",i+1);
    scanf("%f", &vetor[i]);
  }

  return 0;
}
