#include <stdio.h>

void inicializaLista(int *lista, int tam){
    int i;

    for (i = 0; i < tam; i++){
        lista[i] = -1;
    }
}

int verificarEspacoLista(int *lista, int tam){
    int espaco = 0, i;

    for (i = 0; i < tam; i++){
        if(lista[i] != -1){
            espaco++;
        }
    }
    
    return espaco;
}

int insercaoLista(int *lista, int tam, int num){
    int i;
    
    if(lista[tam-1] == -1){
        lista[tam-1] = num;
    }else{
        for (i = 0; i < tam; i++){
            if(lista[i] != -1){
                lista[i-1] = lista[i];
            }
            
            if((lista[i] != -1) && (i == (tam-1))){
                lista[tam-1] = num;
            }
        }
    }    
    return 1;
}

void mostrarLista(int *lista, int tam){

    printf("\n\n----------------MOSTRAR LISTA---------------\n\n");
    for(int i = 0; i < tam; i++){
        printf("[%d] = %d\n", i, lista[i]);
    }
    printf("\n--------------------------------------------\n");
    
}

void cadastrarLista(int *lista, int tam){
    int num, controle = 1, espaco;

    printf("\n\n----------------CADASTRO-------------------\n");
    
    while (controle == 1){
        espaco = verificarEspacoLista(lista, tam);

        if(espaco == tam){
            printf("\nO espaco está cheio!!");
            break;
        }

        printf("\nInsira o número: ");
        scanf("%d", &num);

        insercaoLista(lista, tam, num);

        printf("\nDeseja continuar? \n[1]Sim ou [2]Não: ");
        scanf("%d", &controle);        
    }
    
    printf("\n--------------------------------------------\n");
}

int removerItem(int *lista, int tam){
    int pos, i, espaco;

    printf("\n\n--------------REMOVER ITEM-----------------\n");

    espaco = verificarEspacoLista(lista, tam);

    if(espaco == 0){
        printf("\nLista vazia para remover itens.\n\n");
        return 500;
    }


    printf("Insira a posição do item na lista: ");
    scanf("%d", &pos);

    
    if(pos < 0 || pos >= tam){
        printf("\nPosição não existe!\n\n");
        return 500;
    }

    if(lista[pos] == -1){
        printf("\nPosição está vazia!\n\n");
        return 500;
    }


    lista[pos] = -1;

    for (i = (pos-1); i >= 0; i--){
        lista[i+1] = lista[i];
        if(lista[i] == lista[i+1]){
            lista[i] = -1;
        }
    }    

    printf("Posição excluida com sucesso!!\n");
    printf("\n--------------------------------------------\n");
    return 1;
}

int main(){
    int tam = 300, lista[tam], opcao = 1;

    inicializaLista(lista, tam);

    while (opcao == 1 || opcao == 2 || opcao == 3){ 
        printf("--------------------MENU--------------------\n\n");
        printf("1 - Cadastro\n");
        printf("2 - Mostrar lista\n");
        printf("3 - Remover Item\n");

        printf("\nEscolha uma das opções acima ou insira qualquer número para sair: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                cadastrarLista(lista, tam);
                break;
            
            case 2:
                mostrarLista(lista, tam);
                break;

            case 3:
                removerItem(lista, tam);
                break;
        }
    }

    printf("\nFinalizando programa...\n");
    return 0;
}