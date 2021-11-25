#include <stdio.h>
int main(void) {

  struct horario{
    int horas;
    int minutos;
    int segundos;
  };

  struct horario teste[5] ={{10,20,30},{90,80,70},{34,45,66},{99,00,11},{11,22,33}};
  int i;
  for (i = 0; i < 5; i++) {
    printf("%i:%i:%i\n", teste[i].horas,teste[i].minutos,teste[i].segundos);
  }
  return 0;
}
