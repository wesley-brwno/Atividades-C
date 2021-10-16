#include <stdio.h>
int main(void) {
  float peso[3];
  int i;
  for(i=0; i<3; i++){
    printf("Digite o peso %i:\n", i+1);
    scanf("%f", &peso[i]);
  }
  return 0;
}
