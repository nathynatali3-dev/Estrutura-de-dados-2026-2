#include <stdio.h>

int main(void) {
    int vetor[] = {1, 2, 3};
    int *p1;
    int **p2;
    int ***p3;
  
    p1 = vetor;
    p2 = &p1;   
    p3 = &p2;   

    printf("a) Primeiro elemento:\n");
    printf("   Via *p1:  %d\n", *p1);
    printf("   Via **p2: %d\n", **p2);
    printf("   Via ***p3: %d\n\n", ***p3);

    ***p3 = 10;

    (*p2)++; 

    ***p3 = 20; 

    printf("e) Vetor completo ao final: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
