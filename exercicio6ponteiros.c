#include <stdio.h>

int *encontrarMaior(int *inicio, int tamanho) {
    int *maior = inicio; 

    for (int i = 1; i < tamanho; i++) {
        
        if (*(inicio + i) > *maior) {
            maior = inicio + i; 
        }
    }

    return maior; 
}

int main(void) {
    int numeros[5];
    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int *ptrMaior = encontrarMaior(numeros, 5);

    int posicao = ptrMaior - numeros;

    printf("\n--- RESULTADO ---\n");
    printf("Maior valor: %d\n", *ptrMaior);
    printf("Posicao no vetor: %d\n", posicao);
    printf("Endereco de memoria: %p\n", (void*)ptrMaior);

    return 0;
}
