#include <stdio.h>
int main(void) {

  struct horario{
    int horas;
    int minutos;
    int segundos;
  };

  struct horario agora = {.segundos=99, . horas=77};

  printf("%i:%i:%i\n", agora.horas, agora.minutos, agora.segundos);
  return 0;
}
