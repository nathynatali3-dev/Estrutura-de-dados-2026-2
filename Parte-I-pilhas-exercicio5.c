#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima do histórico

typedef struct {
    int itens[MAX];
    int topo; // Índice do topo (-1 se vazia)
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Empilhar (push)
void empilhar(Pilha *p, int valor) {
    if (!estaCheia(p)) {
        p->topo++;
        p->itens[p->topo] = valor;
    }
}

// Desempilhar (pop)
int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        return -1;
    } else {
        int valor = p->itens[p->topo];
        p->topo--;
        return valor;
    }
}

// Alterar valor: guarda o valor atual na pilha antes de substituí-lo
void alterarValor(Pilha *p, int *atual, int novoValor) {
    if (estaCheia(p)) {
        printf("Aviso: Historico cheio! Nao e possivel fazer novas alteracoes (limite atingido).\n");
    } else {
        empilhar(p, *atual); // Salva o valor atual no histórico
        *atual = novoValor;  // Atualiza para o novo valor
        printf("Valor alterado com sucesso para: %d\n", *atual);
    }
}

// Desfazer: recupera da pilha o valor anterior e o torna o atual
void desfazer(Pilha *p, int *atual) {
    if (estaVazia(p)) {
        printf("Aviso: Nao e possivel desfazer (historico vazio).\n");
    } else {
        *atual = desempilhar(p);
        printf("Ultima alteracao desfeita. Valor atual restaurado para: %d\n", *atual);
    }
}

// Consultar: mostra o valor atual e o histórico disponível
void consultar(Pilha p, int atual) {
    printf("\n--- CONSULTA DE ESTADO ---\n");
    printf("Valor atual: %d\n", atual);
    
    if (estaVazia(&p)) {
        printf("Historico de alteracoes: (vazio)\n");
    } else {
        printf("Historico (do mais recente para o mais antigo):\n")
        for (int i = p.topo; i >= 0; i--) {
            printf(" -> %d\n", p.itens[i]);
        }
    }
    printf("--------------------------\n")
}

int main() {
    Pilha historico;
    inicializar(&historico);
    
    int valorAtual = 0; // Valor inicial igual a zero
    int opcao, novoValor;

    do {
        printf("\n=== MENU SISTEMA DE HISTORICO ===\n");
        printf("1. Alterar valor\n");
        printf("2. Desfazer alteracao\n");
        printf("3. Consultar valor e historico\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o novo valor: ");
                scanf("%d", &novoValor);
                alterarValor(&historico, &valorAtual, novoValor);
                break;
            case 2:
                desfazer(&historico, &valorAtual);
                break;
            case 3:
                consultar(historico, valorAtual);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
