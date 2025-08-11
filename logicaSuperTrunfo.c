#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura que representa um territorio no jogo
// Contém nome, cor do exercito e quantidade de tropas
struct Territorio {
    char nome[30]; // Nome do territorio
    char cor[10];  // Cor do exercito que ocupa o territorio
    int tropas;    // Numero de tropas presentes no territorio
};

// Função para cadastrar territorios
// Recebe um ponteiro para o vetor de territorios e a quantidade total
// Para cada territorio, solicita ao usuario o nome, a cor e o numero de tropas
void cadastrarTerritorios(struct Territorio *mapa, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("=== Cadastro do Territorio %d ===\n", i + 1);

        printf("Digite o nome do territorio: ");
        scanf(" %s", (mapa + i)->nome); // Lê o nome

        printf("Digite a cor do exercito: ");
        scanf(" %s", (mapa + i)->cor); // Lê a cor

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &(mapa + i)->tropas); // Lê o numero de tropas

        printf("\n");
    }
}

// Função para exibir todos os territorios cadastrados
// Mostra o indice, nome, cor e tropas de cada territorio
void exibirTerritorios(struct Territorio *mapa, int qtd) {
    printf("\n=== Territorios ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("[%d] Nome: %s | Cor: %s | Tropas: %d\n",
               i, (mapa + i)->nome, (mapa + i)->cor, (mapa + i)->tropas);
    }
    printf("--------------------------\n");
}

// Função que simula um ataque entre dois territorios
// Recebe ponteiros para o territorio atacante e defensor
// Utiliza valores aleatorios (1 a 6) como se fossem dados
// Se o atacante vencer, o defensor muda de cor e recebe metade das tropas do atacante
// Se perder, o atacante perde 1 tropa
void atacar(struct Territorio *atacante, struct Territorio *defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Voce nao pode atacar um territorio da mesma cor!\n");
        return;
    }

    if (atacante->tropas <= 1) {
        printf("O atacante precisa ter mais de 1 tropa para atacar!\n");
        return;
    }

    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\nAtaque de %s (%s) contra %s (%s)\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);
    printf("Dado atacante: %d | Dado defensor: %d\n",
           dadoAtacante, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Vitoria do atacante!\n");
        
        int tropasTransferidas = atacante->tropas / 2;  // metade das tropas do atacante
        
        strcpy(defensor->cor, atacante->cor);            // muda a cor do defensor para do atacante
        defensor->tropas += tropasTransferidas;          // adiciona tropas ao defensor
        atacante->tropas -= tropasTransferidas;          // subtrai tropas do atacante
    } else {
        printf("Defensor resistiu! Atacante perde 1 tropa.\n");
        atacante->tropas -= 1;
    }
}

// Função para liberar a memoria alocada dinamicamente
void liberarMemoria(struct Territorio *mapa) {
    free(mapa);
}

// Função principal do programa
int main() {
    srand(time(NULL)); // Inicializa gerador de numeros aleatorios

    int qtd;
    printf("Digite o numero de territorios: ");
    scanf("%d", &qtd); // Lê quantidade de territorios

    // Aloca dinamicamente memoria para armazenar territorios
    struct Territorio *mapa = (struct Territorio *)calloc(qtd, sizeof(struct Territorio));
    if (mapa == NULL) { // Verifica falha na alocação
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Cadastro inicial dos territorios
    cadastrarTerritorios(mapa, qtd);

    int opcao;
    // Loop principal para ataques
    do {
        // Exibe territorios
        exibirTerritorios(mapa, qtd);

        // Escolha de atacante e defensor
        int atacante, defensor;
        printf("\nEscolha o indice do territorio atacante: ");
        scanf("%d", &atacante);

        printf("Escolha o indice do territorio defensor: ");
        scanf("%d", &defensor);

        // Executa ataque
        atacar(&mapa[atacante], &mapa[defensor]);

        // Pergunta se deseja continuar
        printf("\nDeseja realizar outro ataque? (1 - Sim / 0 - Nao): ");
        scanf("%d", &opcao);

    } while (opcao == 1); // Continua enquanto usuario digitar 1

    // Exibe territorios finais
    exibirTerritorios(mapa, qtd);

    // Libera memoria antes de encerrar
    liberarMemoria(mapa);

    return 0;
}
