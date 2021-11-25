#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int valor;
  struct No *proximo;
}No;

typedef struct{
  No *inicio;
  int tam;
}Lista;

// inserção no inicio da lista
void inserirInicio(Lista *lista, int valor){
  No *novo = (No*) malloc(sizeof(No));
  novo->valor = valor;
  novo->proximo = lista->inicio;
  lista->inicio = novo;
  lista->tam++;

}

// Inserir no finalizando
void inserirFim(Lista *lista, int valor){
  No *no, *novo =(No*) malloc(sizeof(No));
  novo->valor = valor;
  novo->proximo= NULL;

  if(lista->inicio==NULL){
    lista->inicio =novo;
  }
  else{
    no = lista->inicio;
    while(no->proximo!=NULL)
      no = no->proximo;
    no->proximo = novo;
  }
  lista->tam++;
}

// imprimir a Lista
void imprimir (Lista *lista){
  No *inicio = lista -> inicio;
  printf("Tamanho da lista: %d\n", lista->tam);
  while(inicio != NULL){
    printf("%d ", inicio->valor);
    inicio = inicio->proximo;
  }
  printf("\n\n");
}

int main (){
  Lista lista;
  int opcao, valor;

  lista.inicio = NULL;
  lista.tam = 0;

  do {
    printf("1-inseir no inicio\n2- imprimir\n3-Inserir no fim\n5-sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Digite um valor a ser inserido:");
        scanf("%d", &valor);
        inserirInicio(&lista, valor);
        break;
      case 2:
        imprimir(&lista);
        break;
      case 3:
        printf("Digite um valor a ser inserido:");
        scanf("%d", &valor);
        inserirFim(&lista, valor);
        break;
      case 5:
        printf("finalizando...\n");
        break;
      default:
        printf("Opcao invalida!\n");
    }
  } while(opcao != 5);



  return 0;
}
