#include <stdio.h> 
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Victor Cardoso Mendonça
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 17/09/2026
Objetivo    : Adivinhar a estrutura de dados utilizada.
Dificuldade : Fazer a função da fila de prioridade.
Uso de IA   : Ajudou com erros de sintaxe e com a função da fila de prioridade.
-------------------------------------------------------------------------- */ 

int buscaBinaria(int v[], int alvo, int inicio, int fim){
    if (inicio > fim) return -1;
    int meio = (inicio+fim)/2;
    if (v[meio] == alvo) return meio;
    if (v[meio] < alvo) return buscaBinaria(v, alvo, meio+1, fim);
    if (v[meio] > alvo) return buscaBinaria(v, alvo, inicio, meio-1);
}
 
 
 
int main() {
    int n, m; // qtd de casas e qtd de entregas
    scanf("%d %d", &n, &m);
    int ordem_casas[n];
    for (int i=0; i<n; i++){
        scanf("%d", &ordem_casas[i]);
    }
    int ordem_entregas[m];
    for (int i=0; i<m; i++){
        scanf("%d", &ordem_entregas[i]);
    }
    int pos_casa_anterior = 0; // posição de inicio
    int passos = 0;
    for (int i=0; i<m; i++){
        
        int alvo = ordem_entregas[i];
        
        int pos_casa_que_fui = buscaBinaria(ordem_casas, alvo, 0, n-1);
        
        // para simular o módulo com esse if e else
        // acumula a qtd de passos
        if (pos_casa_que_fui >= pos_casa_anterior){
            passos = passos + (pos_casa_que_fui - pos_casa_anterior);
        }
        
        else {
            passos = passos + (pos_casa_anterior - pos_casa_que_fui);
        }
        
        pos_casa_anterior = pos_casa_que_fui;
    }
    printf("%d\n", passos);
    return 0;
}