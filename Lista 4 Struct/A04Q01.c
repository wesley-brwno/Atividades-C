/*Desenvolva um  programa  em  C  utilizando  registro  que  permita  a  entrada  de  nome,
 endereço e telefone de 3 pessoas e os imprima ao final*/
 #include <stdio.h>
 #include <stdlib.h>
 struct informacoes {
   char nome[20], endereco[20], telefone[10];
 };
 int main() {
   struct informacoes info[3];
   for(int i=0; i<3; i++){
     printf("Digite o nome %i: \n", i+1);
     gets(info[i].nome);
     printf("Digite o endereco %i: \n", i+1);
     gets(info[i].endereco);
     printf("Digite o telefone %i: \n", i+1);
     gets(info[i].telefone);
     system("cls");
   }

   for(int i=0; i<3; i++){
     printf("Nome: %s\n", info[i].nome);
     printf("Endereco: %s\n", info[i].endereco);
     printf("Telefone: %s\n", info[i].telefone);
     printf("---------------------------------\n");
   }
   return 0;
 }
