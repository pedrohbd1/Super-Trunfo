#include <stdio.h>
#include <string.h>

int main() {
    // Carta 1
    char estado1;
    char codigo1[4];
    char nome1[50];
    unsigned long int populacao1;
    float area1;
    float pib1; // em bilhões de reais
    int pontos1;
    float densidade1;
    float pibPerCapita1; // em reais
    float superPoder1;

    // Carta 2
    char estado2;
    char codigo2[4];
    char nome2[50];
    unsigned long int populacao2;
    float area2;
    float pib2; // em bilhões de reais
    int pontos2;
    float densidade2;
    float pibPerCapita2; // em reais
    float superPoder2;

    // Entrada - Carta 1
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta: ");
    scanf(" %3s", codigo1);
    while (getchar() != '\n');

    printf("Nome da Cidade: ");
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = '\0';

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    // Entrada - Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta: ");
    scanf(" %3s", codigo2);
    while (getchar() != '\n');

    printf("Nome da Cidade: ");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // Cálculos
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1e9f) / (float)populacao1;
    superPoder1 = populacao1 + area1 + (pib1 * 1e9f) + pontos1 + pibPerCapita1 + (1.0f / densidade1);

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1e9f) / (float)populacao2;
    superPoder2 = populacao2 + area2 + (pib2 * 1e9f) + pontos2 + pibPerCapita2 + (1.0f / densidade2);

    // Comparações
    printf("\n=== Comparacao de Cartas ===\n");
    printf("Populacao: Carta %d venceu (%d)\n", populacao1 > populacao2 ? 1 : 2, populacao1 > populacao2 ? 1 : 0);
    printf("Area: Carta %d venceu (%d)\n", area1 > area2 ? 1 : 2, area1 > area2 ? 1 : 0);
    printf("PIB: Carta %d venceu (%d)\n", pib1 > pib2 ? 1 : 2, pib1 > pib2 ? 1 : 0);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", pontos1 > pontos2 ? 1 : 2, pontos1 > pontos2 ? 1 : 0);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", densidade1 < densidade2 ? 1 : 2, densidade1 < densidade2 ? 1 : 0);
    printf("PIB per Capita: Carta %d venceu (%d)\n", pibPerCapita1 > pibPerCapita2 ? 1 : 2, pibPerCapita1 > pibPerCapita2 ? 1 : 0);
    printf("Super Poder: Carta %d venceu (%d)\n", superPoder1 > superPoder2 ? 1 : 2, superPoder1 > superPoder2 ? 1 : 0);

    return 0;
}