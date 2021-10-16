#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Função para exibir o menu na tela
void exibirMenuTela(){
    printf("Selecione uma opcao: \n");
    printf("\t1 -> inclua um usuario por vez (MAXIMO 1000); \n");
    printf("\t2 -> edite um usuario; \n");
    printf("\t3 -> exclua um usuario; \n");
    printf("\t4 -> busque um usuario pelo id; \n");
    printf("\t5 -> busque um usuario pelo email; \n");
    printf("\t6 -> imprimir todos os usuarios cadastrados; \n");
    printf("\t7 -> fazer backup dos usuarios cadastrados; \n");
    printf("\t8 -> fazer restauracao de dados; \n\n");
}
//Função para verificar qual foi a opção escolhido pelo usuario
char lerOpcao(){
    //declaração de variaveis
    char opcaoEscolhida;
    int valido;
    //Verificador do WHILE
    valido=0;
    //Verifica se o caracter está correto
    while (valido == 0){
        scanf(" %c", &opcaoEscolhida);
        system("cls"); /*Limpar a tela*/
        switch (opcaoEscolhida){
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                return opcaoEscolhida;
            default:
                printf("Opcao invalida!\n\n");
                exibirMenuTela();
        }
    }
}

void cadastro(int i){
    int id[1000];
    char nome[60][1000], email[60][1000], sexo[60][1000];
    //ID
    id[i] = rand() % 1000;
    printf("Seu ID e %d\n", id[i]);

    //Nome
    printf("Digite seu nome: ");
    fflush(stdin);
    fgets(nome[i], 60, stdin);

    //Email
    printf("Digite seu e-mail: ");
    fflush(stdin);
    fgets(email[i], 60, stdin);

    //Sexo
    printf("Digite o seu sexo (masculino, feminino ou nao declarar): ");
    fflush(stdin);
    fgets(sexo[i], 15, stdin);


}




//Função principal do programa
int main(){
    //Declaração de variaveis
    char opcaoEscolhida;
    int i;
    i=-1;
    //Exibir menu na tela e verificar
    exibirMenuTela();
    opcaoEscolhida = lerOpcao();

    switch (opcaoEscolhida){
    case '1':
        i++;
        cadastro(i);
        break;
    }

    return 0;
}
