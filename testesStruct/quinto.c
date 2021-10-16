#include <stdio.h>

int main(void) {

struct horario{
  int hora;
  int minuto;
  int segundos;
};

  struct horario agora, *depois;
  depois = &agora;

  //(*depois).hora = 20;
  depois->hora = 20;
  (*depois).minuto = 20;
  (*depois).segundos = 77;

  printf("%i:%i:%i\n", agora.hora, agora.minuto, agora.segundos);
  return 0;
}
