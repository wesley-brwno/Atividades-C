/*2. Criar  um  registro  chamado  DadosAluno
  que armazene o  nome e  idade  de  um aluno.
  Na função main: criar uma variável que é uma estrutura DadosAluno;
  ler o nome e a idade de um aluno e armazenar na variável criada;
  exibir na tela o nome do aluno e a idade do aluno*/

  #include <stdio.h>
  #include <stdlib.h>

  struct DadosAluno {
    char nome[20];
    int idade;
  };

  int main() {
    struct DadosAluno dados;
    printf("Digite o nome do aluno: \n");
    gets(dados.nome);
    printf("Digite a idade do aluno: \n");
    scanf("%i", &dados.idade);
    system("cls");
    printf("Nome do aluno: %s\nIdade do aluno: %i", dados.nome, dados.idade);
    return 0;
  }
