#ifndef _T_LISTA_H_
#define _T_LISTA_H_

typedef struct lista tLista;

tLista* criaLista();

void InsereInicioLista (tLista* lista, void* animal);

void InsereFinalLista(tLista* lista, void* animal);

void RetiraItemLista (tLista* lista, void* animal);

int ItemEstaNaLista (tLista*, void* animal);

void ImprimeLista (tLista* lista, void imprimeItem (void* item));

void DeletaLista (tLista* lista);

#endif



void InsereListaGato (tLista* lista, Gato*);

void InsereListaCachorro (tLista* lista, Cachorro*);

void RetiraListaGato (tLista* lista, Gato*);

void RetiraListaCachorro (tLista* lista, Cachorro*);