#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct endereco {
  char estado[30], cidade[30], rua[30], cep[30];
};

struct cadastro{
  char nome[30], email[30], sexo[15];
  double altura;
  int id;
  _Bool vacina;
  struct endereco end;
};

struct no{
  struct cadastro cad;
  struct no *prox;
};

void Menu();
void incluir(struct no **lista, struct no *novo);
void imprimir (struct no *imprimir);
struct no *editar(struct no *lista);
void buscarID (struct no *imprimir);
void fazerBackup (struct no *lista, struct no **backup, struct no *novo);
void restaurar (struct no *backup, struct no **lista, struct no *novo);
void excluir(struct no **lista, struct no *vitima);



int main(void) {
  int opcao;
  struct no *novo, *edicao, *exclusao, *lista=NULL, *backup=NULL;

  do {
    Menu();
    fflush(stdin);
    scanf("%d", &opcao);
    system("cls");
    switch (opcao) {
      case 1:
        incluir(&lista, novo);
      break;
      case 2:
        edicao=editar(lista);
        if(edicao != NULL){
          printf("Digite o nome: ");
          fflush(stdin);
          gets(edicao->cad.nome);
          printf("Digite o email: ");
          fflush(stdin);
          gets(edicao->cad.email);
        }
      break;
      case 3:
        exclusao=editar(lista);
        if(exclusao != NULL){
          excluir(&lista, exclusao);
        }
      break;
      case 4:
        buscarID(lista);
        break;
      case 5:
        imprimir(lista);
      break;
      case 6:
        fazerBackup(lista, &backup, novo);

      break;
      case 7:
  //      restaurar(backup, &lista, novo);
      break;



    }
  } while(opcao != 8);

  return 0;
}


void Menu(){
  printf(" ______________________________________\n");
  printf("|________|CADASTRO DE USUARIOS|________|\n");
  printf("|                                      |\n");
  printf("|     1-Incluir usuario;               |\n");
  printf("|                                      |\n");
  printf("|     2-Editar usuario;                |\n");
  printf("|                                      |\n");
  printf("|     3-Excluir usuario;               |\n");
  printf("|                                      |\n");
  printf("|     4-Buscar usuario pelo ID;        |\n");
  printf("|                                      |\n");
  printf("|     5-Imprimir usuarios;             |\n");
  printf("|                                      |\n");
  printf("|     6-Fazer backup;                  |\n");
  printf("|                                      |\n");
  printf("|     7-Restaurar dados;               |\n");
  printf("|                                      |\n");
  printf("|     8-Sair                           |\n");
  printf("|______________________________________|\n");
  printf("  Escolha uma opcao: ");
}

void incluir(struct no **lista, struct no *novo){

  novo = malloc (sizeof (struct no));
  novo->cad.id = rand() % 1000;
  printf("Usuario: %i\n", novo->cad.id);
  printf("Digite o nome:\n");
  fflush(stdin);
  gets(novo->cad.nome);
  printf("Digite o email:\n");
  fflush(stdin);
  gets(novo->cad.email);
  printf("Digite o sexo:\n");
  fflush(stdin);
  gets(novo->cad.sexo);

  novo->prox = *lista;
  *lista = novo;
  system("pause");
}

void imprimir (struct no *imprimir){
  struct no *aux=imprimir;
  while (aux != NULL) {
    printf("         Usuario: %i\n", aux->cad.id);
    printf("         Nome: %s\n",aux->cad.nome);
    printf("         Email: %s\n", aux->cad.email);
    printf("         Sexo: %s\n", aux->cad.sexo);
    printf("\n--------------------------------------------\n");

    aux = aux->prox;
  }
  system("pause");
  system("cls");
}

void buscarID (struct no *imprimir){
  struct no *aux=imprimir;
  int id;
  printf("Digite o id: ");
  scanf("%i", &id);
  while (aux != NULL) {
    if (aux->cad.id==id) {
      printf("         Usuario: %i\n", aux->cad.id);
      printf("         Nome: %s\n",aux->cad.nome);
      printf("         Email: %s\n", aux->cad.email);
      printf("         Sexo: %s\n", aux->cad.sexo);
      printf("\n--------------------------------------------\n");
    }
    aux = aux->prox;
  }
}

struct no *editar(struct no *lista){
  int id;
  struct no *p = lista;
  printf("Digite o ID: ");
  scanf("%i", &id);
  while (p != NULL) {
    if(p->cad.id == id)
      return p;
    p = p->prox;
  }
  return NULL;
}

void excluir(struct no **lista, struct no *vitima){
  struct no *p = *lista;
  if (*lista==vitima){
    *lista= vitima->prox;
  }
  else{
    while(p->prox !=vitima){
    p = p->prox;
  }
    p->prox = vitima->prox;
  }
  free(vitima);
}

void fazerBackup (struct no *lista, struct no **backup, struct no *novo){
  struct no *aux=lista;

  while (aux != NULL) {
    novo = (struct no*) malloc (sizeof (struct no));
    *novo = *aux;
    novo->prox = *backup;
    *backup = novo;

    printf("novo         Usuario: %i\n", novo->cad.id);
    printf("         Nome: %s\n",novo->cad.nome);
    printf("         Email: %s\n", novo->cad.email);
    printf("         Sexo: %s\n", novo->cad.sexo);
    printf("\n--------------------------------------------\n");

    aux = aux->prox;
  }
  system("pause");
  system("cls");
}
