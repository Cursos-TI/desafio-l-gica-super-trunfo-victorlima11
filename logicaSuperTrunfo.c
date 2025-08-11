#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Armazena nome, cor do exército e quantidade de tropas
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Array para armazenar 5 territórios
    struct Territorio territorios[5];

    // Entrada de dados para cada território
    for (int i = 0; i < 5; i++) {
        printf("=== Cadastro do Territorio %d ===\n", i + 1);

        // Nome do território
        printf("Digite o nome do territorio: ");
        scanf(" %s", territorios[i].nome); // Lê o input

        // Cor do exército
        printf("Digite a cor do exercito: ");
        scanf(" %s", territorios[i].cor); // Lê o input

        // Quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Exibição dos dados cadastrados
    printf("\n=== Territorios Cadastrados ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
        printf("--------------------------\n");
    }

    return 0;
}
