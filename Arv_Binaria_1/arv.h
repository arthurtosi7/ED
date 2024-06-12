#ifndef _ARVORE_BIN_H_
#define _ARVORE_BIN_H_

#include "Aluno.h"

typedef struct arv Arvore;

Arvore* create_empty ();
Arvore* create_arvore (Aluno*, Arvore* left, Arvore* right);

int folhas (Arvore* a); //retorna o número de folhas da árvore
int ocorrencias (Arvore* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore
int altura (Arvore* a); //retorna a altura da árvore

void print (Arvore* arv);

Arvore* free_arvore (Arvore* arv);

#endif