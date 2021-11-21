#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// faltam 2,3,4,5 e as validacoes, altura, id
struct endereco {
  char estado[10], cidade[10], rua[10], cep[10];
};

struct cadastro{
  char nome[30], email[15], sexo[15];
  double altura;
  int id, vacina;
  struct endereco end;
};

struct cadastro cad[10], cadBackup[10];
void Menu();
void incluirUsuario();
void imprimir();

int j=0;

int main() {
  int opcao, sair, qtdCadastros;

  do {
    Menu();
    fflush(stdin);
    scanf("%i", &opcao);
    system("cls");

    switch (opcao) {
    case 1:
    incluirUsuario();
    break;
    case 2:

    break;
    case 3:

    break;
    case 4:

    break;
    case 5:

    break;
    case 6:
    imprimir();
    break;
    case 7:
    for (int i = 0; i < j; i++) {
      cadBackup[i]=cad[i];
    }
    qtdCadastros=j;
    break;
    case 8:
    for (int i = 0; i < qtdCadastros; i++) {
      cad[i]=cadBackup[i];
    }

    j=qtdCadastros;

    break;
    }
  } while(opcao != 9);

  return 0;
}

void Menu(){
  printf("1-Incluir usuario;\n");
  printf("2-Editar usuario;\n");
  printf("3-Excluir usuario;\n");
  printf("4-Buscar usuario pelo ID;\n");
  printf("5-Buscar usuario pelo email;\n");
  printf("6-Imprimir todos usuarios;\n");
  printf("7-Fazer backup de usuarios cadastrados;\n");
  printf("8-Restaurar dados;\n");
  printf("\nEscolha uma opcao:\n ");
}

void incluirUsuario(){
  char repetir, tamanhoEmail[30];
  printf("Digite o nome:\n");
  fflush(stdin);
  gets(cad[j].nome);
  printf("Digite o email:\n");
  gets(cad[j].email);
  printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n");
  fflush(stdin);
  gets(cad[j].sexo);
  printf("Digite o estado:\n");
  fflush(stdin);
  gets(cad[j].end.estado);
  printf("Digite a cidade:\n");
  fflush(stdin);
  gets(cad[j].end.cidade);
  printf("Digite a rua:\n");
  fflush(stdin);
  gets(cad[j].end.rua);
  printf("Digite o cep:\n");
  fflush(stdin);
  gets(cad[j].end.cep);

  system("cls");
  j++;
}

void imprimir(){
  char sair;
  int i;
  for (i=0; i<j; i++){
    printf("Nome: %s\n",cad[i].nome);
    printf("Email: %s\n", cad[i].email);
    printf("Sexo: %s\n", cad[i].sexo);
    printf("estado: %s\n",cad[i].end.estado);
    printf("estado: %s\n",cad[i].end.cidade);
    printf("estado: %s\n",cad[i].end.rua);
    printf("estado: %s\n\n",cad[i].end.cep);
  }
  printf("\n para sair Digite s");
  scanf("%c", &sair);
  system("pause");
  system("cls");
}
