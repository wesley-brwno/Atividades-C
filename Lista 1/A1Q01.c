// Sintese
// Objetivo : Criar vetor de reais para ler notas de 30 alunos;
// Entrada : Notas;
// Saída :
#include <stdio.h>
int main (void){
  float vetor[30];
  int i;

  for (i = 0; i < 30; i++){
    printf("Digite a nota do aluno: ");
    scanf("%f", &vetor[i]);
  }
  return 0;
}
