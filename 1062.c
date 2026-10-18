#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Victor Cardoso Mendonça
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 17/09/2026
Objetivo    : Saber se é possível organizar os vagoes de um trem, usando um desvio como pilha.
Dificuldade : erros pontuais como a variavel do indice do vetor estourando e casos em que o usuario digita 0 duas vezes seguidas.
Uso de IA   : Ajudou com erros de sintaxe e na identificação de erros pontuais, como os dois casos citados acima.
-------------------------------------------------------------------------- */ 

/* possible operations
    1 - Trem A -> Trem B
    2 - Trem A -> Desvio
    3 - Desvio -> Trem B
*/

/* behavior of each data
    Trem A: queue
    Trem B: Output
    Desvio: Stack
*/

typedef struct celula{
    int conteudo;
    struct celula *prox;
}celula;

typedef struct{
    celula *topo;
}pilha;


void empilhar(pilha *p, int conteudo){
    celula *nova = (celula *) malloc(sizeof(celula));
    if (nova == NULL){
        return;
    }
    nova->conteudo = conteudo;
    nova->prox = p->topo;
    p->topo = nova;
}

int desempilhar(pilha *p){
    if (p->topo == NULL){
        return -1;
    }
    celula *lixo = p->topo;
    int numero = lixo->conteudo;
    if (p->topo->prox == NULL){
        p->topo = NULL;
    }
    else {
        p->topo = p->topo->prox;
    }
    free(lixo);
    return numero;
}


int eh_possivel(int vb[], int va[], pilha *d, int n){
    int i = 0; // inicio do vetor va;
    int j = 0; // inicio do vetor vb;
    // enquanto tiver vagoes no trem A ou tiver vagoes no desvio
    while (i < n || d->topo != NULL){
        if (d->topo != NULL && d->topo->conteudo == vb[j]){
            j++;
            desempilhar(d);
        }
        else if (i < n && va[i] == vb[j]) {i++; j++;} // se o va[i] coincide com o vb[i] incrementa os 2
        else if (i < n){
            empilhar(d, va[i]);
            i++;
        }
        else return 0;
    }
    return 1;
}


int main(){
    
    int n;
    do {
        int loop = 1;
        scanf("%d", &n);
        if (n==0) return 0;
        while (loop){
            int vb[n];
            int va[n];
            pilha *desvio = (pilha *) malloc(sizeof(pilha));
            desvio->topo = NULL;
            for (int i = 0; i < n; i++){
                scanf(" %d", &vb[i]); // espaço antes do %d para ignorar todos os espaços e quebras de linhas anteriores
                if (vb[0] == 0) {loop = 0; printf("\n"); break;}
                va[i] = i+1;
            }
            if (!loop) break;
            int resultado = eh_possivel(vb, va, desvio, n);
            if (resultado) printf("Yes\n");
            else{ 
                printf("No\n");
                while (desvio->topo != NULL){
                    desempilhar(desvio);
                }
            }
            free(desvio);
        }
    }while (n != 0);  
    

    return 0;
}