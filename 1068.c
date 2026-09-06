/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Victor Cardoso Mendonça
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 05/09/2026
Objetivo    : Cartas descartadas e cartas restantes.
Dificuldade : linha 40, não sabia como implementar o EOF. Linha 35, estava retornando 1 ao invés de j == 0.
Uso de IA   : Uso de IA quando meu código não dava certo e eu não sabia o por que.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ideia desse algorítimo é o mesmo que eu fiz em python

/* Criamos um vetor de caracteres pilha e a cada vez que a gente
encontrar um ")" a gente checa se o elemento anterior era um "("*/

int esta_correto(char s[]){
    int len_s = strlen(s);
    int pilha[len_s]; // para cada "(" que a gente encontrar, a gente empilha, e para cada ")" que a gente encontrar, a gente desempilha
    int j = 0; // contador de elementos na pilha
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == ')'){
            if (j != 0 && pilha[j-1] == '(') j--; // desempilha
            else return 0;
        }
        else if (s[i] == '('){
            pilha[j] = '('; // empilha
            j++;
        }
    }
    return j == 0; // Se a pilha estiver vazia, então está correto -> errando isso
}

int main(){
    char s[1000];
    while (scanf(" %999[^\n]", s) == 1){ // Enquanto houver entrada, a gente vai ler a string
        if (esta_correto(s)) printf("correct\n");
        else printf("incorrect\n");
    }
    return 0;
}
