#include <stdio.h>

int main() {

  int valores[4][4], valores2[4][4], valores3[4][4];

  for( int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      valores[i][j]=(i*j)+1;
      valores2[i][j]=(i*j)+10;
      valores3[i][j]=valores[i][j]+valores2[i][j];
    }
  }

  valores3[2][2]=999;


  for( int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      printf("linha = %i, coluna = %i, %i\t",i, j, valores3[i][j]);
    }
    printf("\n");
  }
  return 0;
}
