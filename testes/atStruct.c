#include <stdio.h>
#include <stdlib.h>

struct dadosUsr{
  char nome[10], estadoCivil[10], identidade[10], sexo[10];
  int cpf, salario, idade;
};
struct endereco {
  char rua[10], bairro[10], cidade[10];
};

int main(struct dadosUsr info, struct endereco end) {
  printf("Digite o nome:\n");
  fflush(stdin);
  gets(info.nome);
  printf("Digite o estado civil:\n");
  fflush(stdin);
  gets(info.estadoCivil);
  printf("Digite a identidade:\n");
  fflush(stdin);
  gets(info.identidade);
  printf("Digite o sexo:\n");
  gets(info.sexo);
  printf("Digite o cpf:\n");
  scanf("%i", &info.cpf);
  printf("Digite o salario:\n");
  scanf("%i", &info.salario);
  printf("Digite a idade:\n");
  scanf("%i", &info.idade);

  printf("Digite a rua:\n");
  gets(end.rua);
  printf("Digite o bairro:\n");
  gets(end.bairro);
  printf("Digite a cidade:\n");
  gets(end.cidade);

  printf("Nome: %s\n", info.nome);

  return 0;
}
