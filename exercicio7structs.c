#include <stdio.h>

typedef struct {
    char nome[20];
    float nota;
} Aluno;

void ordenarPorNota(Aluno v[], int n) {
    int i, j;
    Aluno temp;
    
    // Algoritmo de ordenação (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Para ordem decrescente, se a nota do atual for MENOR que a do próximo, trocamos
            if (v[j].nota < v[j+1].nota) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

int main() {
    Aluno turma[5] = {
        {"Ana", 7.0f},
        {"Bruno", 9.5f},
        {"Carla", 6.0f},
        {"Diego", 8.5f},
        {"Elis", 9.5f},
    };
    int i;

    ordenarPorNota(turma, 5);
    for (i = 0; i < 5; i++) {
        printf("%dº: %s (%.1f)\n", i + 1, turma[i].nome, turma[i].nota);
    }
    return 0;
}
