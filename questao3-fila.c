/*3) Crie uma lista, uma fila e uma pilha. As estruturas de dados solicitadas devem ter tamanho 10,
ser estáticas e devem armazenar os seguintes campos: Nome do produto, Quantidade no estoque e
Preço unitário do produto. Adicionalmente, para cada estrutura implemente as seguintes funções:
• Inserção
• Busca
• Remoção
• Visualização
Obs.: Os vetores devem ser alocados dinamicamente.*/

#include <stdio.h>

struct produto
{
    char nome[100];
    int quantidade;
    float preco;
};


void inicializafila(int *fila, int tam){
    int i;

    for (i = 0; i < tam; i++){
        fila[i] = -1;
    }
    
}

int filavazia(int prim, int ult){
    if (prim == 0 && ult == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int enfileirar(int *fila, int valor, int ult, int tam){
    if (ult < 0)
    {
        printf("erro entrado na incercao");
        return 500;
    }
    fila[ult]=valor;
    ult++;
    return ult;
}

void ajustafila(int*fila, int tam){
    int i, j, c=0, h=0;
    for ( i = 0; i < tam; i++)
    {
        if (fila[i] = -1)
        {
            h = -1;
        }
        else if (fila[i] != -1 && h == 1)
        {
            j = i;
            while (fila[j-1] == -1)
            {
                fila[j-1] = fila[j];
                fila[j] = -1;
            }
            
        }
        
        }
        
    }

int desenfileirar(int *fila, int prim, int tam){
    int aux;

    if (prim == 0)
    {
        printf("erro encontrado na remocao");
        return 500;
    }

    aux=fila[prim];
    fila[prim]=-1;
    ajustafila(fila, tam);
    return aux;
}



int main(){
    int t= 10, ult = 0, prim = 0 , ult2 = 0, prim2 = 0, aux, i;

    int *fila;
    fila = (int *)malloc(sizeof(int)* t);

    int *fila2;
    fila2 = (int *)malloc(sizeof(int)* t);

    inicializafila(fila,t);
    inicializafila(fila2,t);

    ult = enfileirar(fila, 2, ult, t);
    ult = enfileirar(fila, 4, ult, t);
    ult = enfileirar(fila, 8, ult, t);
    ult = enfileirar(fila, 10, ult, t);
    ult = enfileirar(fila, t, ult, t);

    for (i = 0; i < t; i++)
    {
        printf("%d\n", fila[i]);
    }
    
    printf("\n");

    aux = desenfileirar(fila, prim, t);

    ult = ult-1;
    return 0;
}

    
