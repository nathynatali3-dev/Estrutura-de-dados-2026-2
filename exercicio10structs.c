#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa {
    char nome[30];
    int prioridade;
    struct Tarefa *prox;
} Tarefa;

Tarefa *inserirTarefa(Tarefa *inicio, char nome[], int prioridade) {
    // Aloca memória para o novo nó
    Tarefa *novo = (Tarefa *)malloc(sizeof(Tarefa));
    if (novo == NULL) {
        return inicio; // Erro de alocação
    }
    
    // Preenche os dados do novo nó
    strcpy(novo->nome, nome);
    novo->prioridade = prioridade;
    novo->prox = NULL;
    
    // Caso 1: A lista está vazia ou o novo elemento tem a menor prioridade (vai no início)
    if (inicio == NULL || prioridade < inicio->prioridade) {
        novo->prox = inicio;
        return novo; // O novo nó passa a ser o início da lista
    }
    
    // Caso 2: Encontrar a posição correta para inserção mantendo a ordem crescente
    Tarefa *atual = inicio;
    while (atual->prox != NULL && atual->prox->prioridade <= prioridade) {
        atual = atual->prox;
    }
    
    // Insere o novo nó após o 'atual'
    novo->prox = atual->prox;
    atual->prox = novo;
    
    return inicio; // O início da lista permanece o mesmo
}

void imprimirLista(Tarefa *inicio) {
    Tarefa *atual = inicio;
    // Percorre a lista até o final (NULL) imprimindo cada tarefa
    while (atual != NULL) {
        printf("%s (%d)\n", atual->nome, atual->prioridade);
        atual = atual->prox;
    }
}

int main() {
    Tarefa *fila = NULL;
    Tarefa *p;

    fila = inserirTarefa(fila, "Corrigir bug critico", 1);
    fila = inserirTarefa(fila, "Responder e-mails", 5);
    fila = inserirTarefa(fila, "Preparar aula", 2);
    fila = inserirTarefa(fila, "Revisar artigo", 3);

    imprimirLista(fila);

    // Liberação da memória alocada
    while (fila != NULL) {
        p = fila;
        fila = fila->prox;
        free(p);
    }
    return 0;
}
