#include "corretor.h"

int hash(char *chave);

p_dic cria();

int busca(p_dic d, char *chave);

void insere(p_dic d, char *chave, int len);

int insere_subtring(p_dic d, char *palavra, char *substring, int index);

int remove_letra(p_dic d, char *palavra, int index);

int muda_letra(p_dic d, char *palavra, char *letra, int index);

int checa_palavras(p_dic d, char *palavra);