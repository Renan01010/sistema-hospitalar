#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"

// Lucas - função de criação de criar paciente
Paciente* criarPaciente(int id, char*nome, int idade, char*sintoma){ 
    // verifica se já existe paciente com esse ID
    if (buscarPacientePorID(id) != NULL) {
        printf("Erro: ja existe um paciente com ID %d\n", id);
        return NULL;
    }

    Paciente* p = (Paciente*) malloc(sizeof(Paciente));    //faz alocação de memória necessaria

    //verifica se a alocação de memória realmente foi realizada correta
    if(p == NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    p->id = id; //atribui valores aos atributos do paciente
    strcpy(p->nome, nome);//copia o nome para o atributo nome do paciente
    p->idade = idade; //atribui idade
    strcpy(p->sintoma, sintoma); // copia o sintoma para o atributo sintoma do paciente
    p->prioridade = -1; //inicializa prioridade como 0
    p->tempoAtendimento = 0;
    p->prox = NULL; //inicializa o próximo paciente como NULL
    // adiciona o paciente à lista global de pacientes
    adicionarPacienteLista(p);
    return p; 
}

// Lista global de pacientes (armazenamento simples em memória)
static Paciente *listaPacientes = NULL;

void inicializarLista(void){
    listaPacientes = NULL;
}

void adicionarPacienteLista(Paciente *p){
    if (p == NULL) return;
    p->prox = listaPacientes;
    listaPacientes = p;
}

Paciente* buscarPacientePorID(int id){
    Paciente *atual = listaPacientes;
    while (atual != NULL) {
        if (atual->id == id) {
            return atual;  // encontrou o paciente
        }
        atual = atual->prox;
    }
    return NULL; // não encontrou
}
