#include <stdio.h>

void inicializaLista(int *lista, int tam){
    int i;

    for (i = 0; i < tam; i++){
        lista[i] = -1;
    }
    
}

int insercaoLista(int *lista, int tam, int num){
    int cont = 1, aux;

    if(lista[tam-cont] == -1){
        lista[]
    }else{
        cont++;

        printf("\nentrou else, vai repetir inserção\n");
        insercaoLista(lista, tam-cont, num);

        printf("\nconcluiu inserção\n");
    }
    
}

int main(){
    int tam = 3, lista[tam], pos, num, controle = 0;

    inicializaLista(lista, tam);
    
    while (controle == 0){

        printf("\n----------------Cadastro de números----------------\n");
        printf("Insira o número: ");
        scanf("%d", &num);
        insercaoLista(lista, tam, num);
        printf("Digite 0 para continuar ou qualquer numero para sair... ");
        scanf("%d", &controle);
    }

    for(int i = 0; i < tam; i++){
        printf("[%d] = %d\n", i, lista[i]);
    }

}