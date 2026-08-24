#include <stdio.h>
#include <ctype.h>

int contarVogais(const char *texto) {
    int contador = 0;

    while (*texto != '\0') {
        char c = tolower((unsigned char)*texto);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    return contador;
}

int main(void) {
    char frase[100];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    int total = contarVogais(frase);

    printf("Quantidade de vogais encontradas: %d\n", total);

    return 0;
}
