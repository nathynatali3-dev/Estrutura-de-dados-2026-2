#include <stdio.h>
int main (void) {
    int vetor [] = {10, 20, 30, 40};
    int *p = vetor;

    printf("%d", *p);
    printf("%d", *p++);
    printf("%d", (*p)++);
    printf("%d", *p);
    
    return 0;
}

respostas
a) 10102021
b) p apona para o segundo elemento do vetor
c) 10,30,40 não foram auterados, ja o 20 foi auterado para 21 onde foi incrementado pela operação (*p)++
d) p++ avança para a próxima posição, *p++ avança para a próxima posição, (*p)++ permanece na mesma posição
