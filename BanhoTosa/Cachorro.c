#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

struct cachorro
{
    AGRESSIVIDADE situacao;
    char* nome;
};

Cachorro* inicCachorro(char* nome, AGRESSIVIDADE)
{
    Cachorro* dog = (Cachorro*) malloc (sizeof(Cachorro));
    dog->nome = strdup (nome);
    return dog;
}

AGRESSIVIDADE retornaAgressividadeCachorro (Cachorro* dog)
{
    return dog->situacao; 
}

char* retornaNomeCachorro (Cachorro* dog)
{
    return dog->nome;
}

void atribuiNivelAgressividadeCachorro (Cachorro* dog, AGRESSIVIDADE situacao)
{
    dog->situacao = situacao;
}