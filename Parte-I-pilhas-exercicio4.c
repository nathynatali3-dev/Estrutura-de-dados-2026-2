#include <stdio.h>
#include <stdlib.h>

#define MAX 32 // Ajustado para 32 bits, suficiente para representar números inteiros padrão

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

int main() {
    Pilha p;
    inicializar(&p);
    
    int n;

    // Solicita o número e rejeita entradas negativas
    do {
        printf("Digite um numero inteiro nao negativo: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Erro: Entradas negativas nao sao permitidas. Tente novamente.\n");
        }
    } while (n < 0);

    printf("Representacao binaria de %d: ", n);

    // Tratamento especial para o número 0 (cuja representação binária é 0)
    if (n == 0) {
        empilhar(&p, 0);
    } else {
        int temp = n;
        // Divisões sucessivas por 2, empilhando os restos
        while (temp > 0) {
            empilhar(&p, temp % 2);
            temp /= 2;
        }
    }

    // Desempilha os valores para apresentar na ordem correta
    while (!estaVazia(&p)) {
        printf("%d", desempilhar(&p));
    }
    printf("\n");

    return 0;
}
