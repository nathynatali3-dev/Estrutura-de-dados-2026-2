#include <stdio.h>

int main(void) {
    int valores[] = {1, 2, 3, 4, 5, 6};
    int tamanho = sizeof(valores) / sizeof(valores[0]);
  
    int *inicio = valores;
    int *fim = valores + (tamanho - 1);

    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++; 
        fim--;    
    }

    printf("Vetor invertido: ");
    for (int *p = valores; p < valores + tamanho; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    return 0;
}
