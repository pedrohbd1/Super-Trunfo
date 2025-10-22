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

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta c1, Carta c2) {
    // Atributo escolhido para comparação
    // População: maior valor vence
    printf("\nComparacao de cartas (Atributo: Populacao):\n\n");

    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, (float)c1.populacao);
    printf("Carta 2 - %s (%s): %.2f\n\n", c2.nome, c2.estado, (float)c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if (c2.populacao > c1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {

    // Cadastro de duas cartas
    Carta carta1 = {"Sao Paulo", "SP01", "Sao Paulo", 12300000, 1521.11, 700000.0, 15, 0, 0};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6000000, 1182.30, 500000.0, 12, 0, 0};

    // Calcula densidade e PIB per capita
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Exibe densidade e PIB per capita
    printf("Carta 1 - %s: Densidade = %.2f, PIB per capita = %.2f\n", carta1.nome, carta1.densidade, carta1.pib_per_capita);
    printf("Carta 2 - %s: Densidade = %.2f, PIB per capita = %.2f\n", carta2.nome, carta2.densidade, carta2.pib_per_capita);

    // Compara as cartas
    compararCartas(carta1, carta2);

    return 0;
}