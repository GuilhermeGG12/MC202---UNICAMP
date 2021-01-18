#include "corretor.h"
#include "corretor_funcoes.h"

int hash(char *chave) {

    // função que retorna o valor hash da chave

    int i, n = 0;
    for (i = 0; i < strlen(chave); i++)
    n = (256 * n + chave[i]) % MAX;
    return n;
}

p_dic cria() {

    // função que cria um tabela de hashing (dicionário)

    p_dic d = malloc(sizeof(Dicionario));
    d->tabela = malloc(M * sizeof(Item));
    for (int i = 0; i < M; i++)
        d->tabela[i].vazio = 1;
    return d;
}

int busca(p_dic d, char *chave) {
    
    /*
     função que busca uma palavra no dicionário retornando -1 caso não seja encontrada
     e o tamanho da palavra caso contrário
    */

    int pos = hash(chave);
    while (!d->tabela[pos].vazio && strcmp(chave, d->tabela[pos].chave) != 0)
        pos = (pos + 1) % M;
    if (d->tabela[pos].vazio)
        return -1;
    return d->tabela[pos].len;
}

void insere(p_dic d, char *chave, int len) {

    // função que insere uma nova palavra no dicionario

    int pos = hash(chave);
    while (!d->tabela[pos].vazio && strcmp(chave, d->tabela[pos].chave) != 0)
        pos = (pos + 1) % M;
    if (d->tabela[pos].vazio) {
        d->tabela[pos].vazio = 0;
        strcpy(d->tabela[pos].chave, chave);
    }
    d->tabela[pos].len = len;
}

int insere_subtring(p_dic d, char *palavra, char *substring, int index) {

    // função que insere uma letra(substring) em cada posição de uma palavra

    char *nova_palavra = malloc(52 * sizeof(char));

    strncpy(nova_palavra, palavra, index);
    nova_palavra[index] = '\0';
    strcat(nova_palavra, substring);
    strcat(nova_palavra, palavra + index);
    
    if(busca(d, nova_palavra) != -1){
        free(nova_palavra);
        return 1;
    }
    free(nova_palavra);
    return -1;
}

int remove_letra(p_dic d, char *palavra, int index) {

    // função que remove uma letra de cada posição da palavra

    char *nova_palavra = malloc(26 * sizeof(char));
    strncpy(nova_palavra, palavra, index);
    nova_palavra[index] = '\0';
    if(index != strlen(palavra) - 1)
        strcat(nova_palavra, palavra + index + 1);
    if(busca(d, nova_palavra) != -1){
        free(nova_palavra);
        return 1;
    }
    free(nova_palavra);
    return -1;
}

int muda_letra(p_dic d, char *palavra, char *letra, int index) {

    // função que muda uma letra de cada posição da palavra por outra do alfabeto

    char *nova_palavra = malloc(26 * sizeof(char));
    strncpy(nova_palavra, palavra, index);
    nova_palavra[index] = '\0';
    strcat(nova_palavra, letra);
    strcat(nova_palavra, palavra + index + 1);
    if(busca(d, nova_palavra) != -1){
        free(nova_palavra);
        return 1;
    }
    free(nova_palavra);
    return -1;
}

int checa_palavras(p_dic d, char *palavra) {

    /*
    função que realiza a checagem do grau de correção de uma palavra verificando
    cada um dos casos possíveis, retornando seu grau de correção
    */

    int i, j;
    char *alfabeto = "abcdefghijklmnopqrstuvwxyz";
    char letra[2] = "";

    if(busca(d, palavra) != -1){
        return 0;
    }

    else{
    // Caso 1 - Inserir letras
        for(i = 0; i <= strlen(palavra); i++){
            alfabeto = "abcdefghijklmnopqrstuvwxyz";
            for(j = 1; j <= 26; j++){
                strncpy(letra, alfabeto, 1); //talvez mudar variavel letra
                ++alfabeto;
                if(insere_subtring(d, palavra, letra, i) != -1){
                    return 1;
                }
            }
        }
    // Caso 2 - Remover letras    
        for(i = 0; i < strlen(palavra); i++){
            if(remove_letra(d, palavra, i) != -1)
                return 1;
        }

    // Caso 3 - Mudar letra
        for(i = 0; i < strlen(palavra); i++){
            alfabeto = "abcdefghijklmnopqrstuvwxyz";
            for(j = 0; j < 26; j++){
                strncpy(letra, alfabeto, 1);
                ++alfabeto;
                if(muda_letra(d, palavra, letra, i) != -1)
                    return 1;
            }
        }
    }
    return 2;
}