#include <stdio.h>
#include <stdlib.h>
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Victor Cardoso Mendonça
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 03/09/2026
Objetivo    : Cartas descartadas e cartas restantes.
Dificuldade : Sintaxe, me confundi bastante com ponteiro para ponteiro.
Uso de IA   : Uso de IA para correção de sintaxe, desenvolvimento da lógica e explicação dos pontos de dúvida.
-------------------------------------------------------------------------- */



typedef struct celula{
    int conteudo;
    struct celula *seg;
}celula;



typedef struct{
    celula *inicio;
    celula *fim;
}fila;

int desenfileira(fila *f){
    celula *lixo = f->inicio;
    int valor = lixo->conteudo;
    f->inicio = f->inicio->seg; // o inicio passa a ser o próximo elemento da lista
    if (f->inicio == NULL) f->fim = NULL; // se a lista ficar vazia, fim aponta para NULL
    free(lixo);
    return valor;
}


void enfileira(fila *f, int x){
    celula *nova = (celula*) malloc(sizeof(celula));
    if (nova == NULL){
        printf("Erro de alocacao");
        return;
    }
    nova->conteudo = x;
    nova->seg = NULL; // aponta para NULL, pois será o último elemento da lista
    if (f->fim == NULL) { // lista vazia
        f->inicio = nova;
        f->fim = nova;
    } else {
        f->fim->seg = nova; //ultimo aponta para nova
        f->fim = nova; // ultimo passa a ser a nova
    }
}

// montando lista de [1:n+1]
void montar_baralho(fila *baralho, int n){
    for(int i = 1; i<=n; i++){
        enfileira(baralho, i);
    }
}

 
int main() {
    fila baralho = {NULL, NULL};
    int n; // numero de cartas
    do {
        scanf("%d", &n);
        if(n == 0) break;
        montar_baralho(&baralho, n); // criando lista encadeada 1 a n
        printf("Discarded cards: ");
        while (baralho.inicio != baralho.fim){ // enquanto houver mais de um elento
            int discard = desenfileira(&baralho);
            if (baralho.inicio != baralho.fim) printf("%d, ", discard); 
            else printf("%d", discard); // se for o ultimo elemento, não coloca a vírgula
            enfileira(&baralho, desenfileira(&baralho)); // ja desenfileiro e enfilerio de uma vez
        } 
        printf("\nRemaining card: %d\n", desenfileira(&baralho));       
    } while (n != 0);
    return 0;
}