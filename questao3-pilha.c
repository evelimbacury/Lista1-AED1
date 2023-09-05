//Evelim

#include <stdio.h>
#include <stdlib.h>

#define t 2

typedef struct Produto{
    char nome[200];
    int quantidade;
    float preco;
}Produto;

void inicializaPilha(Produto *pilha, int tam){
    int i;
    for(i = 0; i < tam; i++){
        strcpy(pilha[i].nome, "NULL");
        pilha[i].quantidade = -1;
        pilha[i].preco = -1;
    }
}

int pilhaVazia(int *topo){
    if(topo == 0){
        return 1;
    }else{
        return 0;
    }
}

int inserePilha(Produto *pilha, int *top, int tam){
    int topo = *top;

    if(topo > tam || topo < 0){
        printf("Erro encontrado na inserção!!!\n");
        return 500;
    }

    printf("Nome: ");
    scanf("%s", &pilha->nome);

    printf("Quantidade: ");
    scanf("%d", &pilha->quantidade);

    printf("Preço: ");
    scanf("%f", &pilha->preco);

    strcpy(pilha[topo].nome, pilha->nome);
    pilha[topo].quantidade = pilha->quantidade;
    pilha[topo].preco = pilha->preco;

    topo++;
    return topo;
}

Produto removePilha(Produto *pilha, int *top, int tam){
    int topo = *top;

    Produto aux;
    if(topo < 0){
        printf("Erro encontrado na remoção!!!\n");
    }
    aux = pilha[topo-1];
    
    strcpy(pilha[topo-1].nome, "NULL");
    pilha[topo-1].quantidade = -1;
    pilha[topo-1].preco = -1;

    return aux;
}

void imprimePilha(Produto *pilha, Produto *pilha2, int tam, int *top, int *top2){
    Produto aux;
    int topo = *top;
        printf("\nTOPO = %d\n", topo);
    int topo2 = *top2;

    while(!(pilhaVazia(topo))){
        aux = removePilha(pilha, topo, tam);
        topo = topo - 1;
        printf("%s\t%d\t%f\n", aux.nome, aux.quantidade, aux.preco);
        topo2 = inserePilha(pilha2, topo2, tam);
    }

    printf("\n");

    while (!(pilhaVazia(topo2)))
    {
        aux = removePilha(pilha2, topo2, tam);
        topo2 = topo2 - 1;
        printf("%s\t%d\t%f\n", aux.nome, aux.quantidade, aux.preco);
        topo = inserePilha(pilha, topo, tam);
    }
    printf("\n");
}

int main(){
    Produto *pilha, *pilha2;

    int topo = 0, topo2 = 0, opcao = 1, i;


    pilha = pilha2 = malloc(sizeof(Produto) * t);

    while (opcao == 1 || opcao == 2 || opcao == 3){ 
        printf("--------------------MENU--------------------\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Mostrar pilha\n");
        printf("3 - Remover Item\n");
        
        printf("\nEscolha uma das opções acima ou insira qualquer número para sair: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("\nCadastrar Produto\n");

                for (i = 0; i < t; i++)
                {
                    printf("\n");
                    inserePilha(pilha, &topo, t);
                }
            
                break;
            
            case 2:
                imprimePilha(pilha, pilha2, t, &topo, &topo2);
                break;

            case 3:
                printf("\nRemover Produto\n");
                printf("Insira o nome do produto:");
                removePilha(pilha, &topo, t);
                break;
        }
    }

    free(pilha);
    free(pilha2);

    return 0;
}