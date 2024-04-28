#include "Gato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gato
{
    AGRESSIVIDADE situacao;
    char* nome;
};

Gato* inicGato(char* nome, AGRESSIVIDADE agressividade)
{
    Gato* cat = (Gato*) malloc (sizeof(Gato));
    cat->nome = strdup (nome);
    cat->situacao = agressividade;
    return cat;
}

AGRESSIVIDADE retornaAgressividadeGato (Gato* cat)
{
    return cat->situacao;
}

char* retornaNomeGato (Gato* cat)
{
    return cat->nome;
}

void imprimeGato (Gato* cat)
{
    if (cat->situacao == MANSO)
        printf ("\tNome gato: %s. MANSO\n",cat->nome);
    else
        printf ("\tNome gato: %s. BRAVO\n",cat->nome);
}

void atribuiNivelAgressividadeGato (Gato* cat, AGRESSIVIDADE situacao)
{
    cat->situacao = situacao;
}

void liberaGato (Gato* cat)
{
    free (cat->nome);
    free (cat);
}
