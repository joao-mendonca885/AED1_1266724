#include <stdio.h>
#include <stdlib.h>

/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Victor Cardoso Mendonça
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1340
Data        : 17/09/2026
Objetivo    : Adivinhar a estrutura de dados utilizada.
Dificuldade : Fazer a função da fila de prioridade.
Uso de IA   : Ajudou com erros de sintaxe e com a função da fila de prioridade.
-------------------------------------------------------------------------- */ 

// se o primeiro elemento retirado não for o primeiro da fila, podemos retornar 0
int fila(int sequencia_tipos[], int sequencia_elementos[], int n){
    int fila[n];
    int inicio = 0;
    int fim = 0;
    for (int i = 0; i<n; i++){
        if (sequencia_tipos[i] == 1){
            fila[fim] = sequencia_elementos[i]; //adiciona um elemento no final da fila
            fim++; // incrementa
        }
        else if (sequencia_tipos[i] == 2){
            if (fim <= 0) return 0; //tentou retirar de uma fila vazia
            if (fila[inicio] != sequencia_elementos[i]) return 0;//se o primeiro da fila não for o elemento que ele retirou
            else inicio++;
        }
    }
    return 1;
}

// se o elemento retirado não for o último, não é pilha
int pilha(int sequencia_tipos[], int sequencia_elementos[], int n){
    int topo = 0;
    int pilha[n];
    for (int i = 0; i<n; i++){
        
        int tipo = sequencia_tipos[i];
        int elemento = sequencia_elementos[i];

        if (tipo == 1){ //empilha e o topo ocupa a pos vazia 
            pilha[topo] = elemento;
            topo++;
        }
        
        if (tipo == 2){
            if (topo <= 0) return 0; // vai estar retirando de uma pilha vazia
            if (elemento != pilha[topo-1]) return 0; // se o elemento retirado, for diferente do elemento do topo
            else topo--; // topo desempilha
        }
    }
    return 1;
}

int prioridade(int fila[], int inicio, int fim){
    int prioridade = fila[inicio];
    int indice = inicio;
    for (int i = inicio+1; i<fim; i++){
        if (prioridade < fila[i]) {
            prioridade = fila[i];
            indice = i;
        }
    }
    int temp;
    temp = fila[fim-1];
    fila[fim-1] = prioridade;
    fila[indice] = temp;
    return prioridade;
}

// ideia foi trocar de posição o maior elemento com o último, e desincrementar o fim
int fila_prioridade(int sequencia_tipos[], int sequencia_elementos[], int n){
    int fila[n];
    int inicio = 0;
    int fim = 0;
    for (int i = 0; i<n; i++){
        
        int tipo = sequencia_tipos[i];
        int elemento = sequencia_elementos[i];
        
        if (tipo == 1){
            fila[fim] = elemento;
            fim++;
        }

        else if (tipo == 2){
            if (fim <= 0) return 0;
            if (elemento != prioridade(fila, inicio, fim)) return 0;
            else fim--;
        }
    } 
    return 1;
}


void cheque(int sequencia_tipos[], int sequencia_elementos[], int n){
    int eh_fila = fila(sequencia_tipos, sequencia_elementos, n);
    int eh_pilha = pilha(sequencia_tipos, sequencia_elementos, n);
    int eh_fila_prioridade = fila_prioridade(sequencia_tipos, sequencia_elementos, n);
    
    if (eh_fila && eh_pilha && eh_fila_prioridade){ // só adicionou elementos
        printf("not sure\n");
        return;
    }
    else if (eh_fila && eh_fila_prioridade){ //os maiores podem ser postos no início da fila
        printf("not sure\n");
        return;
    }
    else if (eh_pilha && eh_fila_prioridade){
        printf("not sure\n");
    }
    else if(!eh_pilha && !eh_fila && !eh_fila_prioridade){
        printf("impossible\n");
        return;
    }
    else if(eh_pilha){
        printf("stack\n");
        return;
    }
    else if(eh_fila){
        printf("queue\n");
        return;
    }
    else printf("priority queue\n");
}

int main(){
    int n; // numero de linhas
    int tipo;
    int elemento;
    while (scanf("%d", &n) == 1){
        int sequencia_tipos[n];
        int sequencia_elementos[n];
        for (int i = 0; i<n; i++){
            scanf("%d %d", &tipo, &elemento);
            sequencia_tipos[i] = tipo;
            sequencia_elementos[i] = elemento;
        }
        cheque(sequencia_tipos, sequencia_elementos, n);
    }
    return 0;
}