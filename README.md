# Sistema_de_senha_clinica
# Sistema de Gerenciamento de Filas - Clínica Médica

## Descrição
Sistema desenvolvido em linguagem C para gerenciar senhas e organizar filas de atendimento em uma clínica médica.

## Objetivo
Cadastrar pacientes, identificar automaticamente suas prioridades e organizar a ordem de atendimento.

## Funcionalidades
- Cadastro de pacientes.
- Classificação automática em Normal, Preferencial e Urgente.
- Geração de senhas sequenciais.
- Organização das filas por prioridade.
- Consulta da próxima senha.
- Chamada de pacientes.
- Finalização de atendimentos.
- Painel de acompanhamento das filas.

## Regras de Prioridade

| Senha | Categoria | Condição |
|---|---|---|
| N001 | Normal | Sem prioridade |
| P001 | Preferencial | Gestantes, lactantes, pessoas com necessidades especiais, obesidade e critérios de idade |
| U001 | Urgente | Pessoas com mais de 80 anos |

Ordem de atendimento: Urgente, Preferencial e Normal.

## Tecnologias utilizadas
- Linguagem C
- Online GDB
- GitHub

## Organização do projeto
- main.c
- paciente.h
- paciente.c
- fila.h
- fila.c
- atendimento.h
- atendimento.c
- painel.h
- painel.c

## Como executar
Compile todos os arquivos `.c` juntos em um compilador C e execute o programa.

## Autores
Projeto acadêmico desenvolvido para atividade de programação em linguagem C.
