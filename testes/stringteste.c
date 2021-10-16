#include <stdio.h>
int main(void) {
  char frase[4];
  int i=0, validado=0;
  scanf("%s", &frase);
  /*for (i = 0; i < 4; i++) {
    if (frase[i]== '@') {
      printf("1");
    }
    else
    printf("0");
  }*/
  do {
    switch (frase[i]) {
      case '@':
      validado=9;
    }
    i++;
  } while( i < 30);
  printf("%i foi validado\n", validado);

  return 0;
}
