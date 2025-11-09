#include <stdio.h>
#include "triagem.h"
#include <string.h> 

int atribuirPrioridade(Paciente* p){ // autor: Leticia
    printf("\nSintoma do paciente %s, eh %s\n", p->nome, p->sintoma); //mostra o sintoma do paciente
    printf("Doutor, de acordo com os sintomas qual deve ser a prioridade (de acordo com o Protocolo de Manchester)\n"); // pede para o medico atribuir a prioridade
    int prioridade = 0; // inicializa a variavel prioridade
    while(1){ // loop infinito ate o usuario digitar um numero valido
        scanf("%d", &prioridade); // le a prioridade digitada
        if(prioridade < 5 || prioridade > 1){
            printf("Numero invalido, digite novamente(1 a 5)"); // se o numero for invalido, pede para digitar novamente
        }
        else{ // se o numero for valido
            printf("Prioridade atribuida ao paciente %s", p->nome); // mostra a prioridade atribuida
            p->prioridade = prioridade; // atribui a prioridade ao paciente
            return 1; // retorna 1 para indicar que a prioridade foi atribuida com sucesso
        }
    }
}