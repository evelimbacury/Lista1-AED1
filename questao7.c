// Evelim

/*
Faça um programa em C que leia três valores inteiros (nas variáveis A, B e C) e chame uma
função que receba estes 3 valores de entrada e ordene os valores, ou seja, o menor valor na primeira
variavel (A), o segundo menor valor na variavel do meio (B) e o maior valor na última variável (C).
Utilize passagem por referência para alterar os valores das variáveis (A, B e C).
*/

#include <stdio.h>


void ordenar(int a, int b, int c){
    int *pontA, *pontB, *pontC, *pontAux;
    int aux;

    pontA = &a;
    pontB = &b;
    pontC = &c;
    pontAux = &aux;

    // Caso A for o maior
    if(b < a && c < a){   
        if(b < c){
            // b < c < a
            aux = *pontC;

            *pontC = *pontB;
            *pontB = *pontAux;
        }

        aux = *pontA;

        *pontA = *pontC;
        *pontC = *pontAux;
    }

    // Caso B for o maior
    if(a < b && c < b){   
        if(c < a){
            // b < c < a
            aux = *pontA;

            *pontA = *pontC;
            *pontC = *pontAux;
        }

        aux = *pontB;

        *pontB = *pontC;
        *pontC = *pontAux;
    }    
    
    // Caso C for o maior
    if(a < c && b < c){   
        if(b < a){
            // b < c < a
            aux = *pontA;

            *pontA = *pontB;
            *pontB = *pontAux;
        }
    }   


    printf("\nA: %d\nB: %d\nC: %d\n", a, b, c);
}

int main(){
    int a, b, c;

    printf("Insira 3 valores inteiros para\n");
    printf("A: ");
    scanf("%d", &a);

    printf("B: ");
    scanf("%d", &b);

    printf("C: ");
    scanf("%d", &c);

    ordenar(a, b, c);

}