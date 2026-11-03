#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[30];
    Data data;
} Evento;

int dataMaior(Data d1, Data d2) {
    // Compara primeiro o ano
    if (d1.ano != d2.ano) {
        return d1.ano > d2.ano;
    }
    // Se o ano for igual, compara o mês
    if (d1.mes != d2.mes) {
        return d1.mes > d2.mes;
    }
    // Se mês e ano forem iguais, compara o dia
    return d1.dia > d2.dia;
}

Evento *eventoMaisRecente(Evento v[], int n) {
    if (n <= 0) return NULL;
    
    // Assume inicialmente que o primeiro evento é o mais recente
    Evento *recente = &v[0];
    
    // Percorre o restante do vetor comparando as datas
    for (int i = 1; i < n; i++) {
        if (dataMaior(v[i].data, recente->data)) {
            recente = &v[i]; // Atualiza o ponteiro para o novo evento mais recente
        }
    }
    
    return recente;
}

int main() {
    Evento agenda[4] = {
        {"Reuniao de projeto",   {10, 3, 2026}},
        {"Entrega do TCC",       {21, 9, 2026}},
        {"Seminario de pesquisa",{5, 9, 2026}},
        {"Banca",                {2, 12, 2025}},
    };
    Evento *e;

    e = eventoMaisRecente(agenda, 4);
    printf("Mais recente: %s (%d/%d/%d)\n", e->nome, e->data.dia, e->data.mes, e->data.ano);
    return 0;
}
