#include <stdio.h>
#include <locale.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularAtributos(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para comparar duas cartas com base em um atributo escolhido
void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\n===== COMPARACAO DE CARTAS =====\n");
    printf("Carta 1: %s (%s)\n", c1.nome, c1.estado);
    printf("Carta 2: %s (%s)\n\n", c2.nome, c2.estado);

    switch (opcao) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("%s: %d habitantes\n", c1.nome, c1.populacao);
            printf("%s: %d habitantes\n", c2.nome, c2.populacao);

            if (c1.populacao > c2.populacao)
                printf("\nResultado: %s venceu!\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("\nResultado: %s venceu!\n", c2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 2: // Área
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", c1.nome, c1.area);
            printf("%s: %.2f km²\n", c2.nome, c2.area);

            if (c1.area > c2.area)
                printf("\nResultado: %s venceu!\n", c1.nome);
            else if (c2.area > c1.area)
                printf("\nResultado: %s venceu!\n", c2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhoes\n", c1.nome, c1.pib);
            printf("%s: %.2f bilhoes\n", c2.nome, c2.pib);

            if (c1.pib > c2.pib)
                printf("\nResultado: %s venceu!\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("\nResultado: %s venceu!\n", c2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d pontos\n", c1.nome, c1.pontos_turisticos);
            printf("%s: %d pontos\n", c2.nome, c2.pontos_turisticos);

            if (c1.pontos_turisticos > c2.pontos_turisticos)
                printf("\nResultado: %s venceu!\n", c1.nome);
            else if (c2.pontos_turisticos > c1.pontos_turisticos)
                printf("\nResultado: %s venceu!\n", c2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        case 5: // Densidade demográfica (menor vence)
            printf("Atributo: Densidade Demografica\n");
            printf("%s: %.2f hab/km²\n", c1.nome, c1.densidade);
            printf("%s: %.2f hab/km²\n", c2.nome, c2.densidade);

            if (c1.densidade < c2.densidade)
                printf("\nResultado: %s venceu (menor densidade)!\n", c1.nome);
            else if (c2.densidade < c1.densidade)
                printf("\nResultado: %s venceu (menor densidade)!\n", c2.nome);
            else
                printf("\nResultado: Empate!\n");
            break;

        default:
            printf("\nOpcao invalida! Escolha um número de 1 a 5.\n");
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Cadastro de duas cartas
    Carta carta1 = {"Sao Paulo", "SP01", "Sao Paulo", 12300000, 1521.11, 700000.0, 15, 0, 0};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6000000, 1182.30, 500000.0, 12, 0, 0};

    // Calcula densidade e PIB per capita
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    int opcao;
    printf("===== SUPER TRUNFO - NIVEL AVENTUREIRO =====\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica (menor vence)\n");
    printf("\nDigite o numero da opcao: ");
    scanf("%d", &opcao);

    compararCartas(carta1, carta2, opcao);

    return 0;
}