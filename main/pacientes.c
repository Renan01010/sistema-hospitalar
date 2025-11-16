#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"

// Lucas - função de criação de criar paciente
Paciente* criarPaciente(int id, char*nome, int idade, char*sintoma){ 
    Paciente* p = (Paciente*) malloc(sizeof(Paciente));    //faz alocação de memória necessaria

    //verifica se a alocação de memória realmente foi realizada correta
    if(p == NULL){
        printf("Erro ao alocar memoria");
        return NULL;
    }

    p->id = id; //atribui valores aos atributos do paciente
    strcpy(p->nome, nome);//copia o nome para o atributo nome do paciente
    p->idade = idade; //atribui idade
    strcpy(p->sintoma, sintoma); // copia o sintoma para o atributo sintoma do paciente
    p->prioridade = 0; //inicializa prioridade como 0
    p->tempoAtendimento = 0;
    p->prox = NULL; //inicializa o próximo paciente como NULL
    return p; 
}

Paciente* buscarPacientePorID(Paciente *lista, int id)
{
    Paciente *atual = lista;

    while (atual != NULL) {
        if (atual->id == id) {
            return atual;  // encontrou o paciente
        }
        atual = atual->prox;
    }

    return NULL; // não encontrou
}