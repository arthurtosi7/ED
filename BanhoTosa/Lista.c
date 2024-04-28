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

tLista* criaLista()
{
    tLista* sentinela = (tLista*) malloc (sizeof(tLista));
    sentinela->prim = NULL;
    sentinela->ult = NULL;
    return sentinela;
}

void InsereInicioLista (tLista* lista, void* animal, int tipo)
{
    Celula* new_cel = (Celula*) malloc (sizeof(Celula));
    new_cel->animal = animal;
    new_cel->tipo = tipo;
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

void RetiraItemLista (tLista* lista, void* animal)
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

int retornaQuantidadeGatoLista (tLista* lista)
{
    Celula* c = lista->prim;
    int count = 0;
    while (c != NULL)
    {
        if (c->tipo == 0) // assumindo que o tipo 2 é Gato
            count++;
        c = c->prox;
    }  
    return count;
}

int retornaQuantidadeCachorroLista (tLista* lista)
{
    Celula* c = lista->prim;
    int count = 0;
    while (c != NULL)
    {
        if (c->tipo == 1) // assumindo que o tipo 1 é Cachorro
            count++;
        c = c->prox;
    }  
    return count;
}


void ImprimeLista (tLista* lista)
{
    Celula* c = lista->prim;
    int i = 1;
    if (c == NULL)
        printf ("Lista vazia.\n");
    while (c != NULL)
    {
        printf ("Animal %d:\n", i);
        if (c->tipo == 1)
            imprimeCachorro ((Cachorro*)c->animal);
        else
            imprimeGato ((Gato*)c->animal);
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
        // if (ant->tipo == 0)
        //     liberaGato ((Gato*)ant->animal);
        // else
        //     liberaCachorro ((Cachorro*)ant->animal);
        free (ant);
    }
    free (lista);
}
