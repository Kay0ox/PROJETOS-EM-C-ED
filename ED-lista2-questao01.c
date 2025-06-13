/*
** Função : Ordena um vetor de inteiros em ordem crescente usando o algoritmo Selection Sort
** Autor : kayo victor
** Data : 08/06/2025
** Observações: O algoritmo segue o passo a passo de "classificação por seleção".
*/

#include <stdio.h>

// Função de ordenação por seleção (selection sort)
void selectionSort(int vetor[], int tamanho) {
    int i, j, indiceMenor, temp;

    for (i = 0; i < tamanho - 1; i++) {
        indiceMenor = i;

        // Busca o menor elemento do subvetor [i ... fim]
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }

        // Troca o menor elemento com o primeiro do subvetor
        if (indiceMenor != i) {
            temp = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = temp;
        }
    }
}
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
int main() {
    int vetor[] = {29, 10, 14, 37, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    selectionSort(vetor, tamanho);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
