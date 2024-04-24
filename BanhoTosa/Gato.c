#include "Gato.h"

struct gato
{
    AGRESSIVIDADE situacao;
    char* nome;
};

Gato* inicGato(char* nome, AGRESSIVIDADE)
{
    Gato* cat = (Gato*) malloc (sizeof(Gato));
    cat->nome = strdup (nome);
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

void atribuiNivelAgressividadeGato (Gato* cat, AGRESSIVIDADE situacao)
{
    cat->situacao = situacao;
}

