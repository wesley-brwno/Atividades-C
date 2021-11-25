#include <stdio.h>
#include <stdlib.h>

void incrementa_num(int *num);
int main() {
  int num;
  num=10;
  incrementa_num(&num);//& endereco da variavel
  printf("Numero na main: %d\n", num);

  return 0;
}

void incrementa_num(int *num){
  *num=*num+1;
}
