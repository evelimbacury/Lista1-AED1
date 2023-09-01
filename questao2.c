// Evelim

#include <stdio.h>

int fetuccine(int n1, int n2, int cont){
    int resultado;

    if(cont > 10){
        return 1;
    }
    
    printf("%d\n", n1);
    if(cont%2 == 0){
        resultado = n2 - n1;
    }else{
        resultado = n2 + n1;
    }
    n1 = n2;
    n2 = resultado;
    fetuccine(n1, n2, cont+1);
}

int main(){
    int num1, num2, cont = 1, res;

    printf("Série Fetuccine\n");
    printf("Insira o primeiro numero: ");
    scanf("%d", &num1);
    printf("Insira o segundo numero: ");
    scanf("%d", &num2);


    fetuccine(num1, num2, cont);

    // printf("\n");
    // for(int i = 1; i <= 10; i++){

    //     printf("%d\n", num1);
    //     if(i % 2 == 0){
    //         res = num2 - num1;
    //     }else{
    //         res = num2 + num1;
    //     }
    //     num1 = num2;
    //     num2 = res;
    // }

}