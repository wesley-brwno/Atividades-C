#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct endereco{
  char estado[10];
  char cidade[10];
  char bairro[10];
};
void menu();
struct endereco adicionar(struct endereco *end);
void imprimir(struct endereco *end);

int j;

int main() {
  int opcao, i, qtdBackup;
  struct endereco end[3], endBackup[3];

  do {
    menu();
    fflush(stdin);
    scanf("%i", &opcao);
    system("cls");

    switch (opcao) {
      case 1:
      fflush(stdin);
      end[j]=adicionar(&end);
      break;
      case 2:
      imprimir(&end);
      break;
      case 3:
      qtdBackup=j;
      for(i=0; i < j; i++){
        endBackup[i]=end[i];
      }
      break;
      case 4:
      for(i=0; i < qtdBackup; i++){
        end[i]=endBackup[i];
      }

      break;
    }
  } while(opcao!=9);

  return 0;
}

void menu(){
  printf("1 adicionar\n");
  printf("2 Imprimir\n");
  printf("3 backup\n");
  printf("4 restaurar\n");
}

struct endereco adicionar(struct endereco *end){
  printf("Estado: \n");
  fflush(stdin);
  gets(end->estado);
  printf("cidade: \n");
  gets(end->cidade);
  printf("bairro: \n");
  gets(end->bairro);
  system("cls");
  j++;
  return *end;
}

void imprimir(struct endereco *end){
  int i;
  for(i=0; i < j; i++){
    printf("Vetor %i\n", i);
    printf("%s\n", end[i].estado);
    printf("%s\n", end[i].cidade);
    printf("%s\n\n", end[i].bairro);
  }
}
