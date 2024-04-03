#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

struct matriz
{
    int** elem;
    int num_linhas;
    int num_colunas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    if (nlinhas == 0 || ncolunas == 0)
    {
        printf ("Linhas ou Colunas tem que ser diferentes de 0!\n");
        return NULL;
    }
    Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
    mat->elem = (int**) malloc(nlinhas * sizeof(int*));
    for (int i = 0; i < nlinhas; i++)
    {
        mat->elem[i] = (int*) malloc(ncolunas * sizeof(int));
    }
    mat->num_linhas = nlinhas;
    mat->num_colunas = ncolunas;
    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    if (mat == NULL)
    {
        printf ("Matriz não encontrada!\n");
        return;
    }
    mat->elem[linha][coluna] = elem;
    return;
}

int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    if (mat == NULL)
    {
        printf ("Matriz não encontrada!\n");
        return 0;
    }
    return mat->elem[linha][coluna];
}

int recuperaNColunas (Matriz* mat)
{
    if (mat == NULL)
    {
        printf ("Matriz não encontrada!\n");
        return 0;
    }
    return mat->num_colunas;
}

int recuperaNLinhas (Matriz* mat)
{
    if (mat == NULL)
    {
        printf ("Matriz não encontrada!\n");
        return 0;
    }
    return mat->num_linhas;
}

Matriz* transposta (Matriz* mat)
{
    if (mat == NULL)
    {
        printf ("Matriz não encontrada!\n");
        return NULL;
    }
    Matriz* transposta = inicializaMatriz (mat->num_colunas, mat->num_linhas); //INVERTIDO
    for (int i = 0; i < mat->num_linhas; i++)
    {
        for (int j = 0; j < mat->num_colunas; j++)
        {
            transposta->elem[j][i] = mat->elem[i][j];
        }  
    }
    return transposta;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
    if (mat1 == NULL || mat2 == NULL)
    {
        printf ("Matriz não encontrada!\n");
        return NULL;
    }
    if (!(mat1->num_colunas == mat2->num_linhas))
        return NULL;
    Matriz* mult = inicializaMatriz (mat1->num_linhas, mat2->num_colunas);
    for (int i = 0; i < mult->num_linhas; i++)
    {
        for (int j = 0; j < mult->num_colunas; j++)
        {
            int temp = 0;
            for (int k = 0; k < mat1->num_colunas; k++)
            {
                temp += mat1->elem[i][k] * mat2->elem[k][j];
            }
            mult->elem[i][j] = temp;
        }
    }
    return mult;
}

void imprimeMatriz(Matriz* mat)
{
    for (int i = 0; i < mat->num_linhas; i++)
    {
        imprimeLinhas (mat, i);
    } 
}

void imprimeLinhas (Matriz* mat, int indice)
{
    printf ("|");
    for (int j = 0; j < mat->num_colunas; j++)
    {
        printf ("%d ", mat->elem[indice][j]);
    }
    printf ("|\n");
    return;
}

void destroiMatriz (Matriz* mat)
{
    for (int i = 0; i < mat->num_linhas; i++)
    {
        free (mat->elem[i]);
    }
    free(mat->elem);
    free(mat);    
}