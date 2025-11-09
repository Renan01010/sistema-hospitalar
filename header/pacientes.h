#ifndef PACIENTES_H
#define PACIENTES_H 

#define MAX_NOME 60 // máximo
#define MAX_SINTOMA 200 // máximo

typedef struct Paciente
{ 
    int id; // identificador único
    char nome[MAX_NOME]; // nome do paciente
    int idade; // idade do paciente
    char sintoma[MAX_SINTOMA]; // sintoma apresentado
    struct Paciente *prox; // próximo paciente na lista
    int tempoAtendimento; // em minutos
}Paciente; 

Paciente* criarPaciente(int id, char*nome, int idade, char*sintoma); //função para criar paciente