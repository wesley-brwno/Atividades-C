#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char nomeG[30][1000], emailG[15][1000], sexoG[15][1000], enderecoG[30][1000], vacinadoG[4][1000];
char Rest_nomeG[30][1000], Rest_emailG[15][1000], Rest_sexoG[15][1000], Rest_enderecoG[30][1000];
int j=0, idG[1000], vacinaG[1000], cont=0, Rest_vacinaG[1000], Rest_idG[1000], sair;
double alturaG[1000], Rest_alturaG[1000];

int main(void) {
  void Menu();
  void imprimirUsuario();
  void BuscarID();
  void buscarEmail();
  void editarUsuario();
  void restaurarDados();
  void excluirUsuario();

  do {
    Menu();
    scanf("%i", &opcao);
    system("cls");
    switch (opcao) {
      case 1:

}return 0;

void EditarEcadastrar(){}
