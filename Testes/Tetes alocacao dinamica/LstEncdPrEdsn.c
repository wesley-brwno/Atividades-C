#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tProduto{
  int codigo;
  char descricao[30];
  float valor;
};

struct tNo{
  struct tProduto dado;
  struct tNo *prox;
};

int menu(void);
void incluir(struct tNo **lst, struct tNo *n); // Ponteiro sendo passado por referencia
void listar(struct tNo *); // Nao é necesario declarar struct +-
void destruir(struct tNo **lst);
struct tNo *consultar(struct tNo *, int);

int main(void){
  int opcao, codigo, i, achei;
  struct tNo *novo, *p, *q, *produtos=NULL;

  do {
    opcao = menu();
    switch (opcao) {
      case 1:
        printf("\n*** Inclusao ***\n\n");
        novo = malloc(sizeof(struct tNo));
        printf("Digite o codigo...: ");
        scanf("%d", &((*novo).dado.codigo));
        printf("Digite a descricao: ");
        fflush(stdin);
        gets(((*novo).dado.descricao));
        printf("Digite o valor...: ");
        scanf("%f", &((*novo).dado.valor));

        incluir(&produtos, novo); // & para passagem por referencia;

      break;
      case 2:
        listar(produtos);
      break;
      case 3:
        printf("\n\n*** Consulta ***\n\n");
        printf("Digite o codigo...: ");
        scanf("%i", &codigo);

        p = consultar(produtos, codigo);
        if (p != NULL)
          printf("%d - %s - %.2f\n", (*p).dado.codigo, (*p).dado.descricao, (*p).dado.valor);
        else
          printf("Codigo nao encontrado! \n");
      break;
      case 4:
        printf("\n\n*** Alteracao ***\n\n");
        printf("Digite o codigo...: ");
        scanf("%i", &codigo);

        p = consultar(produtos, codigo);
        if (p != NULL){
          printf("%d - %s - %.2f\n", (*p).dado.codigo, (*p).dado.descricao, (*p).dado.valor);

          printf("Digite o codigo...: ");
          scanf("%d", &p->dado.codigo);
          printf("Digite a descricao: ");
          fflush(stdin);
          gets(p->dado.descricao);
          printf("Digite o valor...: ");
          scanf("%f", &p->dado.valor);

        }
        else
          printf("Codigo nao encontrado! \n");
      break;
    }
  } while(opcao != 0);

  destruir(&produtos);
  return 0;
}

int menu(void){
  int op;
  printf("*** menu *** \n\n");
  printf("1. Inclusao\n");
  printf("2. Listagem\n");
  printf("3. Consulta\n");
  printf("4. Alteracao\n");
  printf("0. Sair\n\n");
  printf("Escolha sua opcao: ");
  scanf("%d", &op);
  return op;
}

void incluir (struct tNo **lst, struct tNo *n){
  n->prox = *lst; // (*lst) pois é referencia;
  *lst = n;
}

void listar(struct tNo *imprimir){
  struct tNo *p=imprimir; // Sem * pois é por valor;
  printf("\n\n*** Listagem ***\n\n");
  while (p != NULL) {
    printf("%d - %s - %.2f\n", (*p).dado.codigo, (*p).dado.descricao, (*p).dado.valor);
    p = (*p).prox;
  }
}

void destruir(struct tNo **lst){
  struct tNo *q, *p = *lst; //(*lst) passagem por referencia
  while (p != NULL) {
    q = p;
    p = p->prox;
    free(q);
  }
}

struct tNo *consultar (struct tNo *lst, int cod){
  struct tNo *p = lst;
  while (p != NULL) {
    if(p->dado.codigo == cod)
      return p;
    p = p->prox;
  }
  return NULL;
}
