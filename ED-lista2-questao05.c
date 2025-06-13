/*
** Função : Verifica a Conjectura de Goldbach de 4 até um número N informado pelo usuário.
** Autor : Kayo Victor, Turma 
** Data : 08/06/2025
** Observações:
*/

#include <stdio.h>
#include <stdbool.h>

// Verifica se um número é primo
bool ehPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Aplica a conjectura para um número par específico
void verificarGoldbach(int numero) {
    for (int i = 2; i <= numero / 2; i++) {
        int j = numero - i;
        if (ehPrimo(i) && ehPrimo(j)) {
            printf("%d = %d + %d\n", numero, i, j);
            return; // Mostra apenas uma combinação
        }
    }
}

int main() {
    int N;

    printf("Digite um número inteiro N maior que 4: ");
    scanf("%d", &N);

    if (N <= 4) {
        printf("N deve ser maior que 4.\n");
        return 1;
    }

    printf("\nConjectura de Goldbach de 4 até %d:\n", N);
    for (int n = 4; n <= N; n += 2) {
        verificarGoldbach(n);
    }

    return 0;
}
