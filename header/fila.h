#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

//estrutura da fila
typedef struct {
    Paciente* inicio[5];
    Paciente* fim[5];
    int tamanho[5];
} Fila;


//protótipo das funções
void inicializar(Fila *paciente);
bool vazia(Fila *f);
bool enfileirar(Fila *f, Paciente *p);
bool pacienteAtendido(Fila *f, Paciente *p);
bool frente(Fila *f, int id);
int tamanho_fila(Fila *f);
void exibir(Fila *f, Paciente *p);
void limpar(Fila *f);

#endif