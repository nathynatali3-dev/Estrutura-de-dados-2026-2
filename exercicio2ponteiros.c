#include <stdio.h>

int main (void) {
    int x = 10;
    int *p = &x;
    int *q = p;
    (*p) += 5;
    (*q) *= 2;
    printf("x = %d", x);
    printf("*p = %d", *p);
    printf("*q = %d", *q);

    return 0;

}

respostas
a) x = 30, *p = 30, *q = 30
b) Porque o q esta armazenando o p assim como o p esta armazenando o x, por isso eles se modificam.
c) Sim, pois o endereço de x esta armazenado no p e no q armazenado o p, que terá o endereço de x.
