#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct endereco{
  char estado[10];
  char cidade[10];
  char bairro[10];
};
void menu();
void adicionar();
void imprimir();
struct endereco end[3], endBackup[3];
int j;

int main() {
  int opcao, i, qtdBackup;

  do {
    menu();
    fflush(stdin);
    scanf("%i", &opcao);
    system("cls");

    switch (opcao) {
      case 1:
      fflush(stdin);
      adicionar();
      break;
      case 2:
      imprimir();
      break;
      case 3:
      endBackup[j]=end[j];
      qtdBackup=j;
      break;
      case 4:
      end[qtdBackup]=end[qtdBackup];
      j=qtdBackup;
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

void adicionar() {
  printf("Estado: \n");
  fflush(stdin);
  gets(end[j].estado);
  printf("cidade: \n");
  gets(end[j].cidade);
  printf("bairro: \n");
  gets(end[j].bairro);
  system("cls");
  j++;

}

void imprimir(){
  int i;
  for(i=0; i < j; i++){
    printf("Vetor %i\n", i);
    printf("%s\n", end[i].estado);
    printf("%s\n", end[i].cidade);
    printf("%s\n\n", end[i].bairro);
  }
}
