/*
** Função : Ordena um vetor usando Bubble Sort e conta comparações e trocas
** Autor : Kayo Victor, Turma 
** Data : 08/06/2025
** Observações: Vetor gerado com números aleatórios
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função Bubble Sort com contagem
void bubbleSort(int v[], int n, int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (v[j] > v[j + 1]) {
                // troca
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

// Imprime vetor
void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));
    if (!vetor) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    srand(time(NULL));
    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int comparacoes, trocas;
    bubbleSort(vetor, n, &comparacoes, &trocas);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, n);

    printf("\nTotal de comparações (if's): %d\n", comparacoes);
    printf("Total de trocas: %d\n", trocas);

    free(vetor);
    return 0;
}
