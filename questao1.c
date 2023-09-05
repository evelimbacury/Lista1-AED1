#include <stdio.h>

void imprimir(int num) {
    printf("%d ", num);
}

int fibonacci(int i, int a, int b, int quantidadeNumeros) {
    int novoSuc;
    if (i == quantidadeNumeros) {
        return 0;
    }

    imprimir(a);

    novoSuc = a + b;
    a = b;
    b = novoSuc;

    return 1 + fibonacci(i + 1, a, b, quantidadeNumeros);
}

int somaFibonacci(int quantidadeNumeros) {
    int soma = 0;
    int i, a = 1, b = 1;
    for (i = 0; i < quantidadeNumeros; i++) {
        soma += a;
        int novoSuc = a + b;
        a = b;
        b = novoSuc;
    }
    return soma;
}

int main() {
    int i = 0, a = 1, b = 1, soma;
    int quantidadeNumeros;

    printf("Informe quantos numeros voce quer na sequencia de Fibonacci: ");
    scanf("%d", &quantidadeNumeros);

    printf("Sequencia de Fibonacci com %d termos:\n", quantidadeNumeros);
    soma = fibonacci(i, a, b, quantidadeNumeros);
    printf("\n");

    printf("A soma dos primeiros %d numeros e: %d\n", quantidadeNumeros, somaFibonacci(quantidadeNumeros));
    
    return 0;
}