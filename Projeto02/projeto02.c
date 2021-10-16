#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// faltam 2,3,4 e as validacoes
// Verificar o ID
struct endereco {
  char estado[10], cidade[10], rua[10], cep[10];
};

struct cadastro{
  char nome[30], email[15], sexo[15];
  double altura;
  int id, vacina;
  struct endereco end;
};

struct cadastro cad[3], cad_Backup[3];
void Menu();
void incluirUsuario();
void imprimir();
void buscarEmail();
void BuscarID();
void editar();
void Excluir();

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
    editar();
    break;
    case 3:
    Excluir();
    break;
    case 4:
    BuscarID();
    break;
    case 5:
    buscarEmail();
    break;
    case 6:
    imprimir();
    break;
    case 7:
    cad_Backup[j]=cad[j];
    qtdCadastros=j;
    break;
    case 8:
    cad[qtdCadastros]=cad_Backup[qtdCadastros];
    j=qtdCadastros;

    break;
    }
  } while(opcao != 9); // corrigir para menor que mil

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
  char repetir, tamanhoEmail[30], vacinado[5];

  if (cad[0].id < 0) {
    cad[0].id = (cad[0].id * (-1)); // ID ficará positivo
    printf("Usuario: %i\n", cad[j].id);
    printf("Digite o nome:\n");
    fflush(stdin);
    gets(cad[0].nome);
    printf("Digite o email:\n");// adicionar Funcao para vericar...
    gets(cad[0].email);
    printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n"); // adicionar Funcao para vericar...
    fflush(stdin);
    gets(cad[0].sexo);
    printf("Digite o estado:\n");
    fflush(stdin);
    gets(cad[0].end.estado);
    printf("Digite a cidade:\n");
    fflush(stdin);
    gets(cad[0].end.cidade);
    printf("Digite a rua:\n");
    fflush(stdin);
    gets(cad[0].end.rua);
    printf("Digite o cep:\n");
    fflush(stdin);
    gets(cad[0].end.cep);
    printf("Digite a altura:\n"); // adicionar Funcao para vericar...
    scanf("%lf", &cad[0].altura);
    printf("Ja vacinou?(Sim ou Nao)\n");// adicionar Funcao para retornar o booliano...
    gets(vacinado);
    system("cls");
  }
  else{
    cad[j].id = rand() % 1000;
    printf("Usuario: %i\n", cad[j].id);
    printf("Digite o nome:\n");
    fflush(stdin);
    gets(cad[j].nome);
    printf("Digite o email:\n");// adicionar Funcao para vericar...
    gets(cad[j].email);
    printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n"); // adicionar Funcao para vericar...
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
    printf("Digite a altura:\n"); // adicionar Funcao para vericar...
    scanf("%lf", &cad[j].altura);
    printf("Ja vacinou?(Sim ou Nao)\n");// adicionar Funcao para retornar o booliano...
    gets(vacinado);
    system("cls");
    j++;
  }
}

void imprimir(){
  char sair;
  for (int i=0; i < j; i++){
    if (cad[i].id > 0) { // Nao imprimi os cadastrados excluidos
      printf("Usuario: %i\n", cad[i].id);
      printf("Nome: %s\n",cad[i].nome);
      printf("Email: %s\n", cad[i].email);
      printf("Sexo: %s\n", cad[i].sexo);
      printf("estado: %s\n",cad[i].end.estado);
      printf("estado: %s\n",cad[i].end.cidade);
      printf("estado: %s\n",cad[i].end.rua);
      printf("estado: %s\n\n",cad[i].end.cep);
    }
  }
  printf("\n para sair Digite s");
  scanf("%c", &sair);
  system("pause");
  system("cls");
}

void buscarEmail() {
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

void BuscarID(){
  int esquerda, direita, meio, idBusca, cont, j, i, aux;
  char repetir, auxS[30], limpar;
  esquerda=0;
  direita=j;
  cont=j;

  for (j = 0; j < cont-1; j++){
    for (i = 0; i < cont-1; i++){
      if (cad[i].id > cad[i+1].id){
        aux = cad[i].id;
        cad[i].id = cad[i+1].id;
        cad[i+1].id = aux;

        strcpy(auxS,cad[i].nome);
        strcpy(cad[i].nome,cad[i+1].nome);
        strcpy(cad[i+1].nome,auxS);

        strcpy(auxS,cad[i].email);
        strcpy(cad[i].email,cad[i+1].email);
        strcpy(cad[i+1].email,auxS);

        strcpy(auxS,cad[i].sexo);
        strcpy(cad[i].sexo,cad[i+1].sexo);
        strcpy(cad[i+1].sexo,auxS);

        strcpy(auxS,cad[i].end.estado);
        strcpy(cad[i].end.estado,cad[i+1].end.estado);
        strcpy(cad[i+1].end.estado,auxS);

        strcpy(auxS,cad[i].end.cidade);
        strcpy(cad[i].end.cidade,cad[i+1].end.cidade);
        strcpy(cad[i+1].end.cidade,auxS);

        strcpy(auxS,cad[i].end.rua);
        strcpy(cad[i].end.rua,cad[i+1].end.rua);
        strcpy(cad[i+1].end.rua,auxS);

        strcpy(auxS,cad[i].end.cep);
        strcpy(cad[i].end.cep,cad[i+1].end.cep);
        strcpy(cad[i+1].end.cep,auxS);

        aux = cad[i].altura;
        cad[i].altura = cad[i+1].altura;
        cad[i+1].altura = aux;

      /*  aux = vacinaG[i];
        vacinaG[i] = vacinaG[i+1];
        vacinaG[i+1] = aux;*/
      }
    }
  }

  printf("Digite o ID: \n");
  scanf("%d", &idBusca);

  do {
   meio=(esquerda+direita)/2;

   if(cad[meio].id==idBusca){
     fflush(stdin);
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

     }
     system("pause");
     system("cls");
     repetir='N';

   if(cad[i].id>idBusca){
     direita=meio-1;
   }
   else{
     esquerda=meio+1;
   }
 }while(esquerda<=direita);

  if (repetir!='N') {
    printf("ID nao encotrado!\n");
    printf("Digite 1 para sair!\n");
    scanf("%c", &limpar);
    system("cls");
  }
}

void editar(){
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

void Excluir(){
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
