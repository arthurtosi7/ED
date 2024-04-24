#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct celula Celula;

struct celula
{
    void* animal;
    int tipo;
    Celula* prox;
};

struct lista
{
    Celula* prim;
    Celula* ult;
};

tLista* CriaLista()
{
    tLista* sentinela = (tLista*) malloc (sizeof(tLista));
    sentinela->prim = NULL;
    sentinela->ult = NULL;
    return sentinela;
}

void InsereInicioLista (tLista* lista, void* animal)
{
    Celula* new_cel = (Celula*) malloc (sizeof(Celula));
    new_cel->animal = animal;
    if (lista->prim == NULL)
    {
        lista->prim = new_cel;
        lista->ult = new_cel;
    }
    else
    {
        new_cel->prox = lista->prim;
        lista->prim = new_cel;
    }
    return;
}

void InsereFinalLista(tLista* lista, void* animal)
{
    Celula* new_cel = (Celula*) malloc (sizeof(Celula));
    new_cel->animal = animal;
    if (lista->prim == NULL)
    {
        lista->prim = lista->ult = new_cel;
    }
    else
    {
        lista->ult->prox = new_cel;
        new_cel->prox = NULL;
        lista->ult = new_cel;
    }
    return;
}

void* RetiraItemLista (tLista* lista, void* animal)
{
    Celula* c = lista->prim;
    Celula* ant = NULL;
    while (c != NULL && (c->animal != animal))
    {
        ant = c;
        c = c->prox;
    }  
    if (c == NULL)
    {
        printf ("Animal não encontrado.\n");
        return;
    }
    if (c == lista->ult)
    {
        lista->ult = ant;
        ant->prox = NULL;
        free (c);
        return;
    }
    if (c == lista->prim)
    {
        lista->prim = c->prox;
        free (c);
        return;
    }
}

int ItemEstaNaLista (tLista* lista, void* animal)
{
    Celula* c = lista->prim;
    Celula* ant = NULL;
    while (c != NULL && (c->animal != animal))
    {
        ant = c;
        c = c->prox;
    }  
    if (c == NULL)
    {
        printf ("Animal não encontrado.\n");
        return 0;
    }
    return 1;
}

void ImprimeLista (tLista* lista)
{
    Celula* c = lista->prim;
    int i = 1;
    while (c != NULL)
    {
        printf ("Animal %d:\n", i);
        
        c = c->prox;
        i++;
    }  
}

void DeletaLista (tLista* lista)
{
    Celula* c = lista->prim;
    Celula* ant = NULL;
    while (c != NULL)
    {
        ant = c;
        c = c->prox;
        free (ant);
    }
    free (lista);
}
