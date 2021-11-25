#include <stdio.h>

struct contato{
  char nome[10], endereco[30], telefone[15];
};

int main() {
  struct contato listaContatos[3];
  int i;

  for (i=0; i<3; i++){
    printf("Digite o nome: \n");
    fgets(listaContatos[i].nome,10,stdin);
    printf("Digite o endereco: \n");
    fgets(listaContatos[i].endereco,30,stdin);
    printf("Digite o telefone: \n");
    fgets(listaContatos[i].telefone,15,stdin);
  }

  for (i=0; i<3; i++){
    printf("Nome: %s\nEndereco: %s\nTelefone: %s\n", listaContatos[i].nome,listaContatos[i].endereco,listaContatos[i].telefone);
  }
  return 0;
}
