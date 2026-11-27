#include <stdio.h>
#include "paciente.h"
#include "atendimento.h"
#include "painel.h"

int main() {
    int opcao;

    do {

        printf("\n================================\n");
        printf("   SISTEMA DE FILAS CLINICA\n");
        printf("================================\n");

        printf("1 - Cadastrar paciente\n");
        printf("2 - Consultar proxima senha\n");
        printf("3 - Chamar paciente\n");
        printf("4 - Finalizar atendimento\n");
        printf("5 - Mostrar painel\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                cadastrarPaciente();
                break;

            case 2:
                consultarProximaSenha();
                break;

            case 3:
                chamarPaciente();
                break;

            case 4:
                finalizarAtendimento();
                break;

            case 5:
                mostrarPainel();
                break;

            case 0:
                printf("\nSistema encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}