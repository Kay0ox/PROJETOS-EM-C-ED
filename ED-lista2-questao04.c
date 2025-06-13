/*
** Função : Verifica a Conjectura de Goldbach para todos os números pares entre 700 e 1100.
** Autor : Kayo Victor, 
** Data : 08/06/2025
** Observações: Para cada número par, imprime uma combinação de dois primos cuja soma dá esse número.
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
            return; // uma solução já é suficiente
        }
    }
}

int main() {
    printf("Conjectura de Goldbach para números pares de 700 a 1100:\n");

    for (int n = 700; n <= 1100; n += 2) {
        verificarGoldbach(n);
    }

    return 0;
}
