#include "arv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore_binaria
{
    ArvBB* sae;
    ArvBB* sad;
    Aluno* aluno;
};

static int retornaComparacao (char* nomeMaior, char* nomeMenor) {
    return strcmp (nomeMaior, nomeMenor);
}

ArvBB* criaArvoreVazia () {
    return NULL;
}

ArvBB* insereArvore (Aluno* al, ArvBB* arv) {
    if (arv == NULL) { //Árvore vazia
        arv = (ArvBB*) malloc (sizeof (ArvBB));
        arv->sad = arv->sae = NULL;
        arv->aluno = al;
        return arv;
    }
    
    if (retornaComparacao (retornaNome(al), retornaNome (arv->aluno)) == 1) {
        arv->sad = insereArvore (al, arv->sad);
    }
    else
        arv->sae = insereArvore (al, arv->sae);

    return arv;
}

Aluno* retornaAluno (ArvBB* arv) {
    return arv->aluno;
}

ArvBB* buscaArvore (Aluno* al, ArvBB* arv) {
    if (arv == NULL) return NULL;

    if (retornaComparacao (retornaNome(al), retornaNome (arv->aluno)) == 1)
        return buscaArvore (al, arv->sad);
    else if (retornaComparacao (retornaNome(al), retornaNome (arv->aluno)) == -1) 
        return buscaArvore (al, arv->sae);

    return arv;
}

ArvBB* retiraArvore (Aluno* al, ArvBB* arv) {
    if (arv == NULL) return NULL;

    if (retornaComparacao (retornaNome(al), retornaNome (arv->aluno)) == 1)
        arv->sad = retiraArvore (al, arv->sad);
    else if (retornaComparacao (retornaNome(al), retornaNome (arv->aluno)) == -1)
        arv->sae = retiraArvore (al, arv->sae);
    else {
        //-----------------------Retirando o nó/raiz----------------

        //Folha
        if (arv->sad == NULL && arv->sae == NULL) {
            free (arv);
            arv = NULL;
        }

        //Apenas um filho
        if (arv->sae == NULL) {
            ArvBB* arv_aux = arv;
            arv = arv->sad;
            free (arv_aux);
        }
        else if (arv->sad == NULL) {
            ArvBB* arv_aux = arv;
            arv = arv->sae;
            free (arv_aux);
        }
        else {
            //Dois filhos
            ArvBB* to_find = arv->sae;
            while (to_find->sad != NULL) to_find = to_find->sad;
            arv->aluno = to_find->aluno;
            to_find->aluno = al;

            retiraArvore (al, to_find);
        }
    }
    return arv;
}

void imprimeArvore (ArvBB* arv) {
    if (arv == NULL) return;

    imprimeArvore (arv->sae);
    imprimeAluno (arv->aluno);
    imprimeArvore (arv->sad);
}

void liberaArvore (ArvBB* arv) {
    if (arv == NULL) return;

    liberaArvore (arv->sae);
    liberaArvore (arv->sad); 
    free (arv); 
}