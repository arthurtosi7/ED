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

char* retornaNome (Aluno* aluno)
{
    return aluno->nome;
}

char* retornaMatricula (Aluno* aluno)
{
    return aluno->matricula;
}

void imprimeAluno (Aluno* aluno) {
    printf ("%s - %s\n", aluno->nome, aluno->matricula);
}

void liberaAluno (Aluno* aluno)
{
    free(aluno->nome);
    free(aluno->matricula);
    free(aluno);
}
