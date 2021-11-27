#include <stdio.h>
#include <stdlib.h>

struct endereco {
  char cidade[10], bairro[10], casa[10];
};

struct cadastro {
  int id;
  char nome[30], email[30], sexo[12];
  double altura;
  _Bool vacina;
  struct endereco end;
};

struct no {
  struct cadastro cad;
  struct no *prox;
};

void Menu();
void incluir (struct no *novo, struct no **lista);
void imprimir (struct no *imprimir);
void editar (struct no **lista);

int main() {
  int opcao;
  struct no *novo, *lista=NULL;

  do {
    Menu();
    scanf("%i", &opcao);
    system("cls");
    switch (opcao) {
      case 1:
        incluir(novo, &lista);
      break;
      case 2:
        editar(&lista);
      break;
      case 5:
        imprimir(lista);
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

void incluir (struct no *novo, struct no **lista){
  novo = malloc(sizeof(struct no));
  novo->cad.id = rand() % 1000;
  printf("Digite o nome: ");
  fflush(stdin);
  gets(novo->cad.nome);
  printf("Digite o email: ");
  fflush(stdin);
  gets(novo->cad.email);
  novo -> prox = *lista;
  *lista = novo;
}

void imprimir (struct no *imprimir){
  struct no *aux = imprimir;

  while (aux != NULL) {
    printf("         Usuario: %i\n", aux->cad.id);
    printf("         Nome: %s\n",aux->cad.nome);
    printf("         Email: %s\n", aux->cad.email);
  /*  printf("         Sexo: %s\n", cad[i].sexo);
    printf("         Estado: %s\n",cad[i].end.estado);
    printf("         Cidade: %s\n",cad[i].end.cidade);
    printf("         Rua: %s\n",cad[i].end.rua);
    printf("         CEP: %s\n",cad[i].end.cep);
    printf("         Altura: %.2f\n",cad[i].altura);
    printf("         Vacinado: \n\n");*/
    printf("--------------------------------------------\n");
    aux = aux->prox;
  }
}

void editar (struct no **lista){
  struct no *aux = *lista;
  int id;
  printf("Digite o ID: ");
  scanf("%i", &id);

  while (aux != NULL) {
    if(aux->cad.id == id){
      printf("Digite o nome: ");
      fflush(stdin);
      gets(aux->cad.nome);
      printf("Digite o email: ");
      fflush(stdin);
      gets(aux->cad.email);
      *lista=aux;
    }
    else{
      if(aux==NULL)
        printf("ID nao encontrado! \n");
    }


    aux = aux->prox;
  }
}
