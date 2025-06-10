/*
** Função : Cadastro, exibição e exclusão de aeroportos com vetor de ponteiros para struct
** Autor : Kayo Victor, Turma 
** Data : 08/06/2025
** Observações: Exemplo com alocação dinâmica usando ponteiros para struct Aeroporto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char sigla[4];
    char cidade[51];
    char pais[31];
    float taxa;
    int capacidade;
}aeroporto;



// Lê dados de um novo aeroporto

aeroporto* criarAeroporto(){
    aeroporto *a = (aeroporto *)malloc(sizeof(aeroporto));
    if (a == NULL){
        printf("erro ao alocar memoria para o aeroporto.\n");
        exit(1);
    }
    getchar();
    printf("sigla (3 letras): ");
   fgets(a->sigla, sizeof(a->sigla), stdin);
    a->sigla[strcspn(a->sigla, "\n")] = '\0';

    printf("cidade: \n");
    fgets(a->cidade, sizeof(a->cidade), stdin);
    a->cidade[strcspn(a->cidade, "\n")] = '\0';

    printf("pais: ");
    fgets(a->pais, sizeof(a->pais), stdin);
    a->pais[strcspn(a->pais, "\n")] = '\0';
    
    printf("taxa: ");
    scanf("%f", &a->taxa);

    printf("capacidade: ");
    scanf("%d", &a->capacidade);

    return a;

}
//exibe os dados do aeroporto
void mostrarAeroporto(aeroporto *a, int i){
   printf("\n--- Aeroporto %d ---\n", i + 1);
    printf("Sigla: %s\n", a->sigla);
    printf("Cidade: %s\n", a->cidade);
    printf("País: %s\n", a->pais);
    printf("Taxa: %.2f\n", a->taxa);
    printf("Capacidade: %d\n", a->capacidade);
}

// remove aeroporto do vetor
void excluirAeroporto(aeroporto ***vetor, int *tamanho, int indice){
if (indice < 0 || indice >= *tamanho){
    printf("indice invalido.\n");
    return;
}

free((*vetor)[indice]);

for (int i = indice; i < *tamanho -1; i++){
    (*vetor)[i] = (*vetor)[i + 1];
}
(*tamanho)--;
*vetor = realloc(*vetor, (*tamanho) * sizeof(aeroporto *));
printf("aeroporto excluido com sucesso!\n");

}

//main

int main(){
    aeroporto **aeroportos = NULL;
    int tamanho = 0;
    int opcao, indice;

    do{
        printf("\n====== MENU ======\n");
        printf("1 - Adicionar aeroporto\n");
        printf("2 - Mostrar aeroportos\n");
        printf("3 - Excluir aeroporto\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);


        switch (opcao){
            case 1:
            aeroportos = realloc(aeroportos, (tamanho + 1) * sizeof(aeroporto *));
            if (!aeroportos) {
                printf("Erro ao realocar memoria\n");
                return 1;
            }
            aeroportos[tamanho] = criarAeroporto();
            tamanho ++;
            break;


            case 2:
            if (tamanho == 0){
                printf("Nenhuma aeroporto cadastrado.\n");
            } else {
                for (int i = 0; i < tamanho; i++){
                    mostrarAeroporto(aeroportos[i], i);
                }
            }
            break;

            case 3:
            if (tamanho == 0){
                printf("nenhum aeroporto para excluir\n");
            } else {
                printf("infome o indice (1 a %d): ", tamanho);
                scanf("%d", &indice);
                excluirAeroporto(&aeroportos, &tamanho, indice - 1);
            }
            break;

            case 0:
                break;

            default:
                printf("opacao invalida\n");
        }
    } while (opcao != 0);
    for (int i = 0; i < tamanho; i++){
        free(aeroportos[i]);
    }
    free(aeroportos);

    return 007;
}