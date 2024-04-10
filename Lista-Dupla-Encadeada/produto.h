#ifndef _PRODUTO_H_
#define _PRODUTO_H_

typedef struct produto tProduto;

tProduto* LeProduto();

char* RetornaNome (tProduto*);

char* RetornaCodigo (tProduto*);

float RetornaValor (tProduto*);

void ImprimeProduto (tProduto*);

void DestroiProduto (tProduto*);

#endif