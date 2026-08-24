#include <stdio.h>
int main(void) {
    int valor = 50;
    int *p, *q;

    p = &valor;
    q = p;
    (*q) *= 2;

    printf("*%d", valor);
    
    return 0;
}


respostas
a) 
b) a correção do codigo foi adicionar o & no *p = valor.
c) codigo modificado, o valor final para 100 por meio do ponteiro, foi adicionado um novo ponteiro para chegar ao resultado.
  
