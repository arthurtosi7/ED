#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula
{
    tProduto* produto;
    Celula* prox;
};

struct lista
{
    Celula* prim;
    Celula* ult;
    int qtd;
    float valor;
};


tLista* CriaLista()
{
    tLista* sentinela = (tLista*) malloc (sizeof(tLista));
    sentinela->prim = NULL;
    sentinela->ult = NULL;
    sentinela->qtd = 0;
    sentinela->valor = 0;
    return sentinela;
}

void InsereInicioLista (tLista* lista, tProduto* new_prod)
{
    Celula* new_cel = (Celula*) malloc (sizeof(Celula));
    new_cel->produto = new_prod;
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
    lista->qtd++;
    lista->valor += RetornaValor (new_prod);
    return;
}

void InsereFinalLista(tLista* lista, tProduto* new_prod)
{
    Celula* new_cel = (Celula*) malloc (sizeof(Celula));
    new_cel->produto = new_prod;
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
    lista->qtd++;
    lista->valor += RetornaValor (new_prod);
    return;
}

void RetiraItemLista (tLista* lista, char* codigo)
{
    Celula* c = lista->prim;
    Celula* ant = NULL;
    while (c != NULL && (strcmp(codigo, RetornaCodigo(c->produto)) != 0))
    {
        ant = c;
        c = c->prox;
    }  
    if (c == NULL)
    {
        printf ("Código não encontrado.\n");
        return;
    }
    lista->valor -= RetornaValor(c->produto);
    lista->qtd--;
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
    ant->prox = c->prox;
    free (c);
    return;
}

void ImprimeLista (tLista* lista)
{
    Celula* c = lista->prim;
    int i = 1;
    while (c != NULL)
    {
        printf ("Produto %d:\n", i);
        ImprimeProduto (c->produto);
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

