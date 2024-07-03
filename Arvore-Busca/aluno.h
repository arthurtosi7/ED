#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct aluno Aluno;

Aluno* criaAluno (char* nome, char* matricula);

char* retornaNome (Aluno* aluno);

char* retornaMatricula (Aluno* aluno);

void imprimeAluno (Aluno* aluno);

void liberaAluno (Aluno* aluno);

#endif