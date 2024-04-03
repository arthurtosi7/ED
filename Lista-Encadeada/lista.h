#ifndef _LISTA_H_
#define _LISTA_H_

#include "produto.h"

typedef struct lista tLista;

tLista* CriaLista();

void InsereInicioLista (tLista*, tProduto*);

void InsereFinalLista(tLista*, tProduto*);

void RetiraItemLista (tLista*, char* codigo);

void ImprimeLista (tLista*);

void DeletaLista (tLista*);

#endif