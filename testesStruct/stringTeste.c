#include <stdio.h>
#include <stdlib.h>
struct ponto{
  char x, y;
};
void atribui(struct ponto *p);

int main() {
  struct ponto p1;
  atribui(&p1);
  printf("x = %c\n", p1.x);
  printf("y = %c\n", p1.y);
  return 0;
}

void atribui(struct ponto *p){
  p->x = 'S';
  p->y = 'J';
}
