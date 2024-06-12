#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno
{
    char* name;
};

Aluno* create_aluno (char* name) {
    Aluno* student = (Aluno*) malloc (sizeof (Aluno));
    student->name = strdup (name);
    return student;
}

char* return_name (Aluno* stud) {
    return stud->name;
}

void print_aluno (Aluno* student) {
    printf ("%s\n", student->name);
}

void free_aluno (Aluno* stud) {
    free (stud->name);
    free (stud);
}
