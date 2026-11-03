#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima definida para o teste obrigatório

typedef struct {
    int itens[MAX];
    int inicio; // Mantido sempre igual a 0
    int fim;    // Controla a próxima posição livre no final
} FilaDeslocamento;

// Inicializa a fila
void inicializar(FilaDeslocamento *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(FilaDeslocamento *f) {
    return f->fim == 0; // Com inicio fixo em 0, se fim for 0, a fila está vazia
}

// Verifica se a fila está cheia
int estaCheia(FilaDeslocamento *f) {
    return f->fim == MAX;
}

// Inserir na fila (Enqueue)
void enfileirar(FilaDeslocamento *f, int valor) {
    if (estaCheia(f)) {
        printf("Aviso: Fila cheia! Nao foi possivel inserir o valor %d.\n", valor);
    } else {
        f->itens[f->fim] = valor;
        f->fim++;
        printf("Elemento %d enfileirado com sucesso.\n", valor);
    }
}

// Desenfileirar (Dequeue) com deslocamento para a esquerda
int desenfileirar(FilaDeslocamento *f) {
    if (estaVazia(f)) {
        printf("Aviso: Fila vazia!\n");
        return -1;
    } else {
        int valorRemovido = f->itens[0]; // O elemento da frente está sempre no índice 0
        
        // Desloca todos os elementos restantes uma posição para a esquerda
        for (int i = 0; i < f->fim - 1; i++) {
            f->itens[i] = f->itens[i + 1];
        }
        
        f->fim--; // Decrementa o fim, liberando espaço no final do vetor
        return valorRemovido;
    }
}

// Listar elementos da fila do início ao fim
void listarFila(FilaDeslocamento f) {
    if (estaVazia(&f)) {
        printf("A fila esta vazia.\n");
    } else {
        printf("\n--- Estado Atual da Fila (do inicio ao fim) ---\n");
        for (int i = 0; i < f.fim; i++) {
            printf("[ %d ] ", f.itens[i]);
        }
        printf("\n-----------------------------------------------\n");
    }
}

int main() {
    FilaDeslocamento fila;
    inicializar(&fila);

    printf("=== TESTE OBRIGATORIO ===\n\n");
    
    // 1. Insira cinco valores (preenche a capacidade máxima de MAX = 5)
    printf("1. Inserindo 5 valores (10, 20, 30, 40, 50):\n");
    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    enfileirar(&fila, 40);
    enfileirar(&fila, 50);
    
    listarFila(fila);

    // 2. Remova dois valores (libera espaço nas posições iniciais)
    printf("\n2. Realizando duas remocoes:\n");
    printf("Removido: %d\n", desenfileirar(&fila));
    printf("Removido: %d\n", desenfileirar(&fila));

    listarFila(fila);

    // 3. Insira outros dois valores (que seriam rejeitados em uma fila linear simples)
    printf("\n3. Inserindo mais dois valores (60 e 70):\n");
    enfileirar(&fila, 60);
    enfileirar(&fila, 70);

    // Apresenta o resultado final provando que foram aceitas e a ordem FIFO foi preservada
    printf("\n4. Estado final da fila (verificando preservacao da ordem FIFO):\n");
    listarFila(fila);

    return 0;
}
