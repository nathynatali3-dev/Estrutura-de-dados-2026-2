#include <stdio.h>

typedef struct {
    float real;
    float imaginario;
} NumeroComplexo;


void Atribui(NumeroComplexo *n, float real, float imaginario)
{
    n->real = real;
    n->imaginario = imaginario;
}


void Imprime(NumeroComplexo n)
{
    if (n.imaginario >= 0)
        printf("%.2f + %.2fi\n", n.real, n.imaginario);
    else
        printf("%.2f - %.2fi\n", n.real, -n.imaginario);
}


void Copia(NumeroComplexo original, NumeroComplexo *copia)
{
    copia->real = original.real;
    copia->imaginario = original.imaginario;
}


NumeroComplexo Soma(NumeroComplexo n1, NumeroComplexo n2)
{
    NumeroComplexo resultado;

    resultado.real = n1.real + n2.real;
    resultado.imaginario = n1.imaginario + n2.imaginario;

    return resultado;
}


int EhReal(NumeroComplexo n)
{
    if (n.imaginario == 0)
        return 1;

    return 0;
}


int main()
{
    NumeroComplexo n1;
    NumeroComplexo n2;
    NumeroComplexo copia;
    NumeroComplexo resultado;


    Atribui(&n1, 3, 4);
    Atribui(&n2, 2, 5);


    printf("Numero 1: ");
    Imprime(n1);

    printf("Numero 2: ");
    Imprime(n2);


    Copia(n1, &copia);

    printf("Copia do numero 1: ");
    Imprime(copia);


    resultado = Soma(n1, n2);

    printf("Soma: ");
    Imprime(resultado);


    if (EhReal(n1))
        printf("Numero 1 e real.\n");
    else
        printf("Numero 1 nao e real.\n");


    return 0;
}
