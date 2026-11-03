#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
} Fila;

// Inicializa a fila
void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int estaCheia(Fila *f) {
    return (f->fim + 1) % MAX == f->inicio;
}

// Inserir na fila (Enqueue)
void enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Erro: Fila cheia!\n");
    } else {
        f->itens[f->fim] = valor;
        f->fim = (f->fim + 1) % MAX;
        printf("Elemento %d enfileirado com sucesso.\n", valor);
    }
}

// Remover da fila (Dequeue)
int desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    } else {
        int valor = f->itens[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        return valor;
    }
}

// Nova funcionalidade: Consultar o próximo elemento sem removê-lo
void consultarProximo(Fila f) {
    if (estaVazia(&f)) {
        printf("A fila esta vazia. Nao ha elementos aguardando.\n");
    } else {
        printf("Proximo elemento na fila: %d\n", f.itens[f.inicio]);
    }
}

// Nova funcionalidade: Mostrar a quantidade calculada apenas por inicio e fim
void mostrarQuantidade(Fila f) {
    int quantidade;
    if (f.fim >= f.inicio) {
        quantidade = f.fim - f.inicio;
    } else {
        quantidade = MAX - f.inicio + f.fim;
    }
    printf("Quantidade de elementos aguardando: %d\n", quantidade);
}

int main() {
    Fila f;
    inicializar(&f);
    int opcao, valor;

    do {
        printf("\n--- MENU FILA ---\n");
        printf("1. Enfileirar (Inserir)\n");
        printf("2. Desenfileirar (Remover)\n");
        printf("3. Consultar proximo elemento\n");
        printf("4. Mostrar quantidade aguardando\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser enfileirado: ");
                scanf("%d", &valor);
                enfileirar(&f, valor);
                break;
            case 2:
                valor = desenfileirar(&f);
                if (valor != -1) {
                    printf("Elemento removido: %d\n", valor);
                }
                break;
            case 3:
                consultarProximo(f);
                break;
            case 4:
                mostrarQuantidade(f);
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
