#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"

struct arv
{
    Aluno* student_arv;
    Arvore* sae; //sub árvore esquerda
    Arvore* sad; //sub árvore direita
};

Arvore* create_empty () {
    return NULL;
}

Arvore* create_arvore (Aluno* student, Arvore* left, Arvore* right)
{
    Arvore* arv = (Arvore*) malloc (sizeof (Arvore));
    arv->student_arv = student;
    arv->sae = left;
    arv->sad = right;
    return arv;
}

static int arvore_vazia (Arvore* arv) {
    return arv == NULL;
}

static int pertenceAluno (Arvore* arv, Aluno* stud) {
    return (!(strcmp (return_name (stud), return_name(arv->student_arv))));
}

int pertence (Arvore* arv, Aluno* stud) {
    if (arvore_vazia (arv))
        return 0;
    else
        return (pertenceAluno (arv, stud) ||
                pertence (arv->sae, stud) ||
                pertence (arv->sad, stud));
}

static int ehFolha (Arvore* arv) {
    return (arvore_vazia (arv->sae) && arvore_vazia (arv->sad));
}

int ocorrencias (Arvore* arv, char* nome) {
    if (arvore_vazia (arv))
        return 0;
    else
        return (strcmp (nome, return_name(arv->student_arv)) == 0) +
                ocorrencias (arv->sae, nome) + ocorrencias (arv->sad, nome);
}

static int return_greater (int n1, int n2) {
    return (n1 >= n2)? n1:n2;
}

int altura (Arvore* arv)
{
    if (arvore_vazia (arv))
        return -1;
    if (ehFolha (arv))
        return 0;
    else
        return 1 + return_greater (altura (arv->sae), altura (arv->sad));
}

int folhas (Arvore* arv) {
    if (arvore_vazia (arv))
        return 0;
    if (ehFolha (arv))
        return 1;
    else 
        return (folhas (arv->sae) + folhas (arv->sad));
}

void print (Arvore* arv) {
    if (arvore_vazia (arv))
        return;
    if (ehFolha (arv)) {
        print_aluno (arv->student_arv);
        return;
    }
    else
    {
        print_aluno (arv->student_arv);
        print (arv->sae);
        print (arv->sad);
    }
}

Arvore* free_arvore (Arvore* arv) {
    if (!arvore_vazia) {
        free_aluno (arv->student_arv);
        free_arvore (arv->sae);
        free_arvore (arv->sad);
        free (arv);
    }
}