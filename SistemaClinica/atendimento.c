#include <stdio.h>
#include "atendimento.h"
#include "fila.h"

static int emAtendimento = -1;

void consultarProximaSenha() {

    int indice = proximaSenha();

    if (indice == -1) {
        printf("\nNao existem pacientes aguardando.\n");
        return;
    }

    Paciente p = obterPaciente(indice);

    printf("\nProxima senha: %s\n", p.senha);
    printf("Categoria: %s\n", p.categoria);
}

void chamarPaciente() {

    if (emAtendimento != -1) {
        printf("\nFinalize o atendimento atual primeiro!\n");
        return;
    }

    int indice = proximaSenha();

    if (indice == -1) {
        printf("\nFila vazia!\n");
        return;
    }

    removerDaFila(indice);

    emAtendimento = indice;

    Paciente p = obterPaciente(indice);

    printf("\n===== PACIENTE CHAMADO =====\n");
    printf("Senha: %s\n", p.senha);
    printf("Categoria: %s\n", p.categoria);
}

void finalizarAtendimento() {

    if (emAtendimento == -1) {
        printf("\nNenhum atendimento em andamento.\n");
        return;
    }

    Paciente p = obterPaciente(emAtendimento);

    printf("\nAtendimento %s finalizado!\n", p.senha);

    emAtendimento = -1;
}

int pacienteEmAtendimento() {
    return emAtendimento;
}