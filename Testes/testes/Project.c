#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int j=0;
char* Adicionar_editar_Usuario(char*nomeG);

int main() {
  int i;
  char nome[4], nomef[3][4];

for ( i = 0; i < 3; i++) {


  strcpy(nomef[i],Adicionar_editar_Usuario(nome));
}

  printf("%s\n",nomef[1]);
  return 0;
}
char* Adicionar_editar_Usuario(char*nomeG) {
  printf("Digite\n");
  fflush(stdin);
  fgets(nomeG,4,stdin);
  j++;
  return nomeG;
}
