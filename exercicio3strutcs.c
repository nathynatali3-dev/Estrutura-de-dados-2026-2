#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
} Aluno;

int main() {

    Aluno alunos[100];
    int quantidade;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {

        printf("Informe os dados do aluno(%d):");

        scanf("%s %d %f %f",
              alunos[i].nome,
              &alunos[i].matricula,
              &alunos[i].nota1,
              &alunos[i].nota2);
    }
    printf("Matricula\tNome\t\tMedia\n");

    for (int i = 0; i < quantidade; i++) {
        float media;
        media = (alunos[i].nota1 + alunos[i].nota2) / 2;

        printf(" %d, %s, %.2f\n",
               alunos[i].matricula,
               alunos[i].nome,
               media);
    }

    return 0;
}
