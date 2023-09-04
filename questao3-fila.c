//Gabriel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    char nome[100];
    int quantidade;
    float preco;
};

void inicializafila(struct produto *fila, int tam){

    int i;

    for ( i = 0; i < tam; i++)
    {
        fila[i].quantidade = -1;
    }

}

void atualizarfila(struct produto *fila, int refresque){
    if (fila[refresque].quantidade == -1 && fila[refresque+1].quantidade != -1)
    {
        strcpy(fila[refresque].nome, fila[refresque+1].nome);
        fila[refresque].quantidade = fila[refresque+1].quantidade;
        fila[refresque].preco = fila[refresque+1].preco;
        fila[refresque+1].quantidade = -1;

        atualizarfila(fila,refresque+1);
    }
    
}




int inserefila(struct produto *fila, int tam, int *ult){
    if (ult<0 || ult >10)
    {
        printf("erro na incerção!!!\n");
    }
    else
    {
        printf("insira o nome produto: ");
        scanf("%s", &fila[*ult].nome);
        printf("informe a quantidade do produto: ");
        scanf("%d", &fila[*ult].quantidade);
        printf("informe o preço do produto: ");
        scanf("%f", &fila[*ult].preco);

        printf("produto cadastrado com sucesso!!!");
    }
}


void encontrarproduto(struct produto *fila, int tam){

    char nomeBusca[50];
    printf("Digite o nome do produto a ser buscado: ");
    scanf("%s", nomeBusca);
    
    for (int i = 0; i < tam; i++) {
        if (strcmp(nomeBusca, fila[i].nome) == 0) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", fila[i].nome);
            printf("Quantidade em estoque: %d\n", fila[i].quantidade);
            printf("Preço unitário: %.2f\n", fila[i].preco);
            }
        }

}
    
void removefila(struct produto *fila, int tam, int *prim){
    if (*prim == 0)
    {
        printf("nenhum produto cadastrado para removição");
    }
    else
    {
        fila[0].quantidade = -1;
        printf("produto removido :()");
        atualizarfila(fila, 0);
    }
    
    
    }


    void imprimirfila(struct produto *fila, int tam, int prim){
        int i;
        if (prim==0)
        {
            printf("nenhum produto encontrado");
        }
        else
        {
            for (i = 0; i < tam; i++)
            {
                if (fila[i].quantidade != -1)
                {
                printf("\nNumero: %i", i+1);
                printf("\nProduto: %s", fila[i].nome);
                printf("\nEstoque: %i", fila[i].quantidade);
                printf("\nValor: %.2f\n\n", fila[i].preco);
                }
                
            }
            
        }
        
    }


    int main()
    {
        int tam = 10, prim = 0; 
        int aux = 0;
        struct produto *fila = (struct produto *)malloc(sizeof(struct produto) * tam);
    inicializafila(fila,tam);

    while(aux!=5) {
    
        printf("\nEscolha uma opcao\n");
        printf("\nInserir produto: 1");
        printf("\nBuscar produto: 2");
        printf("\nRemover produto:3");
        printf("\nVisualizar produtos:4");
        printf("\nEncerrar programa:5\n");

        scanf("%i", &aux);

        switch(aux) {
            case 1:
                inserefila(fila,tam,&prim);
                break;
            case 2:
                encontrarproduto(fila,tam);
                break;
            case 3:
                removefila(fila,tam,&prim);
                break;
            case 4:
                imprimirfila(fila,tam,prim);
                break;
            default:
                printf("\nPor favor, selecione uma opcao possivel.\n");
                break;
        }
    }

    free(fila);
        return 0;
    }
    

