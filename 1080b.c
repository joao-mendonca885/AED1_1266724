#include <stdio.h>
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Victor Cardoso Mendonça
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : Nao lembro
Objetivo    : Maior elemento de um vetor.
Dificuldade : Nenhuma especial.
Uso de IA   : Nada
-------------------------------------------------------------------------- */



int main(){
    int *v;
    v = (int *) malloc(100 * sizeof(int));
    int maior, pos;
    int i; 
    for (i=0; i<100; i++){
        scanf("%d", &v[i]);
        if (i==0) {
            maior = v[i];
            pos = i;
        }
        else {
            if (v[i] > maior){
                pos = i;
                maior = v[i];
            } 
        }
    }
    printf("%d\n", maior);
    printf("%d\n", pos+1);
    free(v);
    return 0;
}


