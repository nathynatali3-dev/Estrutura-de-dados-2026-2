#include <stdio.h>

int main () {
    int x = 20; 
    int y = 15;      
    int *p1, *p2;
    p1 = &x;
    p2 = &y;
    
    printf("valor da variavel x: %d", x);
    printf("endereco da variavel x: %p", &x);
    printf("conteudo do ponteiro p1: %p", p1);
    printf("valor apontado pelo p1: %d", *p1);
    printf("valor da soma (*p1 + *p2): %d", *p1 + *p2); 
    
    return 0;
}
