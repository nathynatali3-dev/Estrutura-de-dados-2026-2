#include <stdio.h>

typedef struct {
    char nome[30];
    char cargo[20];
    float salario;
} Funcionario;

void reajustar(Funcionario *f, float perc) {
    // Aumenta o salário do funcionário apontado por f em 'perc' por cento
    f->salario += f->salario * (perc / 100.0f);
}

Funcionario *maiorSalario(Funcionario v[], int n) {
    if (n <= 0) return NULL;
    
    // Assume inicialmente que o primeiro funcionário tem o maior salário
    Funcionario *maior = &v[0];
    
    // Percorre o restante do vetor comparando os salários
    for (int i = 1; i < n; i++) {
        if (v[i].salario > maior->salario) {
            maior = &v[i]; // Atualiza o ponteiro para o funcionário com maior salário
        }
    }
    
    return maior;
}

int main() {
    Funcionario equipe[5] = {
        {"Marcos",  "Analista", 3200.0f},
        {"Julia",   "Gerente",  5400.0f},
        {"Paulo",   "Estagiario", 1200.0f},
        {"Renata",  "Analista", 3400.0f},
        {"Sergio",  "Diretor",  8000.0f},
    };
    int i;
    Funcionario *top;

    for (i = 0; i < 5; i++) {
        reajustar(&equipe[i], 8.0f);
    }
    top = maiorSalario(equipe, 5);
    printf("Maior salario apos reajuste: %s - %.2f\n", top->nome, top->salario);
    printf("Salario da Julia apos reajuste: %.2f\n", equipe[1].salario);
    return 0;
}
