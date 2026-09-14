#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Registro {
    char nome[100];
    int idade;
    float salario;
    char sexo;
} Registro;


int main(){
    Registro Pessoa;

    printf("Digite o nome: ");
    scanf("%s" , &Pessoa.nome);
    fflush(stdin);
    printf("Digite a idade: ");
    scanf("%d" , &Pessoa.idade);
    printf("Digite o salario: ");
    scanf("%f" , &Pessoa.salario);
    printf("Digite o sexo: ");
    scanf("%c" , &Pessoa.sexo);
    
    return 0;
    
}
