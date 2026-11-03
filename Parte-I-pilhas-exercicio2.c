#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Capacidade máxima de cinco bandejas

typedef struct {
    int idBandejas[MAX];
    int topo; // Índice do topo (-1 se a pilha estiver vazia)
} PilhaBandejas;

// Inicializa a pilha de bandejas
void inicializar(PilhaBandejas *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(PilhaBandejas *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int estaCheia(PilhaBandejas *p) {
    return p->topo == MAX - 1;
}

// Adicionar uma bandeja (empilhar)
void adicionarBandeja(PilhaBandejas *p, int id) {
    if (estaCheia(p)) {
        printf("Aviso: A pilha de bandejas esta cheia! Nao e possivel adicionar mais bandejas no momento.\n");
    } else {
        p->topo++;
        p->idBandejas[p->topo] = id;
        printf("Bandeja %d adicionada ao topo da pilha.\n", id);
    }
}

// Retirar a bandeja do topo (desempilhar), informando seu número
int retirarBandeja(PilhaBandejas *p) {
    if (estaVazia(p)) {
        printf("Aviso: A pilha de bandejas esta vazia! Nenhuma bandeja disponivel para retirada.\n");
        return -1;
    } else {
        int idRetirada = p->idBandejas[p->topo];
        p->topo--;
        return idRetirada;
    }
}

// Consultar a próxima bandeja disponível, sem retirá-la
void consultarProxima(PilhaBandejas p) {
    if (estaVazia(&p)) {
        printf("A pilha de bandejas esta vazia no momento.\n");
    } else {
        printf("Proxima bandeja disponivel no topo: %d\n", p.idBandejas[p.topo]);
    }
}

// Mostrar as bandejas do topo até a base
void mostrarBandejas(PilhaBandejas p) {
    if (estaVazia(&p)) {
        printf("A pilha de bandejas esta vazia.\n");
    } else {
        printf("\n--- Pilha de Bandejas (do topo para a base) ---\n")
        for (int i = p.topo; i >= 0; i--) {
            printf("Bandeja ID: %d\n", p.idBandejas[i]);
        }
        printf("-----------------------------------------------\n");
    }
}

int main() {
    PilhaBandejas pilha;
    inicializar(&pilha);

    printf("=== TESTE OBRIGATORIO ===\n");
    
    // Adicione as bandejas 101, 102 e 103
    adicionarBandeja(&pilha, 101);
    adicionarBandeja(&pilha, 102);
    adicionarBandeja(&pilha, 103);

    // Mostra o estado atual da pilha
    mostrarBandejas(pilha);

    // Realize duas retiradas
    printf("\nRealizando 1ª retirada...\n");
    int retirada1 = retirarBandeja(&pilha);
    if (retirada1 != -1) {
        printf("Bandeja retirada: %d\n", retirada1);
    }

    printf("\nRealizando 2ª retirada...\n");
    int retirada2 = retirarBandeja(&pilha);
    if (retirada2 != -1) {
        printf("Bandeja retirada: %d\n", retirada2);
    }

    // Mostra o estado final para sabermos qual permaneceu
    printf("\nEstado final da pilha:\n");
    mostrarBandejas(pilha);
    
    consultarProxima(pilha);

    return 0
}
