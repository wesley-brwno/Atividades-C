#include <stdio.h>
#include <stdlib.h>

float apresentarPorcentagem(int aprovados, int reprovados, int qtdAlunos);
int main(void) {
  int qtdAlunos, aprovados, reprovados;
  printf("Digite a quantidade de alunos matriculados: \n");
  scanf("%i", &qtdAlunos);
  printf("Digite a quantidade de alunos aprovados: \n");
  scanf("%i", &aprovados);
  printf("Digite a quantidade de alunos reprovados: \n");
  scanf("%i", &reprovados);
  apresentarPorcentagem(aprovados, reprovados, qtdAlunos);
  return 0;
}

float apresentarPorcentagem(int aprovados, int reprovados, int qtdAlunos){
  float operacao;
  operacao = (aprovados*100)/qtdAlunos;
  printf("Aprovados = %.2f %%\n",operacao);
  operacao = (reprovados*100)/qtdAlunos;
  printf("Rerovados = %.2f %%\n",operacao);
}
