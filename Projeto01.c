#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char nomeG[30][1000], emailG[15][1000], sexoG[15][1000], enderecoG[30][1000];
char editarUsr, restaurar;
int j=0, idG[1000], vacinaG[1000], cont, editar;
double alturaG[1000];

void Menu();
void Adicionar_editar_Usuario();
void imprimirUsuario();
void BuscarID();
void buscarEmail();
void backup_restaurar_Usuario();
void excluirUsuario();

int main() {
  int opcao, idBusca, idValido, i, sair;

  do {
    Menu();
    fflush(stdin);
    scanf("%i", &opcao);
    system("cls");

    switch (opcao) {
      case 1:
      Adicionar_editar_Usuario();
      cont++;
      break;
      case 2:
      printf("Digite o ID do usuario:\n");
      scanf("%i", &idBusca);
      idValido=0;
      for (i=0; i<cont; i++){
        if (idBusca==idG[i]) {
          editar=i;
          editarUsr='S';
          idValido=1;
          Adicionar_editar_Usuario();
          editarUsr='N';
        }
      }
      if (idValido!=1) {
        printf("ID Invalido\n");
      }
      printf("\nDigite 1 para sair!\n");
      scanf("%i", &sair);
      system("cls");
    break;
    case 3:
    excluirUsuario();
    break;
    case 4:
    BuscarID();
    break;
    case 5:
    buscarEmail();
    break;
    case 6:
    imprimirUsuario();
    break;
    case 7:
    backup_restaurar_Usuario();
    break;
    case 8:
    restaurar='S';
    backup_restaurar_Usuario();
    restaurar='N';
    break;
    }
  } while(cont < 1000);
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

void Adicionar_editar_Usuario(){
  char nome[30], email[15], sexo[15], endereco[30],vacinado[4];
  char repetir,repetir2,repetir3,repetir4, repetir5,fem[]="Feminino", mas[]="Masculino", nd[]="Nao declarar",nao[]="Nao",sim[]="Sim";
  double altura;
  int opcao, i=1, id[1000], idFixo, tamanhoEmail, vacina, l;

  if (editarUsr=='S') {
    idFixo=idG[editar];
    printf("Usuario: %i\n", idG[editar]);
    }
    else{
    id[i] = rand() % 1000;
    idFixo=id[i];
    printf("Usuario: %i\n", id[i]);
  }

  fflush(stdin);
  printf("Digite o nome:\n");
  gets(nome);
  do {
    printf("Digite o email:\n");
    gets(email);
    tamanhoEmail=strlen(email);
    for (i = 0; i < tamanhoEmail; i++) {
      switch (email[i]) {
        case '@':
        repetir='N';
      }
    }
    if (repetir!='N')
      printf("Email deve conter @!!\n");
  } while(repetir!='N');
  repetir='S';
  do {
    printf("Digite o sexo (Feminino, Masculino, Nao declarar):\n");
    gets(sexo);
    if ((strcmp(sexo,fem)==0) || (strcmp(sexo,mas)==0) || (strcmp(sexo,nd)==0))
      break;
    else{
      printf("Sexo Incorreto!!\n");
        repetir2='S';
    }
  } while(repetir2=='S');
  printf("Digite o endereco:\n");
  gets(endereco);
  do {
    printf("Digite a altura:\n");
    scanf("%lf", &altura);
    if ((altura>1)&&(altura<2)) {
      break;
    }
    else{
      printf("Altura Incorreta\n");
      repetir3='S';
    }
  } while(repetir3=='S');
  do {
    printf("Ja vacinou? (Sim/ Nao)\n");
    fflush(stdin);
    gets(vacinado);
    if ((strcmp(vacinado, sim)==0)||(strcmp(vacinado,nao)==0))
      repetir4='N';
    else
      printf("Digite Sim ou Nao!\n");
  } while(repetir4!='N');
  vacina = strcmp(sim, vacinado)==0;
  system("cls");

  if (idG[0]<0) {
    fflush(stdin);
    strcpy(nomeG[0], nome);
    strcpy(emailG[0], email);
    strcpy(sexoG[0], sexo);
    strcpy(enderecoG[0], endereco);
    alturaG[0]=altura;
    vacinaG[0]=vacina;
    idG[0]=idFixo;
  }
  else{
    if (editarUsr=='S') {
      strcpy(nomeG[editar], nome);
      strcpy(emailG[editar], email);
      strcpy(sexoG[editar], sexo);
      strcpy(enderecoG[editar], endereco);
      alturaG[editar]=altura;
      vacinaG[editar]=vacina;
      idG[editar]=idFixo;
    }
    else{
      fflush(stdin);
      strcpy(nomeG[j], nome);
      strcpy(emailG[j], email);
      strcpy(sexoG[j], sexo);
      strcpy(enderecoG[j], endereco);
      alturaG[j]=altura;
      vacinaG[j]=vacina;
      idG[j]=idFixo;
      j++;
    }
  }
}

void imprimirUsuario() {
  int i;
  char Sair;
for (i = 0; i <= cont; i++) {
  if (idG[i] > 0){
    printf("Usuario: %i\n", idG[i]);
    printf("Nome: %s\n", nomeG[i]);
    printf("Email: %s\n", emailG[i]);
    printf("Sexo: %s\n", sexoG[i]);
    printf("Altura: %.2f\n", alturaG[i]);
    printf("Endereco: %s\n", enderecoG[i]);
    printf("Vacinou: ");
    switch (vacinaG[i]) {
      case 1:
      printf("Sim\n");
      break;
      case 0:
      printf("Nao\n");
    }
    printf("\n");
  }
}
printf("Digite 1 para sair!\n");
scanf("%c\n", &Sair);
system("cls");
}

void BuscarID(){
  int esquerda, direita, meio, idBusca, j, i, aux;
  char repetir, auxS[30], limpar;
  esquerda=0;
  direita=cont;

  for (j = 0; j < cont-1; j++){
    for (i = 0; i < cont-1; i++){
      if (idG[i] > idG[i+1]){
        aux = idG[i];
        idG[i] = idG[i+1];
        idG[i+1] = aux;

        strcpy(auxS,nomeG[i]);
        strcpy(nomeG[i],nomeG[i+1]);
        strcpy(nomeG[i+1],auxS);

        strcpy(auxS,emailG[i]);
        strcpy(emailG[i],emailG[i+1]);
        strcpy(emailG[i+1],auxS);

        strcpy(auxS,sexoG[i]);
        strcpy(sexoG[i],sexoG[i+1]);
        strcpy(sexoG[i+1],auxS);

        strcpy(auxS,enderecoG[i]);
        strcpy(enderecoG[i],enderecoG[i+1]);
        strcpy(enderecoG[i+1],auxS);

        aux = alturaG[i];
        alturaG[i] = alturaG[i+1];
        alturaG[i+1] = aux;

        aux = vacinaG[i];
        vacinaG[i] = vacinaG[i+1];
        vacinaG[i+1] = aux;
      }
    }
  }
  printf("Digite o ID: \n");
  scanf("%i", &idBusca);
  do {
   meio=(esquerda+direita)/2;

   if(idG[meio]==idBusca){
     fflush(stdin);
     printf("Usuario: %i\n", idG[meio]);
     printf("Nome: %s\n", nomeG[meio]);
     printf("Email: %s\n", emailG[meio]);
     printf("Sexo: %s\n", sexoG[meio]);
     printf("Endereco: %s\n", enderecoG[meio]);
     printf("Altura: %.2f\n", alturaG[meio]);
     printf("Vacinou: ");
     switch (vacinaG[j]) {
       case 1:
       printf("Sim\n");
       break;
       case 0:
       printf("Nao\n");
     }
     printf("\n\nDigite 1 para sair!\n");
     scanf("%c", &limpar);
     system("cls");
     repetir='N';
   }
   if(idG[meio]>idBusca){
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

void buscarEmail() {
  char emailBusca[30],i=0;
  char repetir,sair;
  printf("Digite o email: \n");
  fflush(stdin);
  gets(emailBusca);
  do {
    if (strcmp(emailBusca,emailG[i])==0) {
      printf("\n");
      fflush(stdin);
      printf("Usuario: %i\n", idG[i]);
      printf("Nome: %s\n", nomeG[i]);
      printf("Email: %s\n", emailG[i]);
      printf("Sexo: %s\n", sexoG[i]);
      printf("Endereco: %s\n", enderecoG[i]);
      printf("Altura: %.2f\n", alturaG[i]);
      printf("Vacinou: ");
      switch (vacinaG[i]) {
        case 1:
        printf("Sim\n");
        break;
        case 2:
        printf("Nao\n");
        break;
      }
      repetir='N';
    }
    if ((i==cont)&&(repetir!='N'))
      printf("Email invalido");
    i++;
  } while((repetir!='N')&&(i<=cont));
  printf("\n\nDigite 1 para sair!\n");
  scanf("%c", &sair);
  system("cls");
}

void excluirUsuario(){
  int i, j, l=0, idBusca, aux, sair, excluidos=-1;
  char repetir,auxS[30];
  printf("Digite o ID:\n");
  scanf("%i", &idBusca);
  do {
    if (idBusca==idG[l]) {
      idG[l]=excluidos;
      for (j = 0; j < cont-1; j++){
        for (i = 0; i < cont-1; i++){
          if (idG[i] > idG[i+1]){
            aux = idG[i];
            idG[i] = idG[i+1];
            idG[i+1] = aux;

            strcpy(auxS,nomeG[i]);
            strcpy(nomeG[i],nomeG[i+1]);
            strcpy(nomeG[i+1],auxS);

            strcpy(auxS,emailG[i]);
            strcpy(emailG[i],emailG[i+1]);
            strcpy(emailG[i+1],auxS);

            strcpy(auxS,sexoG[i]);
            strcpy(sexoG[i],sexoG[i+1]);
            strcpy(sexoG[i+1],auxS);

            strcpy(auxS,enderecoG[i]);
            strcpy(enderecoG[i],enderecoG[i+1]);
            strcpy(enderecoG[i+1],auxS);

            aux = alturaG[i];
            alturaG[i] = alturaG[i+1];
            alturaG[i+1] = aux;

            aux = vacinaG[i];
            vacinaG[i] = vacinaG[i+1];
            vacinaG[i+1] = aux;
          }
        }
      }
      excluidos--;
      repetir='N';
      system("cls");
      break;
    }
    l++;
  } while((repetir!='N')&&(l<cont));
  if (repetir!='N') {
    printf("ID Invalido\n");
    printf("\nDigite 1 para sair!");
    scanf("%i", &sair);
    system("cls");
  }
}

void backup_restaurar_Usuario(){
  char nome[30][1000], email[15][1000], sexo[15][1000], endereco[30][1000];
  int vacina[1000], id[1000], l;
  double altura[1000];

  if (restaurar=='S') {
    for(l=0; l<cont; l++){
      idG[l]=id[l];
      strcpy(nomeG[l], nome[l]);
      strcpy(emailG[l], email[l]);
      strcpy(sexoG[l], sexo[l]);
      strcpy(enderecoG[l], endereco[l]);
      vacinaG[l]=vacina[l];
      alturaG[l]=altura[l];
      restaurar='N';
    }
  }
  else{
    for(l=0; l<cont; l++){
      id[l]=idG[l];
      strcpy(nome[l], nomeG[l]);
      strcpy(email[l], emailG[l]);
      strcpy(sexo[l], sexoG[l]);
      strcpy(endereco[l], enderecoG[l]);
      vacina[l]=vacinaG[l];
      altura[l]=alturaG[l];
    }
  }
}
