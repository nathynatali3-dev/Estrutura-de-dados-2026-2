#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima da fila de senhas

typedef struct {
    int senhas[MAX];
    int inicio;
    int fim;
} FilaSenhas;

// Inicializa a fila
void inicializar(FilaSenhas *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int estaVazia(FilaSenhas *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int estaCheia(FilaSenhas *f) {
    return (f->fim + 1) % MAX == f->inicio;
}

// Gerar uma senha e adicioná-la à fila (somente se possível)
void gerarSenha(FilaSenhas *f, int *proximaSenha) {
    if (estaCheia(f)) {
        printf("Aviso: A fila de atendimento esta cheia! Nao e possivel gerar nova senha no momento.\n");
    } else {
        f->senhas[f->fim] = *proximaSenha;
        printf("Senha gerada e adicionada à fila: %d\n", *proximaSenha);
        f->fim = (f->fim + 1) % MAX;
        (*proximaSenha)++; // Incrementa para a próxima senha
    }
}

// Chamar a próxima senha, removendo-a da fila
int chamarProxima(FilaSenhas *f) {
    if (estaVazia(f)) {
        printf("Aviso: Nao ha ninguem aguardando atendimento (fila vazia).\n");
        return -1;
    } else {
        int senhaChamada = f->senhas[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        return senhaChamada;
    }
}

// Consultar a próxima senha sem removê-la
void consultarProxima(FilaSenhas f) {
    if (estaVazia(&f)) {
        printf("A fila esta vazia. Nenhuma senha aguardando.\n");
    } else {
        printf("Proxima senha a ser atendida: %d\n", f.senhas[f.inicio]);
    }
}

// Mostrar todas as senhas aguardando atendimento
void mostrarAguardando(FilaSenhas f) {
    if (estaVazia(&f)) {
        printf("Nao ha senhas aguardando atendimento no momento.\n");
    } else {
        printf("\n--- Senhas Aguardando Atendimento ---\n");
        int i = f.inicio;
        while (i != f.fim) {
            printf("[ Senha %d ] ", f.senhas[i]);
            i = (i + 1) % MAX;
        }
        printf("\n-------------------------------------\n");
    }
}

int main() {
    FilaSenhas fila;
    inicializar(&fila);
    int proximaSenha = 1; // Controla a geração automática das senhas começando em 1

    printf("=== TESTE OBRIGATORIO ===\n");
    
    // Gere três senhas
    printf("Gerando 3 senhas:\n");
    gerarSenha(&fila, &proximaSenha);
    gerarSenha(&fila, &proximaSenha);
    gerarSenha(&fila, &proximaSenha);

    // Mostra as senhas aguardando
    mostrarAguardando(fila);

    // Realize dois atendimentos
    printf("\nRealizando 1º atendimento...\n");
    int atendimento1 = chamarProxima(&fila);
    if (atendimento1 != -1) {
        printf("Chamando senha para atendimento: %d\n", atendimento1);
    }

    printf("\nRealizando 2º atendimento...\n");
    int atendimento2 = chamarProxima(&fila);
    if (atendimento2 != -1) {
        printf("Chamando senha para atendimento: %d\n", atendimento2);
    }

    // Apresenta as senhas restantes
    printf("\nSenhas restantes na fila apos os atendimentos:\n");
    mostrarAguardando(fila);
    
    consultarProxima(fila);

    return 0;
}
