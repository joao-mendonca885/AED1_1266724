#include <stdio.h>
 
int main(){
    int v[100];
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
    return 0;
}