// Gabriel

#include <stdio.h>
#include <stdlib.h>

void contarNumerosRepetidos(int *vet, int tam, int *quant) {
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (vet[i] == vet[j]) {
                (*quant)++;
                break; // Para evitar contar o mesmo número repetido várias vezes
            }
        }
    }
}

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int *vet = (int *)malloc(tam * sizeof(int));
    if (vet == NULL) {
        printf("Erro na alocação de memoria.\n");
        return 1;
    }

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }

    int quant = 0;
    contarNumerosRepetidos(vet, tam, &quant);

    printf("Quantidade de numeros repetidos: %d\n", quant);

    free(vet); // Liberar a memória alocada

    return 0;
}
