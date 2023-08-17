#include <stdio.h>

void inicializaLista(int *lista, int tam){
    int i;

    for (i = 0; i < tam; i++){
        lista[i] = -1;
    }
    
}
int verificarLista(int *lista, int tam){
    int i, cont = 0;

    for(i = 0; i < tam; i++){
        if(lista[i] == -1){
            cont++;
        }
    }

    if(cont == 0){
        printf("\nA lista está cheia!\n");
        return 0;
    }

}

int insercaoLista(int *lista, int tam, int pos){
    int num;
    if(pos > tam || pos < 0){
        printf("Erro encontrado na inserção!!\n");
        return 500;
    }

    if(lista[pos] == -1){
        printf("Insira o número: ");
        scanf("%d", &num);

        lista[pos] = num;
        return 0;
    }else{
        if(pos+1 > tam-1){
            pos = -1;
        }
            insercaoLista(lista, tam, pos+1);
    }
    
}

int main(){
    int tam = 500, lista[tam], pos, controle = 0;

    inicializaLista(lista, tam);
    
    while (controle == 0){

        printf("\n----------------Cadastro de números----------------\n");
        if(verificarLista(lista, tam) == 0){
            break;
        }
        printf("Insira a posição desejada(de 0 a 4): ");
        scanf("%d", &pos);
        insercaoLista(lista, tam, pos);
        printf("Digite 0 para continuar ou qualquer numero para sair... ");
        scanf("%d", &controle);
    }

    // for(int i = 0; i < tam; i++){
    //     printf("%d\n", lista[i]);
    // }
}