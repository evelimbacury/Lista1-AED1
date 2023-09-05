// Evelim

#include <stdio.h>

int fetuccine(int n1, int n2, int cont){
    int resultado;

    if(cont == 10){
        return somatorio(n1, n2, resultado);;
    }
    
    printf("%d\n", n1);
    if(cont%2 == 0){
        resultado = n2 - n1;
    }else{
        resultado = n2 + n1;
    }

    somatorio(n1, n2, resultado);

    n1 = n2;
    n2 = resultado;
    
    fetuccine(n1, n2, cont+1);
}

int somatorio(int n1, int n2, int resultado){
    int soma = n1 + n2;

    soma += resultado;

    return soma;
}


int main(){
    int num1, num2, cont = 1;

    printf("Série Fetuccine\n");
    printf("Insira o primeiro numero: ");
    scanf("%d", &num1);
    printf("Insira o segundo numero: ");
    scanf("%d", &num2);


    int soma = fetuccine(num1, num2, cont);

    printf("\nA soma e %d\n", soma);
}