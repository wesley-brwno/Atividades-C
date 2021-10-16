// programa usando struct e ponteiros
// ler e exibir informacoes de um estudante

#include <stdio.h>

int main(){
// criacao da variavel de estudante

// tipo de dado definido pelo usuario
  struct estudante {
    int nMatricula;
    char nome[30];
    float vMensalidade;
    char dataBacharelado[30];
  };

//Declara variavel do tipo estudante e
// Declara variavel do tipo ponteito do struct
// estudante
  struct estudante stud1, *ptr_stud1;
//leitura de dados do estudante
  ptr_stud1=&stud1;
  printf("\n Entre matricula");
  scanf("%d",&ptr_stud1->nMatricula);
  printf("\n Entre nome");
  scanf("%s",&ptr_stud1->nome);
  printf("\n Entre mensalidade");
  scanf("%f",&ptr_stud1->vMensalidade);
  printf("\n Entre data Bacharelado");
  scanf("%s",&ptr_stud1->dataBacharelado);


//Exibir dados coletados
  printf("\n *****CADASTRO DO ESTUDANTE *****");
  printf("\n No. matricula= %d", ptr_stud1->nMatricula);
  printf("\n Nome= %s", ptr_stud1->nome);
  printf("\n Valor mensalidade= %9.2f", ptr_stud1->vMensalidade);
  printf("\n Data do Bacharelado = %s", ptr_stud1->dataBacharelado);

  return 0;
}






// exibir dados coletados
