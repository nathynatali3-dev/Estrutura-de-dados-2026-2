#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

bool estaVazia(Fila *f) {
    return f->tamanho == 0;
}

bool estaCheia(Fila *f) {
    return f->tamanho == MAX;
}

bool enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia! Nao e possivel inserir.\n");
        return false;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;   // movimento circular
    f->tamanho++;
    return true;
}

bool desenfileirar(Fila *f, int *valor) {
    if (estaVazia(f)) {
        printf("Fila vazia! Nao ha o que remover.\n");
        return false;
    }
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;   // movimento circular
    f->tamanho--;
    return true;
}

void listar(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos (do inicio ao fim): ");
    int idx = f->inicio;
    for (int i = 0; i < f->tamanho; i++) {
        printf("%d ", f->dados[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main(void) {
    Fila f;
    inicializar(&f);

    int opcao, valor;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Inserir um elemento na fila\n");
        printf("2. Remover um elemento da fila\n");
        printf("3. Listar os elementos armazenados\n");
        printf("4. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                if (enfileirar(&f, valor))
                    printf("Valor %d inserido.\n", valor);
                break;

            case 2:
                if (desenfileirar(&f, &valor))
                    printf("Valor removido: %d\n", valor);
                break;

            case 3:
                listar(&f);
                break;

            case 4:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
