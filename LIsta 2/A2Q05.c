#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  void ClassificaodaOP(int hbts, char nome[10]);
  char* continuar(char*sair);
  char nome[10], sair[4];
  int habitantes;

  do{
    printf("Digite o nome da organizacao populacional: \n");
    fflush(stdin);
    gets(nome);
    printf("Digite o numero de habitantes: \n");
    scanf("%i", &habitantes);
    system("cls");
    ClassificaodaOP(habitantes,nome);
    strcpy(sair,continuar(sair));
  }while(stricmp(sair,"nao")!=0);
  return 0;
}

void ClassificaodaOP(int hbts, char nome[10]){
  printf("%s recebe a classifacao de ", nome);
  if (hbts > 0 && hbts <= 500)
    printf("VILA\n");
  if (hbts > 500 && hbts <= 1500)
    printf("DISTRITO\n");
  if (hbts > 1500 && hbts <= 1000000)
    printf("CIDADE\n");
  if (hbts > 1000000)
    printf("METROPOLE\n");
}

char* continuar(char*sair){
  printf("\nDeseja continuar?(Sim ou Nao)\n");
  fflush(stdin);
  gets (sair);
  system("cls");
  return sair;
}
