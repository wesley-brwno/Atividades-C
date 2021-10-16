#include <stdio.h>
#include <string.h>
double validarAltura(double alturaValidar);
int incluirUsuario(double *altura, double alturaValidar, int indice, char sexo[][20], char *sexoValidar);
int menu();

int main(){
  double altura[5], alturaValidar;
  char sexo[5][20],sexoValidar[20]; //vetor qtd caracteres.
  int indice=0, opcao;
  switch (menu())
  {
  case 1: indice=incluirUsuario(altura,alturaValidar,indice,sexo,sexoValidar);
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
    break;
  default:printf("Valoar invalido\n");
   break;
  }

}

int menu(){
  int opcao;
  printf("1 incluir\n2 editar\n3  excluir\n4 Buscar\n5 Imprimir\n6 backup\n7 restaurar\n");
  scanf("%i", &opcao);
  return opcao;
}

double validarAltura(double alturaValidar){

  do
  {
    printf("Digite altura \n");
    scanf("%lf", &alturaValidar);
    if(alturaValidar < 1 || alturaValidar > 2)
      printf("Invalido\n");
  } while(alturaValidar < 1 || alturaValidar > 2);

return alturaValidar;
}


char* validarSexo( char *sexoValidar){
  do {
    printf("Digite o sexo:\n");
    fflush(stdin);
    fgets(sexoValidar, 20, stdin);
    if (stricmp(sexoValidar,"Feminino")!=0)
      printf("Sexo digitado invalido\n");
  } while(stricmp(sexoValidar,"Feminino")!=0);

  return sexoValidar;
}

int incluirUsuario(double *altura, double alturaValidar, int indice, char sexo[][20], char *sexoValidar)
{ // ponteiro
    strcpy(sexo[indice],validarSexo[sexoValidar]);
    altura[indice]=validarAltura(alturaValidar);
    indice++;
  return indice;
}
