#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
/* Aprendizados:
*/

/* Ordem de precedência dos operadores
/ 1. ()
/ 2. ^
/ 3. * /
/ 4. + -
*/

typedef struct lista{
    char operador; // armazena o operador
    int prioridade; // guarda a prioridade do operador
    struct lista *anterior; // aponta para o elemento anterior
}lista;

typedef struct{
    lista *topo; // aponta para a lista
}pilha;

char operadores[] = "^*/+-"; // ordem: [0 > 1,2(2) > 3,4(4)]


char desempilhar(pilha *p){
    if (p->topo == NULL){ // pilha vazia
        printf("Pilha vazia");
        return '\0';
    }
    lista *lixo = p->topo;
    char operador = p->topo->operador;
    p->topo = p->topo->anterior; // já serve para 1 ou mais elementos
    free(lixo);
    return operador;
}

void empilhar(pilha *p, char c, int i){
    lista *novo = (lista*) malloc(sizeof(lista));
    if (novo == NULL){
        printf("Erro ao alocar memória");
        return;
    }
    novo->operador = c;
    novo->prioridade = i;
    novo->anterior = p->topo;
    p->topo = novo;
}

void verificacao_operadores(char c, pilha *p, int i){
    
    if (i == 1 || i == 3) i++;
    if (p->topo != NULL && p->topo->operador == '('){
        empilhar(p, c, i);
    }
    else if (p->topo == NULL) empilhar(p, c, i);
    //operador atual tem maior prioridade -> empilha
            // * == 2           - == 4
    else if (p->topo->prioridade >  i) {
        empilhar(p, c, i);
    }
    else {
        while (p->topo != NULL && p->topo->operador != '(' && p->topo->prioridade <= i){
            printf("%c", desempilhar(p));
        }
        empilhar(p, c, i);
    }
}

void verificacao_tipo(char c, pilha *p){
    int len_operadores = strlen(operadores);
    
    for (int i=0; i<len_operadores; i++){
        if(c == operadores[i]){
            verificacao_operadores(c, p, i);
            return; // se entrou aqui, quer dizer que é um operador
        }
    }
    if (c == ')') { // se apareceu isso, quer dizer que tem um "(" correspondente
        while (p->topo != NULL && p->topo->operador != '('){ 
            printf("%c", desempilhar(p));
        }
        desempilhar(p); // desempilha o "("
    }
    else if (c == '('){
        empilhar(p, c, -1); // -1 prioridade max
    }
    else printf("%c", c); // é letra ou número, então imprime
}



int main() {
    int n;
    pilha p = {NULL};
    scanf("%d", &n); // no buffer ainda ficaria o '\n'
    getchar(); // para limpar o buffer do '\n'
    char c;
    for (int i = 0; i<n; i++){
        while (scanf("%c", &c) == 1 && c != '\n'){
            verificacao_tipo(c, &p);
        }
        if (p.topo != NULL){
            while (p.topo != NULL){
                printf("%c", desempilhar(&p));
            }
        }
        printf("\n");
    }
    return 0;
}