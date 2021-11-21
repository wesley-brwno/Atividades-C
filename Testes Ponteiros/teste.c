#include <stdio.h>

int main() {
  int x=0, *p;
  p=&x;
  x=5;
  *p=*p+1;
  x=x+1;
  printf("%i, %i", x,*p);
  return 0;
}
