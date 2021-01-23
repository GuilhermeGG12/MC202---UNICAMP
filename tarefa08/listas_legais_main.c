#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas_legais_funcoes.h"

int main() {
    p_no Treap = NULL;
    int n, k, i, op, val;
    long int j, m;
    long int num;

    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++){
        scanf(" %ld", &num);
        Treap = insere(Treap, num);
    }
    while(k > 0){
        scanf(" %d", &op);
        switch (op){
            case 1:
                scanf(" %ld", &j);
                Treap = insere(Treap, j);
                break;
        
            case 2:
                scanf(" %ld", &m);
                val = recorrencia(Treap, m);
                printf("%d\n", val);
                break;
            case 3:
                val = virar_lista_legal(Treap);
                if(val < 0){
                    val = 0;
                }
                printf("%d\n", val);
                break;
        }
        k--;
    }
    apaga_arvore(Treap);

    return 0;
}


