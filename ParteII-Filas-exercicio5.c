#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima de tarefas na fila

typedef struct {
    int itens[MAX];
    int inicio; // Mantido sempre em 0
    int fim;    // Controla a próxima posição livre no final
} FilaRodizio;

// Inicializa a fila
void inicializar(FilaRodizio *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(FilaRodizio *f) {
    return f->fim == 0;
}

// Verifica se a fila está cheia
int estaCheia(FilaRodizio *f) {
    return f->fim == MAX;
}

// Inserir na fila (Enqueue)
void enfileirar(FilaRodizio *f, int valor) {
    if (estaCheia(f)) {
        printf("Aviso: Fila cheia! Nao foi possivel inserir a tarefa %d.\n", valor);
    } else {
        f->itens[f->fim] = valor;
        f->fim++;
    }
}

// Desenfileirar (Dequeue) com deslocamento para a esquerda (Início = 0)
int desenfileirar(FilaRodizio *f) {
    if (estaVazia(f)) {
        return -1; // Fila vazia
    } else {
        int valorRemovido = f->itens[0]; // A primeira tarefa está sempre no índice 0
        
        // Desloca os elementos restantes uma posição para a esquerda
        for (int i = 0; i < f->fim - 1; i++) {
            f->itens[i] = f->itens[i + 1];
        }
        
        f->fim--; // Libera espaço no final
        return valorRemovido;
    }
}

// Listar tarefas aguardando no rodízio
void listarTarefas(FilaRodizio f) {
    if (estaVazia(&f)) {
        printf("A fila de tarefas esta vazia.\n");
    } else {
        printf("\n--- Fila de Tarefas em Rodizio (do inicio ao fim) ---\n");
        for (int i = 0; i < f.fim; i++) {
            printf("[ Tarefa ID: %d ] ", f.itens[i]);
        }
        printf("\n----------------------------------------------------\n");
    }
}

// Executar uma rodada de rodízio
void executarRodada(FilaRodizio *f) {
    if (estaVazia(f)) {
        printf("Aviso: Nao ha tarefas na fila para executar o rodizio.\n");
        return;
    }

    // Retira a primeira tarefa da fila
    int tarefaAtual = desenfileirar(f);
    printf("\nExecutando tarefa da vez -> ID: %d\n", tarefaAtual);

    int concluida;
    do {
        printf("A tarefa %d foi concluida? (Digite 1 para Sim / 0 para Nao): ", tarefaAtual);
        scanf("%d", &concluida);
        if (concluida != 0 && concluida != 1) {
            printf("Opcao invalida! Digite apenas 1 para Sim ou 0 para Nao.\n");
        }
    } while (concluida != 0 && concluida != 1);

    if (concluida == 1) {
        printf("Tarefa %d concluida com sucesso e removida do rodizio.\n", tarefaAtual);
    } else {
        printf("Tarefa %d nao concluida. Retornando para o final da fila.\n", tarefaAtual);
        enfileirar(f, tarefaAtual); // Coloca novamente no final da fila
    }
}

int main() {
    FilaRodizio fila;
    inicializar(&fila);
    int opcao, id;

    do {
        printf("\n=== MENU RODIZIO DE TAREFAS ===\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Executar uma rodada de rodizio\n");
        printf("3. Listar tarefas na fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador (numero) da tarefa: ");
                scanf("%d", &id);
                enfileirar(&fila, id);
                printf("Tarefa %d adicionada à fila.\n", id);
                break;
            case 2:
                executarRodada(&fila);
                break;
            case 3:
                listarTarefas(fila);
                break;
            case 4:
                printf("Encerrando o programa de rodizio...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
