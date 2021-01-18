#ifndef CORRETOR_H
#define CORRETOR_H
#define MAX 101
#define M 1024
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char chave[MAX];
    int len;
    int vazio;
} Item;

typedef struct Dicionario
{
    Item *tabela;
} Dicionario;

typedef Dicionario *p_dic;

#endif