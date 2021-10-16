#include <stdio.h>
#include <stdbool.h>
int main() {
char texto[]="abc", mensagem[5];
int comparacao;
  printf("Digite uma palavra\n");
  gets(mensagem);
  comparacao=strcmp(texto,mensagem)==0;
  printf("%i",comparacao);
  return 0;
}
