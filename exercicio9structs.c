#include <stdio.h>

typedef struct {
    char nome[30];
} Cliente;

typedef struct {
    Cliente cliente;
    float valor;
    int pago;
} Pedido;

float totalRecebido(Pedido v[], int n) {
    float total = 0.0f;
    // Percorre o vetor somando o valor apenas dos pedidos pagos (pago == 1)
    for (int i = 0; i < n; i++) {
        if (v[i].pago == 1) {
            total += v[i].valor;
        }
    }
    return total;
}

void marcarPago(Pedido *p) {
    // Marca o pedido apontado por p como pago (1)
    p->pago = 1;
}

int main() {
    Pedido pedidos[4] = {
        {{"Loja A"}, 150.0f, 1},
        {{"Loja B"}, 300.0f, 0},
        {{"Loja C"}, 80.0f, 1},
        {{"Loja D"}, 220.0f, 0},
    };

    printf("Total recebido antes: %.2f\n", totalRecebido(pedidos, 4));
    marcarPago(&pedidos[1]);
    printf("Total recebido depois: %.2f\n", totalRecebido(pedidos, 4));
    return 0;
}
