#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
  int valido=0, i=1, id=1;
  char opcaoEscolhida;
  char nome[60][1000], email[60][1000], sexo[60][1000];

  void exibirMenuTela();

  do {
    exibirMenuTela();
    scanf("%c", &opcaoEscolhida);
    system("cls");
    switch (opcaoEscolhida){
      case '1':

      printf("Seu ID e %d\n", id);

      //Nome
      printf("Digite seu nome: \n");
      fflush(stdin);
      fgets(nome[i], 60, stdin);

      //Email
      printf("Digite seu e-mail: \n");
      fflush(stdin);
      fgets(email[i], 60, stdin);

      //Sexo
      printf("Digite o seu sexo (masculino, feminino ou nao declarar): \n");
      fflush(stdin);
      fgets(sexo[i], 15, stdin);
      i++;
      system("cls");
      break;
      case '2':
        printf("ola %s\n", nome[1]);
        scanf("%s\n", nome);
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      break;

    }

  } while(valido < 3);
  return 0;
}

void exibirMenuTela(){
  printf("Selecione uma opcao: \n");
  printf("\t1 -> inclua um usuario por vez (MAXIMO 1000); \n");
  printf("\t2 -> edite um usuario; \n");
  printf("\t3 -> exclua um usuario; \n");
  printf("\t4 -> busque um usuario pelo id; \n");
  printf("\t5 -> busque um usuario pelo email; \n");
  printf("\t6 -> imprimir todos os usuarios cadastrados; \n");
  printf("\t7 -> fazer backup dos usuarios cadastrados; \n");
  printf("\t8 -> fazer restauracao de dados; \n\n");
}
