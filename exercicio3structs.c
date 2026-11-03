#include <stdio.h>
#include <stdlib.h> // Para usar a função abs() se necessário

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto a;
    Ponto b;
} Retangulo;

int area(Retangulo r) {
    int largura = r.b.x - r.a.x;
    int altura = r.b.y - r.a.y;
    // Garantimos valores positivos caso os pontos venham invertidos
    if (largura < 0) largura = -largura;
    if (altura < 0) altura = -altura;
    
    return largura * altura;
}

int perimetro(Retangulo r) {
    int largura = r.b.x - r.a.x;
    int altura = r.b.y - r.a.y;
    if (largura < 0) largura = -largura;
    if (altura < 0) altura = -altura;
    
    return 2 * (largura + altura);
}

void deslocar(Retangulo *r, int dx, int dy) {
    // Como r é um ponteiro para Retangulo, usamos -> para acessar os pontos a e b
    r->a.x += dx;
    r->a.y += dy;
    r->b.x += dx;
    r->b.y += dy;
}

int main() {
    Retangulo ret = {{2, 3}, {10, 7}};

    printf("Area: %d\n", area(ret));
    printf("Perimetro: %d\n", perimetro(ret));
    deslocar(&ret, 5, -1);
    printf("Novo a: (%d, %d)\n", ret.a.x, ret.a.y);
    printf("Novo b: (%d, %d)\n", ret.b.x, ret.b.y);
    printf("Area depois: %d\n", area(ret));
    return 0;
}
