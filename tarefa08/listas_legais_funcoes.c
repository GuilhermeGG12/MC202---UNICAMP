#include "listas_legais.h"
#include "listas_legais_funcoes.h"

p_no rot_dir(p_no raiz) {

    // função que rotaciona parte da Treap para direita

    p_no x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;
    return x;
}

p_no rot_esq(p_no raiz) {

    // função que rotaciona parte da Treap para esquerda

    p_no x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    return x;
}

void apaga_arvore(p_no raiz) {

    // função que apaga a Treap

    if(raiz == NULL)
        return;
    apaga_arvore(raiz->esq);
    apaga_arvore(raiz->dir);
    free(raiz);
}

int buscar(p_no raiz, long int chave) {

    // função que busca um nó específico na Treap retornando 1 se achar e 0 caso contrário

    if (raiz == NULL || chave == raiz->dado)
        return 1;
    if (chave < raiz->dado)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
    return 0;
}

p_no buscarNo(p_no raiz, long int chave) {

    // função que busca um nó específico na Treap retornando esse nó

    if (raiz == NULL || chave == raiz->dado)
        return raiz;
    if (chave < raiz->dado)
        return buscarNo(raiz->esq, chave);
    else
        return buscarNo(raiz->dir, chave);
}

p_no insere(p_no raiz, long int x) {

    /*
    função que insere um novo nó e um valor x na Treap, caso já exista um nó com o valor
    igual ao de x apenas incrementamos 1 á variavel qtd do nó
    */
    if (raiz == NULL) {
        p_no novo = malloc(sizeof(No));
        if(novo == NULL){
            printf("Erro de Memoria!\n");
            exit(1);
        }
        novo->dado = x;
        novo->esq = novo->dir = NULL;
        novo->r = rand();
        novo->qtd = 1;
        return novo;
    }
    if (raiz->dado > x) {
        raiz->esq = insere(raiz->esq, x);
        if (raiz->r < raiz->esq->r)
            raiz = rot_dir(raiz);
    }
    else if (raiz->dado < x) {
        raiz->dir = insere(raiz->dir, x);
        if (raiz->r < raiz->dir->r)
            raiz = rot_esq(raiz);
    }
    else{
        raiz->qtd += buscar(raiz, x);
    }
    return raiz;
}


int recorrencia(p_no treap, long int num) {
    
    /*
    função que verifica o valor da variável qtd em um nó específico e retorna o valor
    */
    p_no aux;
    if(treap == NULL)
        return 0;
    aux = buscarNo(treap, num);
    if(aux == NULL)
        return 0;
    else{
        return aux->qtd;
    }
}

int virar_lista_legal(p_no treap) {

    // função que retorna quantos números devem ser retirados para termos uma lista legal

    if(treap == NULL)
        return 0;

    if(treap->qtd != treap->dado){
        if(treap->qtd > treap->dado){
            return (treap->qtd - treap->dado) + virar_lista_legal(treap->esq) +
                                                virar_lista_legal(treap->dir);
        }
        else{
            return treap->qtd + virar_lista_legal(treap->esq) +
                                virar_lista_legal(treap->dir);
        }
    }
    return virar_lista_legal(treap->esq) +
           virar_lista_legal(treap->dir);
}