#include <stdio.h>
int main () {

    int numeros [6] = {4, 8, 12, 16, 20, 24};
    int *p;
    int tamanho;
    int soma = 0;
    p = &numeros;
    
    for (int *p = numeros; p < numeros + 6; p++) {
        printf("Elemento: %d", *p, p);
        soma += *p; }

    printf("Soma de todos os elementos: %d", soma);
    
    return 0;
}
