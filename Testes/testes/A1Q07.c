// Sintese
// Objetivo: Aumetar preços de CDs;
// Entrada: Preço dos CDs e porcentagem do aumento;
// Saída: Preço dos CDs sem e com aumento e porcetual do aumento;
#include <stdio.h>
int main(void) {
  int i;
  float cd[100],aumento,porCen;
  char tipo;

  for(i = 0; i < 100; i++){
    printf("Valor do CD %i: ", i+1);
    scanf("%f", &cd[i]);
  }
  do {
    printf("Escolha a opcao de aumento:\n  (P)rimeira = aumento de 10%%;\n  (S)egunda = determine o valor;\n");
    fflush(stdin);
    scanf("%c", &tipo);
    switch (tipo) {
      case 'P':
        for(i = 0; i < 100; i++){
          aumento = cd[i] * 1.10;
          printf("O percentual do aumento foi 10 %%, valor sem aumento %.2f, valor com aumento %.2f\n", cd[i],aumento);
        }
        break;
      case 'S':
        printf("Digite o percentual do aumento: ");
        fflush(stdin);
        scanf("%f", &porCen);
        for (i = 0; i < 100; i++){
          aumento = cd[i] * ( 1.0 + (porCen/100));
          printf("O percentual do aumento foi %.0f %%, valor sem aumento %.2f, valor com aumento %.2f\n", porCen,cd[i],aumento);
        }
        break;
      default :
        printf("\nDigite P ou S !!!\n \n");
        tipo = 'Y';
    }
  } while (tipo == 'Y');
  return 0;
}
