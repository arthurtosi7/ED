#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct aluno Aluno;

Aluno* criaAluno (char* nome, char* matricula);

int comparaAlunos (void* al1, void* al2);

char* retornaNome (Aluno* aluno);

char* retornaMatricula (Aluno* aluno);

void imprimeAluno (void* aluno);

void liberaAluno (Aluno* aluno);

#endif