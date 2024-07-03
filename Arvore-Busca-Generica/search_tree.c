#include "search_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct searchTree
{
    void* date;
    Tree* left;
    Tree* right;
};

Tree* createNullTree () {return NULL;}

int treeIsEmpty (Tree* tree) {return (tree == NULL) ? 1 : 0;}

Tree* insertTree (Tree* tree, void* new_date, firstIsGreater isGreater) 
{
    if (treeIsEmpty (tree)) {
        Tree* tree = (Tree*) malloc (sizeof (Tree));
        tree = new_date;
        tree->right = NULL;
        tree->left = NULL;
        return tree;
    }

    if (isGreater (tree->date, new_date))
        tree->right = insertTree (tree->right, new_date, isGreater);
    else
        tree->left = insertTree (tree->left, new_date, isGreater);

    return tree;
}

Tree* removeTree (Tree* tree, void* to_remove, firstIsGreater isGreater) 
{
    if (treeIsEmpty(tree)) return NULL;

    if (isGreater (tree->date, to_remove) == 1)
        tree->right = removeTree (tree->right, to_remove, isGreater);
    else if (isGreater (tree->date, to_remove) == -1)
        tree->left = removeTree (tree->left, to_remove, isGreater);
    else {
        //Leaf
        if (treeIsEmpty (tree->right) && treeIsEmpty (tree->left)) {
            free (tree);
            tree = NULL;
        }

        //only one child
        if (treeIsEmpty (tree->right)) {
            Tree* aux = tree;
            tree = tree->left;
            free (aux);
        }
        else if (treeIsEmpty (tree->left)) {
            Tree* aux = tree;
            tree = tree->right;
            free (aux);
        }
        else {
            //Two children
            Tree* to_find = tree->left;
            while (!treeIsEmpty (to_find->right)) to_find = to_find->right;
            tree->date = to_find->date;
            to_find->date = to_remove;

            removeTree (to_find, to_remove, isGreater);
        }
    }
    return tree;
}

void printTree (Tree* tree, printElement print)
{
    if (treeIsEmpty (tree)) return;

    printTree (tree->left, print);
    print (tree->date);
    printTree (tree->right, print);
}

void freeTree (Tree* tree)
{
    if (treeIsEmpty (tree)) return;

    freeTree (tree->left);
    free (tree);
    freeTree (tree->right);
}