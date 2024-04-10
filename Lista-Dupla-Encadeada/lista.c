#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef Lista Celula;

struct lista
{
    tProduto* produto;
    Celula* ant;
    Celula* prox;
};

Lista* CriaLista()
{
    Lista* lista = (Lista*) malloc (sizeof (Lista));
    lista->ant = NULL;
    lista->produto = NULL;
    lista->prox = NULL;
    return lista;
}

Celula* BuscaCelula (char* nome, Lista* lista)
{
    for (Celula* p = lista; p != NULL; p = p->prox)
    {
        if (strcmp (RetornaNome(p->produto), nome) == 0)
        {
            return p;
        }
    }
    return NULL;
}

Lista* InsereInicioLista (Lista* lista, tProduto* new_prod)
{
    Celula* new_cel = (Celula*) malloc (sizeof(Celula));
    new_cel->produto = new_prod;
    new_cel->prox = lista;
    new_cel->ant = NULL;
    if (lista != NULL)
        lista->ant = new_cel;
    return new_cel;
}

Lista* RetiraItemLista (Lista* lista, char* nome)
{
    Celula* c = (Celula*) malloc (sizeof (Celula));
    c = BuscaCelula (nome, lista);
    if (c == NULL)
        return lista;

    if (c->ant != NULL)
        c->ant->prox = c->prox;
    else
    {
        lista = c->prox;
        lista->ant = NULL;
    }

    if (c->prox != NULL)
        c->prox->ant = c->ant;
    
    free(c);
    return lista;
}

void ImprimeLista (Lista* lista)
{
    int i = 1;
    for (Celula* p = lista; p != NULL; p = p->prox)
    {
        printf ("Produto %d:\n", i);
        ImprimeProduto (p->produto);
        i++;
    }  
}

void DeletaLista (Lista* lista)
{
    for (Celula* p = lista; p != NULL; p = p->prox)
    {
        lista = lista->prox;
        free (lista->ant);
    }
}

