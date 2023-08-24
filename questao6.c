#include <stdio.h>

int contarNumRepetidos(int *vetor, int quant, int tam){
    
}

int main(){
    int t = 5, vetor[t], quant = 0, i;

    printf("Insira 5 números\n");

    for(i = 0; i < t; i++){
        printf("Num %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    contarNumRepetidos(vetor, quant, t);
    //printf(quant);
}