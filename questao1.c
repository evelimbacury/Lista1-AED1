#include <stdio.h>

void inicializaLista(int *lista, int tam){
    int i;

    for (i = 0; i < tam; i++){
        lista[i] = -1;
    }
    
}

void insercaoLista(int *lista, int tam){
    int pos, num;

    printf("Insira a posição desejada(de 0 a 999): ");
    scanf("%d", &pos);

    if(lista[pos] == -1){
        printf("Insira o número: ");
        scanf("%d", &num);

        lista[pos] = num;
    }else{
        printf("A posição já está sendo usada.\n\n");
        insercaoLista(lista, tam);
    }
}

int main(){
    int tam = 1000, lista[tam], controle = 0;

    inicializaLista(lista, tam);
    
    while (controle == 0){

        printf("\n----------------Cadastro de números----------------\n");
        insercaoLista(lista, tam);
        printf("Digite 0 para continuar ou qualquer numero para sair... ");
        scanf("%d", &controle);
    }
}