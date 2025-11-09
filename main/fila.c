#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "paciente.h"


//Renan - Inicializar a fila
void inicializar(Fila *paciente){
    for(int i=0; i<5; i++){
    paciente->inicio[i] = NULL;
    paciente->fim[i] = NULL;
    paciente->tamanho[i] = 0;
    }
}
// Leticia - Verificação da fila vazia
bool vazia(Fila *f){
    return(f->tamanho == 0); // retorna true se a fila estiver vazia
}

// Kauan - Enfileirar paciente na fila da sua prioridade
bool enfileirar(Fila *f, Paciente *p){
    if(f || p == NULL){ // verifica se a fila ou o paciente são nulos
        return false;
    }
    int prioridade = p->prioridade -1;
    if(f->fim[prioridade] == NULL){ //caso esteja vazia a fila
        f->fim[prioridade] = f->inicio[prioridade] = p; //inicio e fim apontam para o novo paciente
    }
    else{
        f->fim[prioridade]->prox = p; // o próximo do fim atual aponta para o novo paciente
        f->fim[prioridade] = p; // o fim da fila agora é o novo paciente
    }
    f->tamanho[prioridade]++; // incrementa o tamanho da fila
    return true;
}
// Lucas - Remover paciente da fila após atendimento
bool pacienteAtendido(Fila *f){
    int prioridade =0;
    for(int i=0; i<5; i++){
       if(f->fim[i] != NULL){  //caso esteja vazia a fila
            break;
            prioridade = i;
        }
    }
    if(prioridade == 0){
        printf("znNao existem pacientes na fila!!\n");
        return false;
    }
    Paciente *atual = f->inicio[prioridade]; 
    printf("\nPaciente %s atendido!!\n Quanto tempo ele levou para ser atendido\n?", atual->nome);
    scanf("%d", &atual->tempoAtendimento);
    
    f->inicio[prioridade] = atual;
    if(f->inicio[prioridade] == NULL){ // caso fila fique vazia
        f-fim[prioridade] =NULL; 
    }

    f->tamanho[prioridade] --;
    free(atual);
    return true;
    
}
// Renan - Consultar o elemento na frente da fila sem removê-lo
bool frente(Fila *f, int id){
    if(vazia(f)){
        printf("Esta vazia, nao tem elementos para consultar.\n");
        return false;
    }
    
    if (f->inicio[i] != NULL){
        f->inicio[i]->id, f->inicio[i]->nome; //exibe id e nome do paciente
    }
    
    return true;
}


//Leticia - Retornar o tamanho da fila
int tamanho_fila(Fila *f){
    return f->tamanho; // retorna o tamanho da fila
}

//Kauan - Exibir fila de espera
void exibir(Fila *f, Paciente *p){
     if (vazia(f)){
        printf("Fila de espera vazia\n");
        return; // sai da função se as filas estiverem vazias
    }

    printf("==== Fila de espera ====\n");
    
    for(int i = 0; i < 5; i++;){
    Paciente* pos = f->inicio[i]; // posição inicial da fila

    if (pos == NULL) continue; // se a fila estiver vazia pula pra proxima
        
        while (pos != NULL){
        printf("%d  Nome: %c   Idade: %d  Sintomas: %c  Tempo de espera: %d\n", id, nome, idade, sintoma, tempoAtendimento); // exibe os dados do paciente
        pos = pos->prox;
        }
    }
}

//Lucas - Limpar filas de espera
void limpar(Fila *f){
    inicializar(f);
    printf("fila limpa!");
}