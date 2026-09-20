#ifndef ContaBancaria.h
#define ContaBancaria.h
typedef struct {
    int numero;
    float saldo;
} ContaBancaria;

void InicializaConta(ContaBancaria *conta, int numero, float saldo);

int VerificaNum(ContaBancaria conta, int num);

float ConsultaSaldo(ContaBancaria conta);
-------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "contabancaria.h"

void InicializaConta(ContaBancaria *conta, int numero, float saldo)
{
    conta->numero = numero;
    conta->saldo = saldo;
}

int VerificaNum(ContaBancaria conta, int num)
{
    if (conta.numero == num)
        return 1;

    return 0;
}

float ConsultaSaldo(ContaBancaria conta)
{
    return conta.saldo;
}
---------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

typedef struct {
    int ncontas;
    ContaBancaria *contas;
} Contas;


void InicializaContas(Contas *cnt)
{
    cnt->ncontas = 0;
    cnt->contas = NULL;
}


void CriarNovasContas(Contas *cnt, int n)
{
    int i;
    float saldo;

    cnt->contas = realloc(
        cnt->contas,
        (cnt->ncontas + n) * sizeof(ContaBancaria)
    );

    if (cnt->contas == NULL)
    {
        printf("Erro de memoria.\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        printf("Digite o saldo da conta %d: ",
               cnt->ncontas + i + 1);

        scanf("%f", &saldo);

        InicializaConta(
            &cnt->contas[cnt->ncontas + i],
            cnt->ncontas + i + 1,
            saldo
        );
    }

    cnt->ncontas += n;
}


void ImprimirContas(Contas *cnt)
{
    int i;

    printf("\nContas existentes:\n");

    for (i = 0; i < cnt->ncontas; i++)
    {
        printf("Conta: %d | Saldo: R$ %.2f\n",
               cnt->contas[i].numero,
               cnt->contas[i].saldo);
    }
}


void ZerarSaldoConta(Contas *cnt, int num)
{
    int i;

    for (i = 0; i < cnt->ncontas; i++)
    {
        if (VerificaNum(cnt->contas[i], num))
        {
            cnt->contas[i].saldo = 0;
            return;
        }
    }

    printf("Conta %d nao encontrada.\n", num);
}


int main()
{
    Contas banco;
    int quantidade;
    int numero;

    InicializaContas(&banco);

    printf("Quantas contas deseja criar? ");
    scanf("%d", &quantidade);

    CriarNovasContas(&banco, quantidade);

    ImprimirContas(&banco);

    printf("\nDigite o numero da conta que deseja zerar: ");
    scanf("%d", &numero);

    ZerarSaldoConta(&banco, numero);

    printf("\nContas apos zerar o saldo:\n");

    ImprimirContas(&banco);

    free(banco.contas);

    return 0;
}
