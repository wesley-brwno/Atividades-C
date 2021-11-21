#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char texto[2000], tamanho;

  printf("Digite o texto: \n");
  gets(texto);
  tamanho=strlen(texto);
  texto[0]=toupper(texto[0]);
  for (int i = 1; i < tamanho; i++) {
    texto[i]=tolower(texto[i]);
  }
  printf("\n\n%s\n", texto);
  printf("\n\nO tamanho do texo = %i\n", tamanho);

  return 0;
}
