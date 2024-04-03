#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    char* nome;
    float preco;
    char* codigo;
};

tProduto* CriaProduto (char* nome, char* codigo, float valor)
{
    tProduto* produto = (tProduto*) malloc (sizeof (tProduto));
    produto->nome = strdup (nome);
    produto->codigo = strdup (codigo);
    produto->preco = valor;
    return produto;
}

tProduto* LeProduto ()
{
    char nome[100], codigo[100];
    float valor;
    printf("Digite o nome do produto: ");
    scanf("%s", nome);
    printf("Digite o código do produto: ");
    scanf("%s", codigo);
    printf("Digite o valor do produto: ");
    scanf("%f", &valor);
    return CriaProduto(nome, codigo, valor);
}

char* RetornaNome (tProduto* prod)
{
    return prod->nome;
}

char* RetornaCodigo (tProduto* prod)
{
    return prod->codigo;
}

float RetornaValor (tProduto* prod)
{
    return prod->preco;
}

void ImprimeProduto (tProduto* prod)
{
    printf("\tNome: %s\n", prod->nome);
    printf("\tCódigo: %s\n", prod->codigo);
    printf("\tValor: %.2f\n", prod->preco);
}

void DestroiProduto (tProduto* prod)
{
    free (prod->nome);
    free (prod->codigo);
    free (prod);
}
