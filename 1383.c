#include <stdio.h>
// problema do sudoko 1383 do beecrowd
 /*your task is to write a program that 
 checks whether a filled matrix is a solution to the puzzle or not.*/ 
int linha_ou_coluna_esta_errada(int v[]){
    for (int i =0; i<9; i++){
        if (v[i] != 1) return 1;
    }
    return 0;
}

int teste_colunas(int m[9][9]){
    for (int j=0; j<9; j++){
        int v[9] = {0};
        for (int i=0; i<9; i++){
            v[m[i][j]-1]++;
        }
        if (linha_ou_coluna_esta_errada(v)){
            return 0;
        }
    }
    return 1;
}

int teste_linhas(int m[9][9]){
    for (int i=0; i<9; i++){
        int v[9] = {0};
        for (int j=0; j<9; j++){
            v[m[i][j]-1]++;
        }
        if (linha_ou_coluna_esta_errada(v)){
            return 0;
        }
    }
    return 1;
}

int teste_blocos(int m[9][9]){
    for (int l=0; l < 9; l=l+3){
        for(int c=0; c < 9; c=c+3){
            int v[9] = {0}; // cada bloco analisado, reinicia o vetor de contagem
            for (int i=l; i<l+3; i++){
                for (int j=c ; j< c+3 ; j++){
                    v[m[i][j]-1]++;
                }
            }
            if (linha_ou_coluna_esta_errada(v)) return 0;
        }
    }
    return 1;        
}

int instancia(int m[9][9]){
    int esta_verdadeiro;
    esta_verdadeiro = teste_linhas(m);
    if (!(esta_verdadeiro)) return 0;
    esta_verdadeiro = teste_colunas(m);
    if (!(esta_verdadeiro)) return 0;
    esta_verdadeiro = teste_blocos(m);
    if (!(esta_verdadeiro)) return 0;
    return 1;
}


int main() {
    int m[9][9];
    int n;
    scanf("%d", &n);
    for (int k=0; k<n; k++){
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                scanf("%d", &m[i][j]);
            }
        }
        int resultado = instancia(m);
        printf("Instancia %d\n", k+1);
        if (resultado) printf("SIM\n\n");
        else printf("NAO\n\n");
    }
    return 0;
}