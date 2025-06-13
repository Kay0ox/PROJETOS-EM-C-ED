/*
** Função : Calcula a raiz quadrada de um número n usando o método de Newton-Raphson
** Autor : Kayo Victor, Turma 
** Data : 08/06/2025
** Observações: A aproximação para erro é de 0.0001
*/

#include <stdio.h>
#include <math.h>

// Função para calcular raiz quadrada com Newton-Raphson
double raizQuadrada(double n) {
    double x = n / 2.0; // chute inicial
    double erro = 0.0001;

    while (fabs(x * x - n) > erro) {
        x = (x + n / x) / 2.0;
    }

    return x;
}

int main() {
    double n;

    printf("Digite um número positivo para calcular a raiz quadrada: ");
    scanf("%lf", &n);

    if (n < 0) {
        printf("Número inválido. A raiz quadrada de número negativo não é real.\n");
        return 1;
    }

    double resultado = raizQuadrada(n);
    printf("Raiz aproximada de %.4lf = %.5lf\n", n, resultado);

    return 0;
}
