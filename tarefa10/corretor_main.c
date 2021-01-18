#include <stdio.h>
#include "corretor_funcoes.h"

int main() {
    int n, q;
    int i, len, grau_correcao;
    char palavra[26], correcao[26];
    p_dic dict = cria();
    scanf("%d %d", &n, &q);
    for(i = 0; i < n; i++){
        scanf(" %s", palavra);
        len = strlen(palavra);
        insere(dict, palavra, len);
    }
    while(q > 0){
        scanf("%s", correcao);
        grau_correcao = checa_palavras(dict, correcao);
        if(grau_correcao == 0)
            printf("verde\n");
        else if(grau_correcao == 1)
            printf("amarelo\n");
        else
            printf("vermelho\n");
        
        q--;    
    }
    free(dict->tabela);
    free(dict);

    return 0;
}