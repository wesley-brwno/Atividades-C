#include <stdio.h>
#include <stdlib.h>

struct veiculo {
  char proprietario[25], combustivel, modelo[10], cor[10];
  char N_chassi[10], placa[6];
  int ano;
};

void listarA(struct veiculo registro);

int main(void) {
  struct veiculo registro[5][3];
  int qtd=0;

  registro[1][0].proprietario="Joao";
  registro[1][1].combustivel="alcool";
  registro[1][0].modelo="Gol";
  registro[1][1].cor="verde";
  registro[1][0].N_chassi="123";
  registro[1][1].ano=2011;
  registro[1][2].placa="abc1234";

  listarA(registro);


  return 0;
}

void listarA(struct veiculo registro){
  for (int i=0; i < 5; i++){
    if(registro[i][1]>=2010);
  }
}
