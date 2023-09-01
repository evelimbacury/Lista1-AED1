//Evelim

#include <stdio.h>
#include <stdlib.h>

#define t 10

struct Produto{
    char nome[200];
    int quantidade;
    float preco;
};

void inicializaPilha(int *pilha, int tam){
    int i;
    for(i = 0; i < tam; i++){
        pilha[i] = -1;
    }
}

int pilhaVazia(int topo){
    if(topo == 0){
        return 1;
    }else{
        return 0;
    }
}

int inserePilha(int *pilha, int valor, int topo, int tam){
    if(topo > tam || topo < 0){
        printf("Erro encontrado na inserção!!!\n");
        return 500;
    }
    pilha[topo] = valor;
    topo++;
    return topo;
}

int removePilha(int *pilha, int topo, int tam){
    int aux;
    if(topo < 0){
        printf("Erro encontrado na remoção!!!\n");
        return 500;
    }
    aux = pilha[topo-1];
    pilha[topo-1] = -1;
    return aux;
}

void imprimePilha(int *pilha, int *pilha2, int tam, int topo, int topo2){
    int aux;
    while(!(pilhaVazia(topo))){
        aux = removePilha(pilha, topo, tam);
        topo = topo - 1;
        printf("%d\t", aux);
        topo2 = inserePilha(pilha2, aux, topo2, tam);
    }
    printf("\n");
    while (!(pilhaVazia(topo2)))
    {
        aux = removePilha(pilha2, topo2, tam);
        topo2 = topo2 - 1;
        printf("%d\t", aux);
        topo = inserePilha(pilha, aux, topo, tam);
    }
    printf("\n");
}

int main(){
    struct Produto produto;
    int topo = 0, topo2 = 0, aux, opcao = 1, i;
    int *pilha, *pilha2;

    pilha = pilha2 = (int *) malloc(sizeof(int) * t);

    while (opcao == 1 || opcao == 2 || opcao == 3){ 
        printf("--------------------MENU--------------------\n\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Mostrar pilha\n");
        printf("3 - Remover Item\n");

        printf("\nEscolha uma das opções acima ou insira qualquer número para sair: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                for (i = 0; i < t; i++)
                {
                    printf("\nCadastrar Produto %d\n", i);
                    printf("Nome: ");
                    scanf("%s", &produto.nome);

                    printf("Quantidade: ");
                    scanf("%d", &produto.quantidade);

                    printf("Preço: ");
                    scanf("%f", &produto.preco);
                    /* code */
                    //inserePilha(pilha, produto, t, topo);
                }
            
                break;
            
            case 2:
                imprimePilha(pilha, pilha2, t, topo, topo2);
                break;

            case 3:
                printf("\nRemover Produto\n");
                printf("Insira o nome do produto:");
                //removePilha();
                break;
        }
    }

}