#ifndef LISTAS_LEGAIS_H
#define LISTAS_LEGAIS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No
{
    long int dado;
    int r, qtd;
    struct No *esq, *dir;
} No;

typedef No *p_no;

#endif