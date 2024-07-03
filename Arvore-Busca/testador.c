#include "arv.h"
#include <stdio.h>

int main() {
    //TESTADOR DAS FUNÇÔES DE ÁRVORE
    Aluno* aluno0 = criaAluno("ZZ", "123");
    Aluno* aluno1 = criaAluno("CC", "123");
    Aluno* aluno2 = criaAluno("DD", "456");
    Aluno* aluno3 = criaAluno("AC", "789");
    Aluno* aluno4 = criaAluno("AA", "101");
    Aluno* aluno5 = criaAluno("AB", "100");

    ArvBB* arv = criaArvoreVazia();
    arv = insereArvore(aluno1, arv);
    arv = insereArvore(aluno0, arv);
    arv = insereArvore(aluno2, arv);
    arv = insereArvore(aluno3, arv);
    arv = insereArvore(aluno4, arv);
    arv = insereArvore(aluno5, arv);

    ArvBB* busca = buscaArvore(aluno3, arv);
    imprimeAluno (retornaAluno (busca));
    printf ("-------------------\n");
    imprimeArvore (arv);
    arv = retiraArvore(retornaAluno(busca), arv);
    imprimeArvore(arv);
    liberaArvore (arv);

    liberaAluno (aluno1);
    liberaAluno (aluno2);
    liberaAluno (aluno3);
    liberaAluno (aluno4);
}