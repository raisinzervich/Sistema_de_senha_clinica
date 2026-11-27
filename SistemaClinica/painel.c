#include <stdio.h>
#include "painel.h"
#include "fila.h"
#include "atendimento.h"

// Mostrar painel
void mostrarPainel() {

    printf("\n================================\n");
    printf("       PAINEL DA CLINICA\n");
    printf("================================\n");

    int atual = pacienteEmAtendimento();

    if (atual == -1) {
        printf("Em atendimento: Nenhum\n");
    } else {
        
        printf("Atendimento em andamento.\n");
    }

    printf("\n----- PROXIMA CHAMADA -----\n");
    consultarProximaSenha();

    printf("\n----- QUANTIDADE EM ESPERA -----\n");

    printf("Urgentes: %d\n", quantidadeUrgente());
    printf("Preferenciais: %d\n", quantidadePreferencial());
    printf("Normais: %d\n", quantidadeNormal());

    printf("Total: %d\n",
        quantidadeUrgente() +
        quantidadePreferencial() +
        quantidadeNormal());

    printf("================================\n");
}