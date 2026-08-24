#include <stdio.h>

int main(void) {
    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int linhas = 3;
    int colunas = 4;

    printf("a) Elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", *(*(matriz + i) + j));
        }
        printf("\n");
    }

    printf("\nb) Soma de cada linha:\n");
    for (int i = 0; i < linhas; i++) {
        int soma_linha = 0;
        for (int j = 0; j < colunas; j++) {
            soma_linha += *(*(matriz + i) + j);
        }
        printf("Soma da linha %d: %d\n", i, soma_linha);
    }

    int maior = *(*(matriz + 0) + 0);
    int lin_maior = 0;
    int col_maior = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (*(*(matriz + i) + j) > maior) {
                maior = *(*(matriz + i) + j);
                lin_maior = i;
                col_maior = j;
            }
        }
    }

    printf("\nc) e d) Resultado do Maior Elemento:\n");
    printf("Maior valor: %d\n", maior);
    printf("Posição: Linha %d, Coluna %d\n", lin_maior, col_maior);

    return 0;
}
