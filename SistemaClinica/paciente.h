#ifndef PACIENTE_H
#define PACIENTE_H

#define MAX 1000

typedef struct {
    char genero;
    int idade;
    int gestante;
    int lactante;
    int necessidadeEspecial;
    int obeso;
    char senha[10];
    char categoria[20];
} Paciente;

int classificarPaciente(Paciente p);
void gerarSenha(Paciente *p, int categoria);
void cadastrarPaciente();

#endif