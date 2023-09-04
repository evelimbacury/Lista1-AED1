//Gabriel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estrutura para representar um produto
struct Produto {
    char nome[50];
    int quantidade;
    float preco;
};

// Função para inserir um novo produto na lista
void inserir(struct Produto lista[], int *tamanho) {
    if (*tamanho < 10) {
        struct Produto novoProduto;
        printf("Digite o nome do produto: ");
        scanf("%s", novoProduto.nome);
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &novoProduto.quantidade);
        printf("Digite o preço unitário do produto: ");
        scanf("%f", &novoProduto.preco);
        
        lista[*tamanho] = novoProduto;
        *tamanho++;
        printf("Produto inserido com sucesso!\n");
    } else {
        printf("A lista está cheia. Não é possível adicionar mais produtos.\n");
    }
}

// Função para buscar um produto pelo nome
void buscar(struct Produto lista[], int tamanho) {
    char nomeBusca[50];
    printf("Digite o nome do produto a ser buscado: ");
    scanf("%s", nomeBusca);
    
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(nomeBusca, lista[i].nome) == 0) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", lista[i].nome);
            printf("Quantidade em estoque: %d\n", lista[i].quantidade);
            printf("Preço unitário: %.2f\n", lista[i].preco);
            return; // Produto encontrado, encerra a busca
        }
    }
    
    printf("Produto não encontrado.\n");
}

// Função para remover um produto pelo nome
void remover(struct Produto lista[], int *tamanho) {
    char nomeRemover[50];
    printf("Digite o nome do produto a ser removido: ");
    scanf("%s", nomeRemover);
    
    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(nomeRemover, lista[i].nome) == 0) {
            // Move os elementos subsequentes uma posição para trás
            for (int j = i; j < *tamanho - 1; j++) {
                lista[j] = lista[j + 1];
            }
            *tamanho--;
            printf("Produto removido com sucesso!\n");
            return; // Produto removido, encerra a remoção
        }
    }
    
    printf("Produto não encontrado. Nenhuma remoção realizada.\n");
}

// Função para visualizar todos os produtos da lista
void visualizar(struct Produto lista[], int tamanho) {
    printf("Lista de produtos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Quantidade em estoque: %d\n", lista[i].quantidade);
        printf("Preço unitário: %.2f\n", lista[i].preco);
        printf("-----------------\n");
    }
}

int main() {
    struct Produto *listaProdutos = (struct Produto *)malloc(10 * sizeof(struct Produto));
    int tamanho = 0;
    int opcao;

    if (listaProdutos == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir um novo produto\n");
        printf("2. Buscar um produto\n");
        printf("3. Remover um produto\n");
        printf("4. Visualizar todos os produtos\n");
        printf("5. Sair\n");
        printf("escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
           inserir(listaProdutos, &tamanho);
                break; 
        }
        
        if (opcao == 2)
        {
           buscar(listaProdutos, tamanho);
                break; 
        }
        
        if (opcao == 3)
        {
           remover(listaProdutos, &tamanho);
                break;
        }
        
        if (opcao == 4)
        {
           visualizar(listaProdutos, tamanho);
                break;
        }
        
        if (opcao == 5)
        {
           free(listaProdutos); // Libera a memória alocada
                return 0;
        }
        
        
        
    }

    return 0;
}