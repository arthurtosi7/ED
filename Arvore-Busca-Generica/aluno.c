#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char* nome;
    char* matricula;
};

Aluno* criaAluno (char* nome, char* matricula)
{
    Aluno* aluno = (Aluno*) malloc (sizeof(Aluno));
    aluno->nome = strdup(nome);
    aluno->matricula = strdup(matricula);
    return aluno;
}

static int retornaComparacao (char* nomeMaior, char* nomeMenor) {
    return strcmp (nomeMaior, nomeMenor);
}

int comparaAlunos (void* al1, void* al2) {
    Aluno* aluno1 = (Aluno*) al1;
    Aluno* aluno2 = (Aluno*) al2;
    return retornaComparacao (aluno1->nome, aluno2->nome);
}

char* retornaNome (Aluno* aluno)
{
    return aluno->nome;
}

char* retornaMatricula (Aluno* aluno)
{
    return aluno->matricula;
}

void imprimeAluno (void* al) {
    Aluno* aluno = (Aluno*) al;
    printf ("%s - %s\n", aluno->nome, aluno->matricula);
}

void liberaAluno (Aluno* aluno)
{
    free(aluno->nome);
    free(aluno->matricula);
    free(aluno);
}
