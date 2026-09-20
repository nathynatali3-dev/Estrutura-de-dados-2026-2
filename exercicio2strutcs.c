#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ficha {
    int inscricao;
    char nome[100];
    int classe;
    float horasNormais;
    float horasExtras;

    float salarioNormal;
    float salarioExtra;
    float salarioBruto;
    float descontoINSS;
    float salarioLiquido;
} Ficha;

int main() {

    Ficha Pessoa[2];
    int quantidade;
    float salarioReferencia;
    float salarioClasse;
    float salarioHoraNormal;
    float salarioHoraExtra;

    printf("Digite o salario de referencia: ");
    scanf("%f", &salarioReferencia);
    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {

        printf("\nFuncionario %d\n", i + 1);
        printf("Digite o numero de inscricao: ");
        scanf("%d", &Pessoa[i].inscricao);
        printf("Digite o nome: ");
        scanf(" %99[^\n]", Pessoa[i].nome);
        printf("Digite a classe (1 ou 2): ");
        scanf("%d", &Pessoa[i].classe);
        printf("Digite as horas normais: ");
        scanf("%f", &Pessoa[i].horasNormais);
        printf("Digite as horas extras: ");
        scanf("%f", &Pessoa[i].horasExtras);

        if (Pessoa[i].classe == 1) {
            salarioClasse = salarioReferencia * 1.3;
        }
        else if (Pessoa[i].classe == 2) {
            salarioClasse = salarioReferencia * 1.9;
        
        }

        Pessoa[i].salarioNormal = salarioClasse;
        salarioHoraNormal = salarioClasse / Pessoa[i].horasNormais;
        salarioHoraExtra = salarioHoraNormal * 1.30;
        Pessoa[i].salarioExtra =
            salarioHoraExtra * Pessoa[i].horasExtras;
        Pessoa[i].salarioBruto =
            Pessoa[i].salarioNormal + Pessoa[i].salarioExtra;
        Pessoa[i].descontoINSS =
            Pessoa[i].salarioBruto * 0.11;
        Pessoa[i].salarioLiquido =
            Pessoa[i].salarioBruto - Pessoa[i].descontoINSS;
    }

    for (int i = 0; i < quantidade; i++) {

        if (Pessoa[i].classe != 1 && Pessoa[i].classe != 2) {
            continue;
        }

        
        printf("Contracheque:\n");
        printf("Numero da inscricao: %d\n",
               Pessoa[i].inscricao);
        printf("Nome: %s\n",
               Pessoa[i].nome);
        printf("Salario horas normais: R$ %.2f\n",
               Pessoa[i].salarioNormal);
        printf("Salario horas extras: R$ %.2f\n",
               Pessoa[i].salarioExtra);
        printf("INSS: R$ %.2f\n",
               Pessoa[i].descontoINSS);
        printf("Salario liquido: R$ %.2f\n",
               Pessoa[i].salarioLiquido);
    }

    return 0;
}
