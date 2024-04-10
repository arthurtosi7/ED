#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void ImprimeMenu()
{
    printf ("Digite a opção desejada:\n");
    printf ("\t1- Adicionar produto\n");
    printf ("\t2- Remover produto\n");
    printf ("\t3- Imprimir lista\n");
    printf ("\t4- Sair\n");
}

void ImprimeProdutos (tProduto** produtos, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        ImprimeProduto(produtos[i]);
    }
}

void DeletaProdutos (tProduto** produtos, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        DestroiProduto(produtos[i]);
    }
    free (produtos);
}

int main ()
{
    Lista* lista = CriaLista();
    tProduto** produtos = (tProduto**) malloc (sizeof (tProduto*));
    int qtd_produtos = 0;
    int escolha = -1;
    while (escolha != 4)
    {
        ImprimeMenu();  
        scanf ("%d", &escolha);
        switch (escolha)
        {
            case 1:
                tProduto* produto = LeProduto();
                InsereInicioLista(lista, produto);
                produtos[qtd_produtos] = produto;
                qtd_produtos++;
                break;
            
            case 2:
                printf ("Digite o nome do produto a ser removido: ");
                char nome[100];
                scanf ("%s", nome);
                RetiraItemLista(lista, nome);
                break;

            case 3:
                ImprimeLista(lista);
                break;
            
            case 4: 
                break;

            default:
                printf ("Opção inválida.\n");
                break;
        }
    }
    DeletaProdutos (produtos, qtd_produtos);
    DeletaLista (lista);
    return 0;
}