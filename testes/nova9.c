// Ordenar vetores !!!
// Buble sort
#include <stdio.h>
int main (void){
  int mes[50], matricula[50], cont=0;

  do {
    printf("Digite a Matricula :");
    scanf("%i", &matricula[cont]);
    switch (matricula[cont]){
      case 0:
        break;
      default :
        printf("Digite a quantidade de meses: ");
        scanf("%i", &mes[cont]);
    }
    cont++;
  } while(matricula[cont-1] != 0 && cont -1 < 50);


  return 0;
}
