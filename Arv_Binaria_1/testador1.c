#include "arv.h"
#include <stdio.h>

int main() {
    Arvore* arthur_tosi = create_arvore (create_aluno ("Arthur Tosi"), create_empty(), create_empty ());
    Arvore* ralph_dorn = create_arvore (create_aluno ("Raphael Dornelas"), create_empty(), create_empty ());
    Arvore* sodre = create_arvore (create_aluno ("Pedro Sodré"), ralph_dorn, arthur_tosi);
    Arvore* john_loss = create_arvore (create_aluno ("John Loss"), sodre, create_empty ());

    Arvore* vivi_rang = create_arvore (create_aluno ("Victor Rangel"), create_empty(), create_empty ());
    Arvore* arthur_tosi2 = create_arvore (create_aluno ("Arthur Tosi"), create_empty(), vivi_rang);

    Arvore* corona = create_arvore (create_aluno ("Daniel Corona"), john_loss, arthur_tosi2);

    print (corona);

    printf ("Ocorrências: %d\n", ocorrencias (arthur_tosi, "Arthur Tosi"));
    printf ("Altura: %d\n", altura (corona));
        
    free_arvore (corona);
}