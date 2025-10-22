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

// Função auxiliar para obter o valor numérico de um atributo
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função para comparar duas cartas com base em dois atributos
void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    printf("\n===== COMPARAÇÃO DE CARTAS =====\n");
    printf("Carta 1: %s (%s)\n", c1.nome, c1.estado);
    printf("Carta 2: %s (%s)\n\n", c2.nome, c2.estado);

    // Obter valores dos atributos
    float v1_c1 = obterValorAtributo(c1, atributo1);
    float v1_c2 = obterValorAtributo(c2, atributo1);
    float v2_c1 = obterValorAtributo(c1, atributo2);
    float v2_c2 = obterValorAtributo(c2, atributo2);

    // Regras de comparação (densidade: menor vence)
    float resultado1 = (atributo1 == 5) ?
                        ((v1_c1 < v1_c2) ? 1 : (v1_c1 > v1_c2 ? -1 : 0)) :
                        ((v1_c1 > v1_c2) ? 1 : (v1_c1 < v1_c2 ? -1 : 0));

    float resultado2 = (atributo2 == 5) ?
                        ((v2_c1 < v2_c2) ? 1 : (v2_c1 > v2_c2 ? -1 : 0)) :
                        ((v2_c1 > v2_c2) ? 1 : (v2_c1 < v2_c2 ? -1 : 0));

    // Mostrar detalhes
    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("  %s: %.2f\n  %s: %.2f\n\n", c1.nome, v1_c1, c2.nome, v1_c2);

    printf("Atributo 2: %s\n", nomeAtributo(atributo2));
    printf("  %s: %.2f\n  %s: %.2f\n\n", c1.nome, v2_c1, c2.nome, v2_c2);

    // Soma dos atributos
    float soma1 = v1_c1 + v2_c1;
    float soma2 = v1_c2 + v2_c2;

    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n  %s: %.2f\n", c1.nome, soma1, c2.nome, soma2);

    // Determinar vencedor pela soma
    if (soma1 > soma2)
        printf("\nResultado final: %s venceu!\n", c1.nome);
    else if (soma2 > soma1)
        printf("\nResultado final: %s venceu!\n", c2.nome);
    else
        printf("\nResultado final: Empate!\n");
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001 > nul");

    // Cadastro das cartas
    Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 700000.0, 15, 0, 0};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6000000, 1182.30, 500000.0, 12, 0, 0};

    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    int atributo1, atributo2;

    printf("===== SUPER TRUNFO - NÍVEL MESTRE =====\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("\nDigite a opção: ");
    scanf("%d", &atributo1);

    // Verificação básica
    if (atributo1 < 1 || atributo1 > 5) {
        printf("\nOpção inválida!\n");
        return 0;
    }

    // Menu dinâmico - remove o atributo já escolhido
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1)
            printf("%d - %s\n", i, nomeAtributo(i));
    }
    printf("\nDigite a opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("\nOpção inválida! Os atributos devem ser diferentes.\n");
        return 0;
    }

    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
3}