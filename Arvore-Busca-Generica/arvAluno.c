//
// Created by Arthur on 03/07/2024.
//

#include "arvAluno.h"

typedef Tree ArvAluno;

ArvAluno* createNullArvAluno () {return createNullTree ();}

ArvAluno* insertArvAluno (ArvAluno* arv, Aluno* aluno) {
    return (ArvAluno*) insertTree ((Tree*) arv, aluno, comparaAlunos);
}

ArvAluno* removeArvAluno (ArvAluno* arv, Aluno* aluno) {
    return (ArvAluno*) removeTree ((Tree*) arv, aluno, comparaAlunos);
}

void imprimeArvAluno (ArvAluno* arv) {
    printTree ((Tree*) arv, imprimeAluno);
}

void liberaArvAluno (ArvAluno* arv) {
    freeTree ((Tree*) arv);
}

