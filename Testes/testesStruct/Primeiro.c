#include <stdio.h>

  struct horario{ // Denfinição do Struct;
    int horas;
    int minutos;
    int segundos;
    double teste;
    char letra;
  };
int main(void) {

  struct horario agora; // Declaração do struct;

  agora.horas = 15;
  agora.minutos = 17;
  agora.segundos = 30;

  struct horario depois;
  depois.horas = agora.horas + 10;
  depois.minutos = agora.minutos;
  depois.teste = 50.55 / 123;
  depois.letra = 'a';

  printf("%i\n", depois.horas);
  printf("%i\n", depois.minutos);
  printf("%f\n", depois.teste);
  printf("%c\n", depois.letra);
  return 0;
}