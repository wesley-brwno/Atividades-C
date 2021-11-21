#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// faltam 7, 8 e as validacoes

struct endereco {
  char estado[30], cidade[30], rua[30], cep[30];
};

struct cadastro{
  char nome[30], email[15], sexo[15];
  double altura;
  int id, vacina;
  struct endereco end;
};

void Menu();
struct cadastro incluirUsuario(struct cadastro *incluir);
void imprimir(struct cadastro *cad);
void buscarEmail(struct cadastro *cad);
void BuscarID(struct cadastro *cad);
void editar(struct cadastro *cad);
void Excluir(struct cadastro *cad);
char* validarSexo(char*sexoValido);
void substituirExcluido(struct cadastro *incluir);

int j=0;

int main() {
  struct cadastro cad[10], cad_backup[10];
  int opcao, qtdCadastros_backup, qtdCadastros=0;

  do {
    Menu();
    fflush(stdin);
    scanf("%i", &opcao);
    system("cls");

    switch (opcao) {
    case 1:
    if (cad[0].id<0){
      substituirExcluido(cad);
    }
    else{
      cad[j]=incluirUsuario(cad);
      j++;
    }
    break;
    case 2:
    editar(cad);
    break;
    case 3:
    Excluir(cad);
    break;
    case 4:
    BuscarID(cad);
    break;
    case 5:
    buscarEmail(cad);
    break;
    case 6:
    imprimir(cad);
    break;
    case 7:

    break;
    case 8:

    break;
    }
  } while(opcao != 9); // corrigir para menor que mil

  return 0;
}

void Menu(){
  printf(" ______________________________________\n");
  printf("|________|CADASTRO DE USUARIOS|________|\n");
  printf("|                                      |\n");
  printf("|     1-Incluir usuario;               |\n");
  printf("|                                      |\n");
  printf("|     2-Editar usuario;                |\n");
  printf("|                                      |\n");
  printf("|     3-Excluir usuario;               |\n");
  printf("|                                      |\n");
  printf("|     4-Buscar usuario pelo ID;        |\n");
  printf("|                                      |\n");
  printf("|     5-Buscar usuario pelo email;     |\n");
  printf("|                                      |\n");
  printf("|     6-Imprimir usuarios;             |\n");
  printf("|                                      |\n");
  printf("|     7-Fazer backup;                  |\n");
  printf("|                                      |\n");
  printf("|     8-Restaurar dados;               |\n");
  printf("|______________________________________|\n");
  printf("  Escolha uma opcao: ");
}

struct cadastro incluirUsuario(struct cadastro *incluir){
  char repetir, tamanhoEmail[30], vacinado[5];

  if(incluir[0].id<0){
    incluir[0].id=incluir[0].id*(-1);
  }
  else{
  incluir.id = rand() % 1000;
  }
  printf("Usuario: %i\n", incluir.id);
  printf("Digite o nome:\n");
  fflush(stdin);
  gets(incluir.nome);
  printf("Digite o email:\n");// adicionar Funcao para vericar...
  gets(incluir.email);
  printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n"); // adicionar Funcao para vericar...
  fflush(stdin);
  gets(incluir.sexo);
  printf("Digite o estado:\n");
  fflush(stdin);
  gets(incluir.end.estado);
  printf("Digite a cidade:\n");
  fflush(stdin);
  gets(incluir.end.cidade);
  printf("Digite a rua:\n");
  fflush(stdin);
  gets(incluir.end.rua);
  printf("Digite o cep:\n");
  fflush(stdin);
  gets(incluir.end.cep);
  printf("Digite a altura:\n"); // adicionar Funcao para vericar...
  scanf("%lf", &incluir.altura);
  printf("Ja vacinou?(Sim ou Nao)\n");// adicionar Funcao para retornar o booliano...
  gets(vacinado);
  system("cls");
  return *incluir;
}


void imprimir(struct cadastro *cad){

  for (int i=0; i < j; i++){
    if (cad[i].id > 0) { // Nao imprimi os cadastrados excluidos
      printf("         Usuario: %i\n", cad[i].id);
      printf("         Nome: %s\n",cad[i].nome);
      printf("         Email: %s\n", cad[i].email);
      printf("         Sexo: %s\n", cad[i].sexo);
      printf("         Estado: %s\n",cad[i].end.estado);
      printf("         Cidade: %s\n",cad[i].end.cidade);
      printf("         Rua: %s\n",cad[i].end.rua);
      printf("         CEP: %s\n",cad[i].end.cep);
      printf("         Altura: %.2f\n",cad[i].altura);
      printf("         Vacinado: \n\n");
      printf("--------------------------------------------\n");
    }
  }
  system("pause");
  system("cls");
}

void buscarEmail(struct cadastro *cad) {
  char emailBusca[30],i=0;
  char repetir,sair;
  printf("Digite o email: \n");
  fflush(stdin);
  gets(emailBusca);
  do {
    if (strcmp(emailBusca,cad[i].email)==0) {
      printf("Usuario: %i\n", cad[i].id);
      printf("Nome: %s\n",cad[i].nome);
      printf("Email: %s\n", cad[i].email);
      printf("Sexo: %s\n", cad[i].sexo);
      printf("estado: %s\n",cad[i].end.estado);
      printf("estado: %s\n",cad[i].end.cidade);
      printf("estado: %s\n",cad[i].end.rua);
      printf("estado: %s\n\n",cad[i].end.cep);
      printf("Altura: %.2f\n", cad[i].altura);
      printf("Vacinou: ");
  /*    switch (cad[i].vacina) {
        case 1:
        printf("Sim\n");
        break;
        case 2:
        printf("Nao\n");
        break;
      }*/
      repetir='N';
    }
    if ((i==j)&&(repetir!='N'))
      printf("Email invalido!\n");
    i++;
  } while((repetir!='N')&&(i<=j));
  system("pause");
  system("cls");
}

