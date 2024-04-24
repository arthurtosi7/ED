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
        InsereInicioLista (loja->listaBravos, (void*) dog);
    else
        InsereInicioLista (loja->listaMansos, (void*) dog);
}

void cadastraGato(BanhoTosa* loja, Gato* cat)
{
    if (retornaAgressividadeGato (cat) == BRAVO)
        InsereInicioLista (loja->listaBravos, (void*) cat);
    else
        InsereInicioLista (loja->listaMansos, (void*) cat);
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
            InsereInicioLista(loja->listaMansos, (void*)cat);
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
            InsereInicioLista(loja->listaBravos, (void*)cat);
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
            InsereInicioLista(loja->listaMansos, (void*)dog);
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
            InsereInicioLista(loja->listaBravos, (void*)dog);
        }
    }
}

void ImprimeTipoLista(void* animal, int tipo)
{
    if (tipo )
}


void imprimeBanhoTosa(BanhoTosa* loja)
{
    printf ("%s\n", loja->nomeLoja);
    printf ("Lista animais bravos da %s:\n", loja->nomeLoja);
    ImprimeLista (loja->listaBravos, ImprimeTipoLista ());
    printf ("Lista animais mansos da %s:\n", loja->nomeLoja);
    ImprimeLista (loja->listaMansos);
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja);


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja);