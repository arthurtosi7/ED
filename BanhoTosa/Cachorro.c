#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

struct cachorro
{
    AGRESSIVIDADE situacao;
    char* nome;
};

Cachorro* inicCachorro(char* nome, AGRESSIVIDADE agressividade)
{
    Cachorro* dog = (Cachorro*) malloc (sizeof(Cachorro));
    dog->nome = strdup (nome);
    dog->situacao = agressividade;
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

void imprimeCachorro (Cachorro* dog)
{
    if (dog->situacao == MANSO)
        printf ("\tNome cachorro: %s. MANSO\n",dog->nome);
    else
        printf ("\tNome cachorro: %s. BRAVO\n",dog->nome);
}

void liberaCachorro (Cachorro* dog)
{
    free (dog->nome);
    free (dog);
}