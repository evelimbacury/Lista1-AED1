//Gabriel

#include<stdio.h>


void imprintmir(int num){
    printf("%d\n", num);
}

int fibonacci(int i, int a, int b, int quantidadenumeros){
    int novoSuc, soma = 0;
    if (i == quantidadenumeros)
    {
        return 1;
    }

    imprintmir(a);

    novoSuc = a + b;
    a = b;
    b = novoSuc;

    fibonacci(i+1,a,b, quantidadenumeros);
    
}



int main(){
   int i = 0, a = 1, b = 1, soma; 
   int quantidadenumeros;
   printf("informes quantos numeros queres");
   scanf("%d", &quantidadenumeros);

    soma = fibonacci(i, a, b, quantidadenumeros);

    printf("\nA soma e %d", soma);
    return 0;
}