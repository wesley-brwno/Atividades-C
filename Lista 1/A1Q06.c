// Sintese
// Objetivo: Informar maior e menor salários;
// Entrada: Salários e matrículas de funcionários;
// Saída: Valores do maior e do menor salários;
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int i;
  char matricula[5][100];
  float salario[100],maiorSlr=0,menorSlr;

  for(i = 0; i < 5; i++){
    printf("Matricula do funcionario: ");
    scanf("%s", &matricula[i]);
    printf("Salario do funcionario: ");
    scanf("%f", &salario[i]);
    if (salario[i] > maiorSlr)
      maiorSlr = salario[i];
    printf("\n");
  }
  menorSlr = maiorSlr;
  for( i = 0; i < 5; i++){
    if (salario[i] < menorSlr)
      menorSlr = salario[i];
  }
  system("cls");
  printf("===================\n");
  for(i = 0; i < 5; i++){
    printf("Matricula: %s\n", matricula[i]);
    printf("Salario: %.2f\n", salario[i]);
  }
  printf("===================\n \n");
  printf("O maior salario foi: %.2f\n", maiorSlr);
  printf("O menor salario foi: %.2f", menorSlr);
  return 0;
  system("cls");
}
