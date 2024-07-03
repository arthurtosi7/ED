#ifndef _ARVORE_H_
#define _ARVORE_H_

#include "aluno.h"

typedef struct arvore_binaria ArvBB;

ArvBB* criaArvoreVazia ();

ArvBB* insereArvore (Aluno*, ArvBB*);

Aluno* retornaAluno (ArvBB*);

ArvBB* buscaArvore (Aluno* al, ArvBB* arv);

ArvBB* retiraArvore (Aluno* al, ArvBB* arv);

void imprimeArvore (ArvBB* arv);

void liberaArvore (ArvBB* arv);

#endif