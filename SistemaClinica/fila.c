#include <stdio.h>
#include "fila.h"

static Paciente pacientes[MAX];

static int filaN[MAX], filaP[MAX], filaU[MAX];

static int inicioN = 0, fimN = 0;
static int inicioP = 0, fimP = 0;
static int inicioU = 0, fimU = 0;

static int total = 0;

void inserirFila(Paciente p, int categoria) {

    if (total >= MAX) {
        printf("Limite de pacientes atingido!\n");
        return;
    }

    pacientes[total] = p;

    if (categoria == 3)
        filaU[fimU++] = total;

    else if (categoria == 2)
        filaP[fimP++] = total;

    else
        filaN[fimN++] = total;

    total++;
}

int proximaSenha() {

    if (inicioU < fimU)
        return filaU[inicioU];

    if (inicioP < fimP)
        return filaP[inicioP];

    if (inicioN < fimN)
        return filaN[inicioN];

    return -1;
}

Paciente obterPaciente(int indice) {
    return pacientes[indice];
}

void removerDaFila(int indice) {

    if (inicioU < fimU && filaU[inicioU] == indice)
        inicioU++;

    else if (inicioP < fimP && filaP[inicioP] == indice)
        inicioP++;

    else if (inicioN < fimN && filaN[inicioN] == indice)
        inicioN++;
}

int quantidadeUrgente() {
    return fimU - inicioU;
}

int quantidadePreferencial() {
    return fimP - inicioP;
}

int quantidadeNormal() {
    return fimN - inicioN;
}