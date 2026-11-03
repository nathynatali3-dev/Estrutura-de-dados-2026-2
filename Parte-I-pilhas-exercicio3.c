#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Capacidade máxima da pilha

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
    }
}

// Desempilhar (pop): adaptada para retornar o valor removido e tratar pilha vazia
int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("Aviso: Pilha vazia!\n");
        return -1; // Retorno de erro/sentinela
    } else {
        int valor = p->itens[p->topo];
        p->topo--;
        return valor;
    }
}

int main() {
    Pilha p;
    inicializar(&p);
    
    int qtd, i, valor

    // Solicita a quantidade de números garantindo que esteja entre 1 e MAX
    do {
        printf("Digite a quantidade de numeros (entre 1 e %d): ", MAX);
        scanf("%d", &qtd);
        if (qtd < 1 || qtd > MAX) {
            printf("Quantidade invalida! Tente novamente.\n");
        }
    } while (qtd < 1 || qtd > MAX);

    // Lê e empilha os valores fornecidos pelo usuário
    printf("Digite os %d numeros inteiros:\n", qtd);
    for (i = 0; i < qtd; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &valor);
        empilhar(&p, valor);
    }

    // Retira os elementos da pilha e apresenta na ordem inversa (LIFO)
    printf("\nSequencia invertida (ordem de retirada):\n");
    for (i = 0; i < qtd; i++) {
        int desempilhado = desempilhar(&p);
        if (desempilhado != -1) {
            printf("%d ", desempilhado);
        }
    }
    printf("\n");

    // Confirmação final de que a pilha está vazia
    if (estaVazia(&p)) {
        printf("Ao final, a pilha esta vazia.\n");
    }

    return 0;
}
