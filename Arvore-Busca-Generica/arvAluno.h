//
// Created by Arthur on 03/07/2024.
//

#ifndef ARVALUNO_H
#define ARVALUNO_H

#include "search_tree.h"
#include "aluno.h"

typedef Tree ArvAluno;

ArvAluno* createNullArvAluno ();

int arvAlunoIsEmpty (ArvAluno* arv);

ArvAluno* insertArvAluno (ArvAluno* arv, Aluno* aluno);

ArvAluno* removeArvAluno (ArvAluno* arv, Aluno* aluno);

void imprimeArvAluno (ArvAluno* arv);

void liberaArvAluno (ArvAluno* arv);



#endif //ARVALUNO_H