void BuscarID(struct cadastro *cad){
  int esquerda, direita, meio, idBusca, qtdCadastros, k, i, id_n_encontrado;
  struct cadastro aux_cad;
  qtdCadastros=j;
  esquerda=0;
  direita=j;

  for (k = 0; k < qtdCadastros-1; k++){
    for (i = 0; i < qtdCadastros-1; i++){
      if (cad[i].id > cad[i+1].id){

        aux_cad = cad[i];
        cad[i]= cad[i+1];
        cad[i+1]= aux_cad;
      }
    }
  }

  printf("Digite o ID: \n");
  scanf("%d", &idBusca);

  while(esquerda<=direita) {
   meio=(esquerda+direita)/2;
   if(cad[meio].id==idBusca){
     id_n_encontrado=0;
     printf("Usuario: %i\n", cad[meio].id);
     printf("Nome: %s\n",cad[meio].nome);
     printf("Email: %s\n", cad[meio].email);
     printf("Sexo: %s\n", cad[meio].sexo);
     printf("Estado: %s\n",cad[meio].end.estado);
     printf("Cidade: %s\n",cad[meio].end.cidade);
     printf("Rua: %s\n",cad[meio].end.rua);
     printf("CEP: %s\n\n",cad[meio].end.cep);
     printf("Altura: %.2f\n", cad[meio].altura);
     printf("Vacinou: ");
 /*    switch (cad[meio].vacina) {
       case 1:
       printf("Sim\n");
       break;
       case 2:
       printf("Nao\n");
       break;
     }*/

     }
   if(cad[meio].id>idBusca)
     direita=meio-1;
   else
     esquerda=meio+1;
 }

 if (id_n_encontrado!=0)
  printf("ID nao encotrado!\n\n");

  system("pause");
  system("cls");
}

void editar(struct cadastro *cad){
  int idBusca,i;
  char vacinado[5];
  printf("Digite o Id\n");
  scanf("%i", &idBusca);
  for (i = 0; i < j; i++) {
    if (idBusca == cad[i].id) {
      printf("Digite o nome:\n");
      fflush(stdin);
      gets(cad[i].nome);
      printf("Digite o email:\n");// adicionar Funcao para vericar...
      gets(cad[i].email);
      printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n"); // adicionar Funcao para vericar...
      fflush(stdin);
      gets(cad[i].sexo);
      printf("Digite o estado:\n");
      fflush(stdin);
      gets(cad[i].end.estado);
      printf("Digite a cidade:\n");
      fflush(stdin);
      gets(cad[i].end.cidade);
      printf("Digite a rua:\n");
      fflush(stdin);
      gets(cad[i].end.rua);
      printf("Digite o cep:\n");
      fflush(stdin);
      gets(cad[i].end.cep);
      printf("Digite a altura:\n"); // adicionar Funcao para vericar...
      scanf("%lf", &cad[i].altura);
      printf("Ja vacinou?(Sim ou Nao)\n\n");// adicionar Funcao para retornar o booliano...
      gets(vacinado);
      i=j;
    }
  }
  system("pause");
  system("cls");
}

void Excluir(struct cadastro *cad){
  int idBusca, l=0, qtdCadastros, k, i, aux;
  char auxS[10], msg_n_encontrado;
  struct cadastro aux_cad;
  qtdCadastros=j;

  printf("Digite o Id\n");
  fflush(stdin);
  scanf("%i", &idBusca);

  do {
    if (idBusca==cad[l].id) {
      cad[l].id = (cad[l].id * (-1)); // O ID ficará com numero negativo e vai ser alocado nos primeiros indices do vetor
      strcpy(cad[l].email,"Email excluido");
      msg_n_encontrado = 'n';

      for (k = 0; k < qtdCadastros-1; k++){
        for (i = 0; i < qtdCadastros-1; i++){
          if (cad[i].id > cad[i+1].id){

            aux_cad = cad[i];
            cad[i]= cad[i+1];
            cad[i+1]= aux_cad;

          }
        }
      }
    }
  l++;
} while(l <= qtdCadastros || idBusca == cad[l].id);

  switch (msg_n_encontrado) {
    case 'n':
    break;
    default:
    printf("ID Invalido! \n\n");
  }
  msg_n_encontrado='s';
  system("pause");
  system("cls");
}

char* validarSexo(char*sexoValido){
  char repetir;
  do {
    printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n");
    fflush(stdin);
    gets(sexoValido);
    if ((stricmp(sexoValido,"Feminino")==0) || (stricmp(sexoValido,"Masculino")==0) || (stricmp(sexoValido,"Nao declarar")==0))
      break;
    else{
      printf("Sexo Incorreto!!\n");
        repetir='S';
    }
  } while(repetir=='S');
  return sexoValido;
}
