#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
    } else {
        p->topo++;
        p->itens[p->topo] = valor;
        printf("Elemento %d empilhado com sucesso.\n", valor);
    }
}

// Desempilhar (pop)
int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    } else {
        int valor = p->itens[p->topo];
        p->topo--;
        return valor;
    }
}

// Nova funcionalidade: Consultar o topo sem removê-lo
void consultarTopo(Pilha p) {
    if (estaVazia(&p)) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("Elemento no topo: %d\n", p.itens[p.topo]);
    }
}

// Nova funcionalidade: Mostrar a quantidade calculada pelo campo topo (topo + 1)
void mostrarQuantidade(Pilha p) {
    int quantidade = p.topo + 1;
    printf("Quantidade de elementos na pilha: %d\n", quantidade);
}

int main() {
    Pilha p;
    inicializar(&p);
    int opcao, valor;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Consultar topo\n");
        printf("4. Mostrar quantidade de elementos\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(&p, valor);
                break;
            case 2:
                valor = desempilhar(&p);
                if (valor != -1) {
                    printf("Elemento desempilhado: %d\n", valor);
                }
                break;
            case 3:
                consultarTopo(p);
                break;
            case 4:
                mostrarQuantidade(p);
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
