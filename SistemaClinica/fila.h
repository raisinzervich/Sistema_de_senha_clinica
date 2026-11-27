#ifndef FILA_H
#define FILA_H

#include "paciente.h"

void inserirFila(Paciente p, int categoria);
int proximaSenha();
Paciente obterPaciente(int indice);
void removerDaFila(int indice);
int quantidadeUrgente();
int quantidadePreferencial();
int quantidadeNormal();

#endif