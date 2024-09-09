#include <stdio.h>   // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // Biblioteca para aloca��o de espa�o em mem�ria
#include <locale.h>  // Biblioteca para aloca��es de texto por regi�o
#include <string.h>  // Biblioteca para manipula��o de strings

#define MAX_ALUNOS 100  // Define o n�mero m�ximo de alunos

int main() {
    setlocale(LC_ALL, "Portuguese");  // Configura o uso do idioma Portugu�s

    int opcao;  // Vari�vel para armazenar a escolha do usu�rio
    char nomes[MAX_ALUNOS][100];       // Array para armazenar os nomes dos alunos
    char sobrenomes[MAX_ALUNOS][100];  // Array para armazenar os sobrenomes dos alunos
    char cpfs[MAX_ALUNOS][15];         // Array para armazenar os CPFs dos alunos
    char cargos[MAX_ALUNOS][50];       // Array para armazenar os cargos dos alunos
    int totalAlunos = 0;               // Contador de alunos cadastrados

    do {
        // Exibe o menu principal
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar Alunos\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n");
        printf("Esse software � do rk.exe\n\n");
        printf("Digite sua op��o: ");
        scanf("%d", &opcao);  // L� a op��o do usu�rio

        system("cls");  // Limpa a tela (para sistemas Windows)

        if (opcao == 1) {
            // Registrar novos alunos
            if (totalAlunos < MAX_ALUNOS) {  // Verifica se ainda h� espa�o para mais alunos
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", nomes[totalAlunos]);  // L� o nome do aluno
                printf("Digite o sobrenome do aluno: ");
                scanf(" %[^\n]", sobrenomes[totalAlunos]);  // L� o sobrenome do aluno
                printf("Digite o CPF do aluno (somente n�meros): ");
                scanf(" %[^\n]", cpfs[totalAlunos]);  // L� o CPF do aluno
                printf("Digite o cargo do aluno: ");
                scanf(" %[^\n]", cargos[totalAlunos]);  // L� o cargo do aluno
                totalAlunos++;  // Incrementa o contador de alunos
                printf("Nome registrado com sucesso!\n");
            } else {
                printf("Limite m�ximo de alunos atingido!\n");
            }
        } else if (opcao == 2) {
            // Menu de consulta
            int subOpcao;
            printf("### Menu de Consulta ###\n");
            printf("Escolha a op��o desejada:\n");
            printf("\t1 - Fun��es\n");
            printf("\t2 - Banco de Dados\n");
            printf("\t3 - Projeto de Fun��es\n");
            printf("\t4 - Consulta de Aluno\n");
            printf("Digite sua op��o: ");
            scanf("%d", &subOpcao);

            system("cls");

            if (subOpcao == 1) {
                printf("Fun��es s�o blocos de c�digo que executam uma tarefa espec�fica no programa.\n");
            } else if (subOpcao == 2) {
                printf("Banco de Dados � onde as informa��es s�o armazenadas de forma organizada.\n");
            } else if (subOpcao == 3) {
                printf("Projeto de Fun��es � o planejamento e organiza��o de fun��es em um sistema.\n");
            } else if (subOpcao == 4) {
                // Consulta de Aluno
                if (totalAlunos > 0) {
                    int aluno;
                    printf("Digite o n�mero do aluno que deseja consultar (1 a %d): ", totalAlunos);
                    scanf("%d", &aluno);

                    if (aluno > 0 && aluno <= totalAlunos) {
                        // Exibe as informa��es do aluno
                        printf("Nome: %s\n", nomes[aluno - 1]);
                        printf("Sobrenome: %s\n", sobrenomes[aluno - 1]);
                        printf("CPF: %s\n", cpfs[aluno - 1]);
                        printf("Cargo: %s\n", cargos[aluno - 1]);
                    } else {
                        printf("N�mero inv�lido!\n");
                    }
                } else {
                    printf("Nenhum aluno registrado at� o momento.\n");
                }
            } else {
                printf("Op��o inv�lida!\n");
            }
        } else if (opcao == 3) {
            // Deletar nomes
            if (totalAlunos > 0) {
                int num;
                printf("Digite o n�mero do aluno que deseja deletar: ");
                scanf("%d", &num);

                if (num > 0 && num <= totalAlunos) {
                    // Deleta o nome deslocando os elementos para a esquerda
                    for (int i = num - 1; i < totalAlunos - 1; i++) {
                        strcpy(nomes[i], nomes[i + 1]);
                        strcpy(sobrenomes[i], sobrenomes[i + 1]);
                        strcpy(cpfs[i], cpfs[i + 1]);
                        strcpy(cargos[i], cargos[i + 1]);
                    }
                    totalAlunos--;  // Decrementa o contador de alunos
                    printf("Nome deletado com sucesso!\n");
                } else {
                    printf("N�mero inv�lido!\n");
                }
            } else {
                printf("Nenhum aluno registrado para deletar.\n");
            }
        } else if (opcao >= 4 || opcao <= 0) {
            printf("Essa op��o n�o est� dispon�vel!\n");
        }
    } while (opcao != 4);  // O programa continua at� o usu�rio escolher a op��o de sair

    printf("Saindo do programa...\n");
    return 0;
}
