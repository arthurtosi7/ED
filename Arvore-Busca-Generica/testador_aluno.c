#include "search_tree.h"
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

    Tree* root = createNullTree();
    root = insertTree(root, aluno1, comparaAlunos);
    root = insertTree(root, aluno0, comparaAlunos);
    root = insertTree(root, aluno2, comparaAlunos);
    root = insertTree(root, aluno3, comparaAlunos);
    root = insertTree(root, aluno4, comparaAlunos);
    root = insertTree(root, aluno5, comparaAlunos);

    //Tree* busca = buscarootore(aluno3, root);
    //imprimeAluno (retornaAluno (busca));
    printf ("-------------------\n");
    printTree (root, imprimeAluno);
    root = removeTree (root, aluno3, comparaAlunos);
    printTree(root, imprimeAluno);
    freeTree (root);

    liberaAluno (aluno1);
    liberaAluno (aluno2);
    liberaAluno (aluno3);
    liberaAluno (aluno4);
}