#include <stdio.h>   // Biblioteca de comunicação com o usuário
#include <stdlib.h>  // Biblioteca para alocação de espaço em memória
#include <locale.h>  // Biblioteca para alocações de texto por região
#include <string.h>  // Biblioteca para manipulação de strings

#define MAX_ALUNOS 100  // Define o número máximo de alunos

int main() {
    setlocale(LC_ALL, "Portuguese");  // Configura o uso do idioma Português

    int opcao;  // Variável para armazenar a escolha do usuário
    char nomes[MAX_ALUNOS][100];       // Array para armazenar os nomes dos alunos
    char sobrenomes[MAX_ALUNOS][100];  // Array para armazenar os sobrenomes dos alunos
    char cpfs[MAX_ALUNOS][15];         // Array para armazenar os CPFs dos alunos
    char cargos[MAX_ALUNOS][50];       // Array para armazenar os cargos dos alunos
    int totalAlunos = 0;               // Contador de alunos cadastrados

    do {
        // Exibe o menu principal
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar Alunos\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n");
        printf("Esse software é do rk.exe\n\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);  // Lê a opção do usuário

        system("cls");  // Limpa a tela (para sistemas Windows)

        if (opcao == 1) {
            // Registrar novos alunos
            if (totalAlunos < MAX_ALUNOS) {  // Verifica se ainda há espaço para mais alunos
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", nomes[totalAlunos]);  // Lê o nome do aluno
                printf("Digite o sobrenome do aluno: ");
                scanf(" %[^\n]", sobrenomes[totalAlunos]);  // Lê o sobrenome do aluno
                printf("Digite o CPF do aluno (somente números): ");
                scanf(" %[^\n]", cpfs[totalAlunos]);  // Lê o CPF do aluno
                printf("Digite o cargo do aluno: ");
                scanf(" %[^\n]", cargos[totalAlunos]);  // Lê o cargo do aluno
                totalAlunos++;  // Incrementa o contador de alunos
                printf("Nome registrado com sucesso!\n");
            } else {
                printf("Limite máximo de alunos atingido!\n");
            }
        } else if (opcao == 2) {
            // Menu de consulta
            int subOpcao;
            printf("### Menu de Consulta ###\n");
            printf("Escolha a opção desejada:\n");
            printf("\t1 - Funções\n");
            printf("\t2 - Banco de Dados\n");
            printf("\t3 - Projeto de Funções\n");
            printf("\t4 - Consulta de Aluno\n");
            printf("Digite sua opção: ");
            scanf("%d", &subOpcao);

            system("cls");

            if (subOpcao == 1) {
                printf("Funções são blocos de código que executam uma tarefa específica no programa.\n");
            } else if (subOpcao == 2) {
                printf("Banco de Dados é onde as informações são armazenadas de forma organizada.\n");
            } else if (subOpcao == 3) {
                printf("Projeto de Funções é o planejamento e organização de funções em um sistema.\n");
            } else if (subOpcao == 4) {
                // Consulta de Aluno
                if (totalAlunos > 0) {
                    int aluno;
                    printf("Digite o número do aluno que deseja consultar (1 a %d): ", totalAlunos);
                    scanf("%d", &aluno);

                    if (aluno > 0 && aluno <= totalAlunos) {
                        // Exibe as informações do aluno
                        printf("Nome: %s\n", nomes[aluno - 1]);
                        printf("Sobrenome: %s\n", sobrenomes[aluno - 1]);
                        printf("CPF: %s\n", cpfs[aluno - 1]);
                        printf("Cargo: %s\n", cargos[aluno - 1]);
                    } else {
                        printf("Número inválido!\n");
                    }
                } else {
                    printf("Nenhum aluno registrado até o momento.\n");
                }
            } else {
                printf("Opção inválida!\n");
            }
        } else if (opcao == 3) {
            // Deletar nomes
            if (totalAlunos > 0) {
                int num;
                printf("Digite o número do aluno que deseja deletar: ");
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
                    printf("Número inválido!\n");
                }
            } else {
                printf("Nenhum aluno registrado para deletar.\n");
            }
        } else if (opcao >= 4 || opcao <= 0) {
            printf("Essa opção não está disponível!\n");
        }
    } while (opcao != 4);  // O programa continua até o usuário escolher a opção de sair

    printf("Saindo do programa...\n");
    return 0;
}
