#include "arvAluno.h"
#include "aluno.h"
#include <stdio.h>

int main() {
    //TESTADOR DAS FUNÇÔES DE ÁRVORE
    Aluno* aluno0 = criaAluno("ZZ", "123");
    Aluno* aluno1 = criaAluno("CC", "123");
    Aluno* aluno2 = criaAluno("DD", "456");
    Aluno* aluno3 = criaAluno("AC", "789");
    Aluno* aluno4 = criaAluno("AA", "101");
    Aluno* aluno5 = criaAluno("AB", "100");

    ArvAluno* root = createNullArvAluno();
    root = insertArvAluno(root, aluno0);
    root = insertArvAluno(root, aluno1);
    root = insertArvAluno(root, aluno2);
    root = insertArvAluno(root, aluno3);
    root = insertArvAluno(root, aluno4);
    root = insertArvAluno(root, aluno5);
    imprimeArvAluno(root);

    //Tree* busca = buscarootore(aluno3, root);
    //imprimeAluno (retornaAluno (busca));
    printf ("-------------------\n");
    imprimeArvAluno(root);
    printf ("-------------------\n");
    root = removeArvAluno(root, aluno0);
    imprimeArvAluno(root);
    liberaArvAluno(root);

    liberaAluno (aluno1);
    liberaAluno (aluno2);
    liberaAluno (aluno3);
    liberaAluno (aluno4);
}