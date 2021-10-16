#include <stdio.h>
int main() {

  char email[30];
  int i=0, checar=0;
  do {
    printf("Digite o email:\n");
    gets(email);
    setbuf(stdin,NULL);
    do {
      if (email[i]=='@') {
        checar=1;
      }
      printf("%c\n", email[i]);
      i++;
    } while( i < 4);
    printf("%i", checar);
  } while(checar == 0);

  return 0;
}
