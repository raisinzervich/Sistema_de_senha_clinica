#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "fila.h"

int contadorN = 0;
int contadorP = 0;
int contadorU = 0;

int classificarPaciente(Paciente p) {

    if (p.idade > 80) {
        return 3;
    }

    if (p.gestante ||
        p.lactante ||
        p.necessidadeEspecial ||
        p.obeso ||
        (p.genero == 'F' && p.idade >= 60) ||
        (p.genero == 'M' && p.idade >= 65)) {
        return 2;
    }

    return 1;
}

void gerarSenha(Paciente *p, int categoria) {

    if (categoria == 3) {
        contadorU++;
        sprintf(p->senha, "U%03d", contadorU);
        strcpy(p->categoria, "Urgente");
    }
    else if (categoria == 2) {
        contadorP++;
        sprintf(p->senha, "P%03d", contadorP);
        strcpy(p->categoria, "Preferencial");
    }
    else {
        contadorN++;
        sprintf(p->senha, "N%03d", contadorN);
        strcpy(p->categoria, "Normal");
    }
}

void cadastrarPaciente() {

    Paciente p;

    printf("\n===== CADASTRO DE PACIENTE =====\n");

    printf("Genero (M/F): ");
    scanf(" %c", &p.genero);

    if (p.genero >= 'a' && p.genero <= 'z')
        p.genero -= 32;

    while (p.genero != 'M' && p.genero != 'F') {
        printf("Genero invalido. Digite M ou F: ");
        scanf(" %c", &p.genero);

        if (p.genero >= 'a' && p.genero <= 'z')
            p.genero -= 32;
    }

    printf("Idade: ");
    scanf("%d", &p.idade);

    while (p.idade < 0 || p.idade > 120) {
        printf("Idade invalida. Digite novamente: ");
        scanf("%d", &p.idade);
    }

    p.gestante = 0;
    p.lactante = 0;

    if (p.genero == 'F') {
        printf("Gestante? (1-Sim / 0-Nao): ");
        scanf("%d", &p.gestante);

        printf("Lactante? (1-Sim / 0-Nao): ");
        scanf("%d", &p.lactante);
    }

    printf("Necessidade especial? (1-Sim / 0-Nao): ");
    scanf("%d", &p.necessidadeEspecial);

    printf("Possui obesidade? (1-Sim / 0-Nao): ");
    scanf("%d", &p.obeso);

    int categoria = classificarPaciente(p);

    gerarSenha(&p, categoria);

    printf("\nSenha gerada: %s\n", p.senha);
    printf("Categoria: %s\n", p.categoria);

    inserirFila(p, categoria);
}