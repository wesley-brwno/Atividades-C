


#include <stdio.h>

struct contato {
  char nome[10], endereco[30], telefone[15];
};

void cadastrar(struct contato *listaContatos);
void imprimir(struct contato *listaContatos);

int main (){

  struct contato listaContatos[3];
  struct contato contatoUnico;
  cadastrar(listaContatos);
  imprimir(listaContatos);

}
/*
  struct contato cadastrarUnico (struct contatoUnico){
    fgets(contatoUnico.nome,10,stdin);
    fgets(contatoUnico.endereco,30,stdin);
    fgets(contatoUnico.telefone,15,stdin);

    return contatoUnico;
  }
*/


  void cadastrar(struct contato *listaContatos){
    int i;
    for(i=0; i<3; i++){
      printf("Digite o nome: ");
      fgets(listaContatos[i].nome,10,stdin);
      printf("Digite o endereco: ");
      fgets(listaContatos[i].endereco,10,stdin);
      printf("Digite o telefone: ");
      fgets(listaContatos[i].telefone,10,stdin);
    }
  }

  void imprimir(struct contato *listaContatos){
    int i;
    for(i=0; i<3; i++){
      printf("Nome: %s\nEndereco: %s\nTelefone: %s\n", listaContatos[i].nome,listaContatos[i].endereco,
      listaContatos[i].telefone);
    }
  }
