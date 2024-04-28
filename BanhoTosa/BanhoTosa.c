#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "BanhoTosa.h"

struct banhotosa
{
    char* nomeLoja;
    tLista* listaBravos;
    tLista* listaMansos;
};

BanhoTosa* inicBanhoTosa(char* nome)
{
    BanhoTosa* loja = (BanhoTosa*) malloc (sizeof (BanhoTosa));
    loja->listaMansos = criaLista();
    loja->listaBravos = criaLista();
    loja->nomeLoja = strdup(nome);
    return loja;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog)
{
    if (retornaAgressividadeCachorro (dog) == BRAVO)
        InsereInicioLista (loja->listaBravos, (void*) dog, 1);
    else
        InsereInicioLista (loja->listaMansos, (void*) dog, 1);
}

void cadastraGato(BanhoTosa* loja, Gato* cat)
{
    if (retornaAgressividadeGato (cat) == BRAVO)
        InsereInicioLista (loja->listaBravos, (void*) cat, 0);
    else
        InsereInicioLista (loja->listaMansos, (void*) cat, 0);
}

void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat)
{
    if (retornaAgressividadeGato (cat) == MANSO)
    {
        if (ItemEstaNaLista(loja->listaMansos, (void*)cat))
            return;
        else
        {
            if (ItemEstaNaLista(loja->listaBravos, (void*)cat))
                RetiraItemLista (loja->listaBravos, (void*)cat);
            InsereInicioLista(loja->listaMansos, (void*)cat, 0);
        }
    }
    else
    {
        if (ItemEstaNaLista(loja->listaBravos, (void*)cat))
            return;
        else
        {
            if (ItemEstaNaLista(loja->listaMansos, (void*)cat))
                RetiraItemLista (loja->listaMansos, (void*)cat);
            InsereInicioLista(loja->listaBravos, (void*)cat, 0);
        }
    }
}


void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog)
{
    if (retornaAgressividadeCachorro (dog) == MANSO)
    {
        if (ItemEstaNaLista(loja->listaMansos, (void*)dog))
            return;
        else
        {
            if (ItemEstaNaLista(loja->listaBravos, (void*)dog))
                RetiraItemLista (loja->listaBravos, (void*)dog);
            InsereInicioLista(loja->listaMansos, (void*)dog, 1);
        }
    }
    else
    {
        if (ItemEstaNaLista(loja->listaBravos, (void*)dog))
            return;
        else
        {
            if (ItemEstaNaLista(loja->listaMansos, (void*)dog))
                RetiraItemLista (loja->listaMansos, (void*)dog);
            InsereInicioLista(loja->listaBravos, (void*)dog, 1);
        }
    }
}


void imprimeBanhoTosa(BanhoTosa* loja)
{
    printf ("%s\n", loja->nomeLoja);
    printf ("\nLista animais bravos da %s:\n\n", loja->nomeLoja);
    ImprimeLista (loja->listaBravos);
    printf ("\nLista animais mansos da %s:\n\n", loja->nomeLoja);
    ImprimeLista (loja->listaMansos);
    printf ("Fim impressora,\n");
}


float calculaReceita(BanhoTosa* loja)
{
    float receita;
    receita = 35.0*(retornaQuantidadeGatoLista(loja->listaBravos)) + 45.0*retornaQuantidadeCachorroLista(loja->listaBravos);
    receita += 30.0*(retornaQuantidadeGatoLista(loja->listaMansos)) + 40.0*retornaQuantidadeCachorroLista(loja->listaMansos);
    return receita;
}

void liberaBanhoTosa(BanhoTosa* loja)
{
    free (loja->nomeLoja);
    DeletaLista (loja->listaBravos);
    DeletaLista (loja->listaMansos);
    free (loja);
}