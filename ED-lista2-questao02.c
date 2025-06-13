/*
** Função : Cadastro, exibição e exclusão de registros de empregados com alocação dinâmica
** Autor : Kayo Victor, Turma [Sua Turma Aqui]
** Data : 08/06/2025
** Observações: Código corrigido com leitura, escrita e exclusão usando vetor dinâmico.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nome[100];
    char dataNascimento[11];
    char rg[15];
    char dataAdmissao[11];
    double salario;
} Empregado;

// Lê os dados de um empregado
void lerEmpregado(Empregado *e) {
    getchar(); // limpar buffer
    printf("Nome: ");
    fgets(e->nome, sizeof(e->nome), stdin);
    e->nome[strcspn(e->nome, "\n")] = '\0';

    printf("Data de nascimento (DD/MM/AAAA): ");
    fgets(e->dataNascimento, sizeof(e->dataNascimento), stdin);
    e->dataNascimento[strcspn(e->dataNascimento, "\n")] = '\0';

    printf("RG: ");
    fgets(e->rg, sizeof(e->rg), stdin);
    e->rg[strcspn(e->rg, "\n")] = '\0';

    printf("Data de admissão (DD/MM/AAAA): ");
    fgets(e->dataAdmissao, sizeof(e->dataAdmissao), stdin);
    e->dataAdmissao[strcspn(e->dataAdmissao, "\n")] = '\0';

    printf("Salário: ");
    scanf("%lf", &e->salario);
}

//dados de um empregado
void mostrarEmpregado(Empregado e, int indice) {
    printf("\n--- Empregado %d ---\n", indice + 1);
    printf("Nome: %s\n", e.nome);
    printf("Data de nascimento: %s\n", e.dataNascimento);
    printf("RG: %s\n", e.rg);
    printf("Data de admissão: %s\n", e.dataAdmissao);
    printf("Salário: %.2lf\n", e.salario);
}

// Remove um empregado de índice especificado
void excluirEmpregado(Empregado **vetor, int *tamanho, int indice) {
    if (indice < 0 || indice >= *tamanho) {
        printf("Índice inválido.\n");
        return;
    }

    for (int i = indice; i < *tamanho - 1; i++) {
        (*vetor)[i] = (*vetor)[i + 1];
    }

    (*tamanho)--;
    *vetor = realloc(*vetor, (*tamanho) * sizeof(Empregado));

    printf("Empregado excluído com sucesso.\n");
}



// Função principal
int main() {
    Empregado *empresa = NULL;
    int tamanho = 0;
    int opcao, indice;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Adicionar empregado\n");
        printf("2 - Mostrar todos os empregados\n");
        printf("3 - Excluir empregado por índice\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                tamanho++;
                empresa = realloc(empresa, tamanho * sizeof(Empregado));
                if (!empresa) {
                    printf("Erro de memória.\n");
                    return 1;
                }
                lerEmpregado(&empresa[tamanho - 1]);
                break;

            case 2:
                if (tamanho == 0) {
                    printf("Nenhum empregado cadastrado.\n");
                } else {
                    for (int i = 0; i < tamanho; i++) {
                        mostrarEmpregado(empresa[i], i);
                    }
                }
                break;

            case 3:
                if (tamanho == 0) {
                    printf("Nenhum empregado para excluir.\n");
                } else {
                    printf("Digite o índice (1 a %d): ", tamanho);
                    scanf("%d", &indice);
                    excluirEmpregado(&empresa, &tamanho, indice - 1);
                }
                break;

            case 0:
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    free(empresa);
    return 0;
}
