#include <stdio.h>
 
int main(){
    int n;
    int menor, pos;
    scanf("%d", &n);
    if (n<=0) return 1;
    int v[n];
    for (int i=0; i<n; i++){
        scanf("%d", &v[i]);
        /*já encontrando o menor elemento nesse loop para
        reduzir o número de comparações, nesse caso fica O(n)*/         
        if (i == 0){
            menor = v[i];
            pos = i;
        }
        else {
            if (menor > v[i]){
                menor = v[i];
                pos  = i;
            }
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);
    return 0;
}