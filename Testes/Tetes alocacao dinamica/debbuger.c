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

  novo = malloc(sizeof(struct tNo));
  novo->dado.codigo = 1;

  novo = malloc(sizeof(struct tNo));
  novo->dado.codigo = 1;
  incluir(&produtos, novo);

  listar(produtos);

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
