// Sintese
// Objetivo: Descobrir os três funcionários mais recentes;
// Entrada: Matrícula e meses de trabalho;
// Saída: Matrícula dos três funcionários mais recentes;
// Não finalizado.
#include <stdio.h>
#include <stdlib.h>
int main (void){
  int mes[50], mescp[50], matricula[50], cont=0, i, j, aux;

  do {
    printf("Digite a Matricula :");
    scanf("%i", &matricula[cont]);
    switch (matricula[cont]){
      case 0:
        break;
      default :
        printf("Digite a quantidade de meses: ");
        scanf("%i", &mes[cont]);
        mescp[cont]=mes[cont];
    }
    cont++;
  } while(matricula[cont-1] != 0 && cont -1 < 50);

  for (j = 0; j < cont-1; j++){
    for (i = 0; i < cont -1; i++){
      if (mes[i] > mes[i+1]){
        aux = mes[i];
        mes[i] = mes[i+1];
        mes[i+1] = aux;
      }
    }
  }

  system("cls");
  printf("Os 3 funcionarios mais recentes foram :");
  for (i=0; i<cont-1;i++){
    if (mes[0]==mescp[i]) {
      printf("%i ", matricula[i]);
    }
  }
  for (i=1; i<cont-1;i++){
    if (mes[1]==mescp[i]) {
      printf("%i ", matricula[i]);
    }
  }
  for (i=0; i<cont-1;i++){
    if (mes[2]==mescp[i]) {
      printf("%i ", matricula[i]);
    }
  }

  return 0;
}
