#include<stdio.h>



struct contato {
    char nome[30], endereco[50], telefone[11];
};



void preencherLista(struct contato *lista);
void imprimirLista(struct contato *lista);



int main(){
    struct contato lista[3];

    preencherLista(lista);
    imprimirLista(lista);
}



void preencherLista(struct contato *lista){
    int i;
    for (i=0;i<3;i++){
      printf("Digite o nome: \n");
      fgets(lista[i].nome,10,stdin);
      printf("Digite o endereco: \n");
      fgets(listaContatos[i].endereco,30,stdin);
      printf("Digite o telefone: \n");
      fgets(listaContatos[i].telefone,15,stdin);
    }
}



void imprimirLista(struct contato *lista){
    int i;
    for (i=0;i<3;i++)
        printf("Nome: %s. Endereco: %s. Telefone: %s\n",lista[i].nome, lista[i].endereco, lista[i].telefone);
}
