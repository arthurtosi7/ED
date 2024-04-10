#ifndef _LISTA_H_
#define _LISTA_H_

#include "produto.h"


typedef struct lista Lista;

Lista* CriaLista();

Lista* InsereInicioLista (Lista*, tProduto*);

Lista* RetiraItemLista (Lista*, char* nome);

void ImprimeLista (Lista*);

void DeletaLista (Lista*);

#endif