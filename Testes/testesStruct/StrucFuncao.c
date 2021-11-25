#include <stdio.h>
#include <stdlib.h>
struct ponto{
  int x, y;
};
void atribui(struct ponto *p);

/*void impime_valor(int *n) {
  *n = *n + 1;
  printf("Valor= %d\n", *n);
}
int main() {
  struct ponto p1 = {10,20};
  impime_valor(&p1.x);
  impime_valor(&p1.y);
  return 0;
}*/
int main() {
  struct ponto p1;
  atribui(&p1);
  printf("x = %d\n", p1.x);
  printf("y = %d\n", p1.y);
  return 0;
}

void atribui(struct ponto *p){
  p->x = 10;
  p->y = 22;
}
