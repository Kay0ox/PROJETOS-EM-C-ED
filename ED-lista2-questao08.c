/*
** Função : Implementa um TAD para realizar operações com números complexos
** Autor : Kayo Victor, Turma 
** Data : 08/06/2025
** Observações: Operações básicas: soma, subtração, multiplicação, divisão e exibição
*/

#include <stdio.h>

// Definição do TAD Complexo
typedef struct {
    double real;
    double imag;
} Complexo;

// Cria um número complexo
Complexo criarComplexo(double r, double i) {
    Complexo c;
    c.real = r;
    c.imag = i;
    return c;
}

// Soma dois complexos
Complexo somar(Complexo a, Complexo b) {
    return criarComplexo(a.real + b.real, a.imag + b.imag);
}

// Subtrai dois complexos
Complexo subtrair(Complexo a, Complexo b) {
    return criarComplexo(a.real - b.real, a.imag - b.imag);
}

// Multiplica dois complexos
Complexo multiplicar(Complexo a, Complexo b) {
    double real = a.real * b.real - a.imag * b.imag;
    double imag = a.real * b.imag + a.imag * b.real;
    return criarComplexo(real, imag);
}

// Divide dois complexos
Complexo dividir(Complexo a, Complexo b) {
    double divisor = b.real * b.real + b.imag * b.imag;
    double real = (a.real * b.real + a.imag * b.imag) / divisor;
    double imag = (a.imag * b.real - a.real * b.imag) / divisor;
    return criarComplexo(real, imag);
}

// Exibe um número complexo na forma (a, b)
void mostrarComplexo(Complexo c) {
    printf("(%.2lf, %.2lf)\n", c.real, c.imag);
}

// Lê um número complexo
Complexo lerComplexo() {
    Complexo c;
    printf("Parte real: ");
    scanf("%lf", &c.real);
    printf("Parte imaginária: ");
    scanf("%lf", &c.imag);
    return c;
}

int main() {
    Complexo c1, c2, resultado;
    int opcao;

    printf("Digite o primeiro número complexo:\n");
    c1 = lerComplexo();

    printf("\nDigite o segundo número complexo:\n");
    c2 = lerComplexo();

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                resultado = somar(c1, c2);
                printf("Resultado da soma: ");
                mostrarComplexo(resultado);
