// Sintese
// Objetivo : Apresentar idade porvavel e nivel de idade;
// Entrada : Ano de nascimento;
// Saída : Idade e nivel de idade;
#include <stdio.h>
int main (void){
  int apresentaClassificacao(int x, int y);
  int anoNs, anoAt;

  printf("Digite seu ano de nascimento: ");
  scanf("%i", &anoNs);
  printf("Digite o ano atual: ");
  scanf("%i", &anoAt);
  apresentaClassificacao(anoNs, anoAt);
  return 0;
}
int apresentaClassificacao(int x, int y){
  void obtemNivel(int idade);
  int idade = y-x;
  printf("A idade provavel e %i\n", idade);
  obtemNivel(idade);
  return idade;
}
void obtemNivel(int idade){
  if (idade > 10 && idade < 18)
  printf("ADOLECENTE");
  if (idade >= 18 && idade < 25)
  printf("JOVEM");
  if (idade >= 25 && idade <= 58)
  printf("ADULTO");
  if (idade >58)
  printf("IDOSO");
}
