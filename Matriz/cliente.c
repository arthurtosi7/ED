#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void ImprimeMenu()
{
    printf ("Escolha a opção:\n");
    printf ("\t1) Adicionar matriz\n");
    printf ("\t2) Multiplicar matrizes\n");
    printf ("\t3) Matriz Transposta\n");
    printf ("\t4) Eliminar Matriz\n");
    printf ("\t5) Imprimir Matriz\n");
    printf ("\t6) Terminar Programa\n");
}

void LeMatriz (Matriz* mat, int nLinhas, int nColunas)
{ 
    printf ("Digite todos os %d elementos: ", nLinhas*nColunas);
    for (int i = 0; i < nLinhas; i++)
    {
        for (int j = 0; j < nColunas; j++)
        {
            int elem;
            scanf ("%d", &elem);
            modificaElemento(mat, i, j, elem);
        }
    } 
}

int main()
{
    int opcao = 0;
    int quant_matriz = 0;
    Matriz** index = (Matriz**) malloc (sizeof(Matriz*));
    while (opcao != 6)
    {
        ImprimeMenu();
        scanf ("%d", &opcao);
        switch (opcao)
        {
        case 1:
            index = (Matriz**) realloc (index, sizeof (Matriz*) * (quant_matriz+1));
            printf ("Digite a quantidade de linhas: ");
            int nLinhas;
            scanf ("%d", &nLinhas);
            printf ("Digite a quantidade de colunas: ");
            int nColunas;
            scanf ("%d", &nColunas);
            index[quant_matriz] = inicializaMatriz(nLinhas, nColunas);   
            LeMatriz (index[quant_matriz], nLinhas, nColunas);
            quant_matriz++;
            break;

        case 2:
            printf ("Escolha quais matrizes deseja multiplicar: ");
            int escolha1, escolha2;
            scanf ("%d %d", &escolha1, &escolha2);
            Matriz* result = multiplicacao (index[escolha1-1], index[escolha2-1]);
            printf ("Matriz resultante: \n");
            imprimeMatriz (result);
            printf ("Deseja adicionar a matriz resultante? (1 - Sim, 0 - Não): ");
            int add;
            scanf ("%d", &add);
            if (add)
            {
                index = (Matriz**) realloc (index, sizeof (Matriz*) * (quant_matriz+1));
                index[quant_matriz] = result;
                quant_matriz++;
            }
            printf ("Adicionado!\n");
            break;
        
        case 3:
            printf ("Escolha qual matriz deseja transpor: ");
            int escolha_mult;
            scanf ("%d", &escolha_mult);
            Matriz* transp = transposta (index[escolha_mult - 1]);
            printf ("Matriz resultante: \n");
            imprimeMatriz (transp);
            printf ("Deseja adicionar a matriz resultante? (1 - Sim, 0 - Não): ");
            int add_transp;
            scanf ("%d", &add_transp);
            if (add_transp)
            {
                index = (Matriz**) realloc (index, sizeof (Matriz*) * (quant_matriz+1));
                index[quant_matriz] = transp;
                quant_matriz++;
            }
            printf ("Adicionado!\n");
            break;

        case 4:
            printf ("Escolha qual matriz deseja eliminar: ");
            int escolha_free;
            scanf ("%d", &escolha_free);
            destroiMatriz (index[escolha_free]);
            quant_matriz--;
            break;

        case 5:
            int escolha_print;
            printf ("Digite qual matriz deseja imprimir: ");
            scanf ("%d", &escolha_print);
            imprimeMatriz (index[escolha_print-1]);
            break;

        default:
            break;
        }
    }
    
}