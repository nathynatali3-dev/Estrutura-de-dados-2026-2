#include <stdio.h>

typedef struct {
    char nome[100];
    char tipoMusica[100];
    int integrantes;
    int ranking;
} Banda;

void mostrarBanda(Banda banda)
{
    printf("\nNome: %s\n", banda.nome);
    printf("Tipo de musica: %s\n", banda.tipoMusica);
    printf("Numero de integrantes: %d\n", banda.integrantes);
    printf("Posicao no ranking: %d\n", banda.ranking);
}

void buscarRanking(Banda bandas[], int posicao)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        if (bandas[i].ranking == posicao)
        {
            mostrarBanda(bandas[i]);
            return;
        }
    }

}

int main()
{
    Banda bandas[5];
    int i;
    int posicao;

    for (i = 0; i < 5; i++)
    {
        printf("\nDigite os dados da banda %d\n", i + 1);

        printf("Nome: ");
        scanf(" %99[^\n]", bandas[i].nome);

        printf("Tipo de musica: ");
        scanf(" %99[^\n]", bandas[i].tipoMusica);

        printf("Numero de integrantes: ");
        scanf("%d", &bandas[i].integrantes);

        printf("Posicao no ranking (1 a 5): ");
        scanf("%d", &bandas[i].ranking);
    }

    for (i = 0; i < 5; i++)
    {
        mostrarBanda(bandas[i]);
    }

    printf("\nDigite uma posicao do ranking de 1 a 5: ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= 5)
    {
        buscarRanking(bandas, posicao);
    }

    return 0;
}
