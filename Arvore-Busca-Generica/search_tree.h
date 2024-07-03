#ifndef _TREE_H_
#define _TREE_H_

typedef struct searchTree Tree;

typedef int (*firstIsGreater)(void* elem1, void* elem2); //Must return 1 if element 1 is greater, 0 if equals and -1 if element 2
typedef void (*printElement)(void* elem);

Tree* createNullTree ();

Tree* insertTree (Tree*, void* new_date, firstIsGreater);

Tree* removeTree (Tree*, void* to_remove, firstIsGreater);

void printTree (Tree*, printElement);

void freeTree (Tree*);

#endif