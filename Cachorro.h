#ifndef _T_CACHORRO_H_
#define _T_CACHORRO_H_

typedef struct cachorro Cachorro;

typedef enum{
    MANSO,
    BRAVO
} AGRESSIVIDADE;

Cachorro* inicCachorro(char* nome, AGRESSIVIDADE);

AGRESSIVIDADE retornaAgressividadeCachorro (Cachorro*);

char* retornaNomeCachorro (Cachorro*);

void atribuiNivelAgressividadeCachorro (Cachorro*, AGRESSIVIDADE);

void imprimeCachorro (Cachorro*);

void liberaCachorro (Cachorro*);

#endif