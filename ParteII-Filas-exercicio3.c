#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima de trabalhos na fila de impressão

typedef struct {
    int trabalhos[MAX];
    int inicio;
    int fim;
} FilaImpressao;

// Inicializa a fila
void inicializar(FilaImpressao *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(FilaImpressao *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int estaCheia(FilaImpressao *f) {
    return (f->fim + 1) % MAX == f->inicio;
}

// Adicionar um trabalho à fila (Enqueue)
void adicionarTrabalho(FilaImpressao *f, int id) {
    if (estaCheia(f)) {
        printf("Aviso: A fila de impressao esta cheia! Nao e possivel adicionar novos trabalhos.\n");
    } else {
        f->trabalhos[f->fim] = id;
        printf("Trabalho %d adicionado à fila de impressao.\n", id);
        f->fim = (f->fim + 1) % MAX;
    }
}

// Imprimir próximo (remover o primeiro da fila - Dequeue)
int imprimirProximo(FilaImpressao *f) {
    if (estaVazia(f)) {
        printf("Aviso: Nao ha trabalhos pendentes na fila.\n");
        return -1;
    } else {
        int idTrabalho = f->trabalhos[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        return idTrabalho;
    }
}

// Listar pendentes (consultar elementos sem removê-los)
void listarPendentes(FilaImpressao f) {
    if (estaVazia(&f)) {
        printf("Nao ha trabalhos pendentes no momento.\n");
    } else {
        printf("\n--- Trabalhos Pendentes na Impressora ---\n");
        int i = f.inicio;
        while (i != f.fim) {
            printf("[ Trabalho ID: %d ] ", f.trabalhos[i]);
            i = (i + 1) % MAX;
        }
        printf("\n-----------------------------------------\n");
    }
}

// Imprimir todos: processa e remove os trabalhos um a um até a fila esvaziar
void imprimirTodos(FilaImpressao *f) {
    if (estaVazia(f)) {
        printf("Aviso: Nao ha trabalhos para imprimir (fila vazia).\n");
    } else {
        printf("\n--- Iniciando Impressao de Todos os Trabalhos ---\n");
        while (!estaVazia(f)) {
            int id = imprimirProximo(f);
            printf("Imprimindo trabalho ID: %d...\n", id);
        }
        printf("Todos os trabalhos foram impressos com sucesso. Fila vazia.\n");
        printf("--------------------------------------------------\n");
    }
}

int main() {
    FilaImpressao fila;
    inicializar(&fila);
    int opcao, id;

    do {
        printf("\n=== MENU FILA DE IMPRESSAO ===\n");
        printf("1. Adicionar trabalho\n");
        printf("2. Imprimir proximo\n");
        printf("3. Listar trabalhos pendentes\n");
        printf("4. Imprimir todos os trabalhos\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o identificador (numero) do trabalho: ");
                scanf("%d", &id);
                adicionarTrabalho(&fila, id);
                break;
            case 2:
                id = imprimirProximo(&fila);
                if (id != -1) {
                    printf("Imprimindo agora o trabalho: %d\n", id);
                }
                break;
            case 3:
                listarPendentes(fila);
                break;
            case 4:
                imprimirTodos(&fila);
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
