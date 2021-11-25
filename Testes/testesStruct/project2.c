#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct endereco
{
    char rua[100], complemento[100], bairro[100];
    int quara, casa;
};
struct usuarios
{
    int id;
    char nome[100], email[100], sexo[100];
    double altura;
    bool vacina;
    struct endereco endereco;
}dados[1000],bkup[1000];

void cadastro(struct usuario *dados);
void id(struct usuario *dados, int userCount);
void nome(struct usuario *dados, int userCount);
void email(struct usuario *dados, int userCount);
void sexo(struct usuario *dados, int userCount);
void endereco(struct usuario *dados, int userCount);
void altura(struct usuario *dados, int userCount);
void vacina(struct usuario *dados, int userCount);
void mostrarPerfil(int idBuscado, struct usuario *dados);
void editar(struct usuario *dados);
void excluir(struct usuario *dados);
int buscarId(struct usuario *dados);
int buscarEmail(struct usuario *dados);
void mostraTodos(struct usuario *dados);
void backup(int backupOption, struct usuario *dados);
int userNumeber = 0;

int main()
{

    int option = 0, backupOption, validaBackup = 0;
    do
    {

        system("cls");
        printf("1-Criar usuario\n");
        printf("2-Edita usuario\n");
        printf("3-Excluir usuario\n");
        printf("4-Buscar por id\n");
        printf("5-Buscar por email\n");
        printf("6-Imprimir todos os usuarios\n");
        printf("7-Backup\n");
        printf("8-Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            cadastro(dados);
            break;
        case 2:
            editar(dados);

            break;
        case 3:
            excluir(dados);
            break;
        case 4:
            buscarId(dados);
            break;
        case 5:
            buscarEmail(dados);
            break;
        case 6:
            mostraTodos(dados);
            break;
        case 7:
            do
            {
                do
                {
                    system("cls");
                    printf("1-Criar Backup\n");
                    printf("2-recuperar Backup\n");
                    printf("3-Voltar\n");
                    printf("Digite um opcao: ");
                    scanf("%d", &backupOption);
                } while (backupOption < 1 || backupOption > 3);
                if (backupOption == 1)
                {
                    printf("backup realizado com sucesso!!!\n");
                    system("pause");
                    backup(backupOption, dados);
                    validaBackup == 1;
                }
                else if (backupOption == 2)
                {
                    printf("backup restaurado com sucesso!!!\n");
                    system("pause");
                    backup(backupOption, dados);
                }
                else if (backupOption == 2 && validaBackup != 1)
                {
                    printf("Nao tem backup salvo!\n");
                }
                else if (backupOption != 3)
                {
                    system("cls");
                    printf("Opcao invalida!! digite novamente");
                    system("pause");
                }
            } while (backupOption != 3);
            break;
        default:
            printf("Opcao invalida!! digite novamente");
            system("pause");
            system("cls");
            break;
        }
        printf("passou");
    } while (option > 1 || option < 7);
    printf("passou2");
    system("pause");
}
void cadastro(struct usuario *dados)
{
    int option;
    do
    {
        system("cls");
        printf("_________________Cadastro_________________\n");
        id(dados, userNumeber);
        nome(dados, userNumeber);
        email(dados, userNumeber);
        sexo(dados, userNumeber);
        endereco(dados, userNumeber);
        altura(dados, userNumeber);
        vacina(dados, userNumeber);
        printf("\n___________________________________________\n");
        mostrarPerfil(userNumeber, dados);
        system("cls");
        userNumeber++;
        do
        {
            printf("Deseja cadastra outro usuario(1-sim, 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}

void id(struct usuario *dados,int userCount)
{
    srand(time(NULL));
    dados[userCount].id = (rand() % (999999 - 100000 + 100000) + 100000);
    for (int i = 0; i < userNumeber; i++)
    {
        if (dados[userCount].id == id[i])
        {
            dados[userCount].id = (rand() % (999999 - 100000 + 100000) + 100000);
            i = 0;
        }
    }
}
void nome(struct usuario *dados, int userCount)
{
    do
    {
        printf("Digite seu nome completo: ");
        fflush(stdin);
        fgets(dados[userCount].nome, 100, stdin);
    } while (strlen(dados[userCount].nome) < 2);
}
void email(struct usuario *dados, int userCount)
{
    do
    {
        printf("Digite o email: ");
        fgets(dados[userCount].email, 100, stdin);
    } while (strchr(dados[userCount].email, '@') == NULL);
}
void sexo(struct usuario *dados, int userCount)
{
    int option = 1;
    do
    {
        printf("Digite o sexo(feminino, masculino e nao declarar): ");
        fflush(stdin);
        fgets(dados[userCount].sexo, 100, stdin);
        if (stricmp(dados[userCount].sexo, "masculino\n") == 0 || stricmp(dados[userCount].sexo, "feminino\n") == 0 || stricmp(dados[userCount].sexo, "nao declarar\n") == 0)
        {
            return;
        }
    } while (option == 1);
}
void endereco(struct usuario *dados, int userCount)
{
    do
    {
        printf("Informe a Rua: ");
        fflush(stdin);
        fgets(dados[userCount].endereco.rua, 100, stdin);
    } while (strlen(dados[userCount].endereco.rua) < 2);
    do
    {
        printf("Informe o Bairro: ");
        fflush(stdin);
        fgets(dados[userCount].endereco.bairro, 100, stdin);
    } while (strlen(dados[userCount].endereco.bairro) < 2);

    printf("Informe a Quadra: ");
    fflush(stdin);
    scanf("%d", &dados[userCount].endereco.quadra);

    printf("Informe o numero da Casa: ");
    fflush(stdin);
    scanf("%d", &dados[userCount].endereco.casa);

    do
    {
        printf("Digite um Complemento ");
        fflush(stdin);
        fgets(dados[userCount].endereco.complemento, 100, stdin);
    } while (strlen(endereco[userCount]) < 2);
}
void altura(struct usuario *dados, int userCount)
{
    do
    {
        printf("Digite sua altura: ");
        scanf("%lf", &dados[userCount].altura);
    } while (dados[userCount].altura < 1 || dados[userCount].altura > 2);
}
void vacina(struct usuario *dados, int userCount)
{
    int option = 1;
    char validaVacina[10];
    do
    {
        printf("tomou a vacina: ");
        fflush(stdin);
        fgets(validaVacina, 10, stdin);
        if (stricmp(validaVacina, "sim\n") == 0)
        {
            dados[userCount].vacina = true;
            option = 2;
        }
        else if (stricmp(validaVacina, "nao\n") == 0)
        {
            dados[userCount].vacina = false;
            option = 2;
        }
    } while (option == 1);
}

void mostrarPerfil(int idBuscado, struct usuario *dados)
{
    system("cls");
    printf("_______________________________________________\n");
    printf("O id do usuario: %d\n", dados[idBuscado].id);
    printf("O nome do usuario: %s\n", dados[idBuscado].nome);
    printf("O email do usuario: %s\n", dados[idBuscado].email);
    printf("O sexo do usuario: %s\n", dados[idBuscado].sexo);
    printf("O endereco do usuario: %s\n", dados[idBuscado].endereco);
    printf("O altura do usuario: %lf\n", dados[idBuscado].altura);
    if (dados[idBuscado].vacina == true)
    {
        printf("O usuario tomou a vacina\n");
    }
    else
    {
        printf("O usuario nao tomou a vacina\n");
    }
    printf("\n__________________________________________________\n");
    system("pause");
}

void editar(struct usuario *dados)
{
    int option, userCount;
    do
    {
        system("cls");
        printf("_________________Editar___________________\n");
        do
        {
            printf("buscar usuario:\n");
            printf("1-por ID\n");
            printf("2-por Email\n");
            printf("3-volta\n");
            printf("Digite uma opcao valida:");
            scanf("%d", &option);
        } while (option < 1 || option > 3);
        if (option == 1)
        {
            userCount = buscarId(dados);
        }
        else if (option == 2)
        {
            userCount = buscarEmail(dados);
        }
        else
        {
            return;
        }

        do
        {
            system("cls");
            printf("1-Nome\n");
            printf("2-Email\n");
            printf("3-Sexo\n");
            printf("4-Endereco\n");
            printf("5-Altura\n");
            printf("6-Vacina\n");
            printf("7-Volta\n");
            printf("Digite a opcao que deseja alterar:");
            scanf("%d", &option);
        } while (option < 1 || option > 7);
        if (option == 1)
        {
            nome(dados, userCount);
        }
        else if (option == 2)
        {
            email(dados, userCount);
        }
        else if (option == 3)
        {
            sexo(dados, userCount);
        }
        else if (option == 4)
        {
            endereco(dados, userCount);
        }
        else if (option == 5)
        {
            altura(dados, userCount);
        }
        else if (option == 6)
        {
            vacina(dados, userCount);
        }
        else
        {
            return;
        }
        mostrarPerfil(userCount, dados);
        do
        {
            system("cls");
            printf("deseja edita outro usuario(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
void excluir(struct usuario *dados)
{
    int option, userCount;
    do
    {
        do
        {
            printf("buscar usuario:\n");
            printf("1-por ID\n");
            printf("2-por Email\n");
            printf("3-volta\n");
            printf("Digite uma opcao valida: ");
            scanf("%d", &option);
            fflush(stdin);
        } while (option < 1 || option > 3);
        if (option == 1)
        {
            userCount = buscarId(dados);
        }
        else if (option == 2)
        {
            userCount = buscarEmail(dados);
        }
        else
        {
            return;
        }
        for (userCount; userCount < userNumeber; userCount)
        {
            dados[userCount].id = dados[++userCount].id;
            strcpy(dados[userCount].nome, dados[++userCount].nome);
            strcpy(dados[userCount].email, dados[++userCount].email);
            strcpy(dados[userCount].sexo, dados[++userCount].sexo);
            strcpy(dados[userCount].endereco, dados[++userCount].endereco);
            dados[userCount].altura = dados[++userCount].altura;
            dados[userCount].vacina = dados[++userCount].vacina;
        }
        userNumeber--;
        do
        {
            system("cls");
            printf("deseja edita outro usuario(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
int buscarId(struct usuario *dados)
{
    int idEscolhido, option;
    do
    {
        printf("Digite o ID do usuario: ");
        scanf("%d", &idEscolhido);
        fflush(stdin);
        for (int i = 0; i < userNumeber; i++)
        {
            if (dados[i].id == idEscolhido)
            {
                mostrarPerfil(i, dados);
                return i;
            }
        }
        do
        {
            printf("id invalido!");
            printf("Deseja tenta novamente(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
int buscarEmail(struct usuario *dados)
{
    int option;
    char emailEscolido[100];
    do
    {
        printf("Digite o email do usuario: ");
        fflush(stdin);
        fgets(emailEscolido, 100, stdin);
        for (int i = 0; i < userNumeber; i++)
        {
            if (stricmp(emailEscolido, dados[i].email) == 0)
            {
                mostrarPerfil(i, dados);
                return i;
            }
        }
        do
        {
            printf("email invalido!");
            printf("Deseja tenta novamente(1-sim 2-nao):");
            scanf("%d", &option);
        } while (option < 1 || option > 2);
    } while (option == 1);
}
void mostraTodos(struct usuario *dados)
{
    for (int i = 0; i < userNumeber; i++)
    {
        mostrarPerfil(i, dados);
    }
}
void backup(int backupOption, struct usuario *dados)
{
    int backupUserNumber;

    if (backupOption == 1)
    {
        for (int i = 0; i < userNumeber; i++)
        {
            bkup[i].id = dados[i].id;
            strcpy(bkup[i].nome, dados[i].nome);
            strcpy(bkup[i].email, dados[i].email);
            strcpy(bkup[i].sexo, dados[i].sexo);
            strcpy(bkup[i].endereco, dados[i].endereco);
            bkup[i].altura = dados[i].altura;
            bkup[i].vacina = dados[i].vacina;
        }
        backupUserNumber = userNumeber;
    }
    else if (backupOption == 2)
    {
        for (int i = 0; i < userNumeber; i++)
        {
            dados[i].id = bkup[i].id;
            strcpy(dados[i].nome, bkup[i].nome);
            strcpy(dados[i].email, bkup[i].email);
            strcpy(dados[i].sexo, bkup[i].sexo);
            strcpy(dados[i].endereco, bkup[i].endereco);
            dados[i].altura = bkup[i].altura;
            dados[i].vacina = bkup[i].vacina;
        }
        userNumeber = backupUserNumber;
    }
}
