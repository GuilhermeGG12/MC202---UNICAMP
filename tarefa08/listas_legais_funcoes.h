#include "listas_legais.h"

p_no rot_dir(p_no raiz);

p_no rot_esq(p_no raiz);

void apaga_arvore(p_no raiz);

int buscar(p_no raiz, long int chave);

p_no buscarNo(p_no raiz, long int chave);

p_no insere(p_no raiz, long int x);

int recorrencia(p_no treap, long int num);

int virar_lista_legal(p_no treap);