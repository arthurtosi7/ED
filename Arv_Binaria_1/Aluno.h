#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct aluno Aluno;

Aluno* create_aluno (char* name);

char* return_name (Aluno*);

void print_aluno (Aluno*);

void free_aluno (Aluno*);

#endif