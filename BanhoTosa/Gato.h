#ifndef _T_GATO_H_
#define _T_GATO_H_

typedef struct gato Gato;

typedef enum{
    MANSO,
    BRAVO
} AGRESSIVIDADE;

Gato* inicGato(char* nome, AGRESSIVIDADE);

AGRESSIVIDADE retornaAgressividadeGato (Gato*);

char* retornaNomeGato (Gato*);

void atribuiNivelAgressividadeGato (Gato*, AGRESSIVIDADE);

void liberaGato (Gato*);

#endif