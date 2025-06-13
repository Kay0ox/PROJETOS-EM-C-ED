/*
** Função : Ordena um vetor usando o algoritmo recursivo Quicksort
** Autor : Kayo Victor, Turma 
** Data : 08/06/2025
** Observações: O pivô é o elemento central. O vetor é preenchido com valores aleatórios.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quicksort recursivo
void quicksort(int v[], int inicio, int fim) {
    int i = inicio;
    int j = fim;
    int m = v[(inicio + fim) / 2]; // pivô central

    while (i <= j) {
        while (v[i] < m) i++;
        while (v[j] > m) j--;
        if (i <= j) {
            trocar(&v[i], &v[j]);
            i++;
            j--;
        }
    }

    if (inicio < j)
        quicksort(v, inicio, j);
    if (i < fim)
        quicksort(v, i, fim);
}

// Imprime o vetor
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
        printf("Erro de alocação.\n");
        return 1;
    }

    srand(time(NULL));
    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    quicksort(vetor, 0, n - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, n);

    free(vetor);
    return 0;
}
