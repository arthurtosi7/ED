#ifndef _T_GATO_H_
#define _T_GATO_H_

typedef struct gato Gato;
#include "Cachorro.h"

Gato* inicGato(char* nome, AGRESSIVIDADE);

AGRESSIVIDADE retornaAgressividadeGato (Gato*);

char* retornaNomeGato (Gato*);

void atribuiNivelAgressividadeGato (Gato*, AGRESSIVIDADE);

void imprimeGato (Gato*);

void liberaGato (Gato*);

#endif