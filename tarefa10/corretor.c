#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
#define M 1024

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

int hash(char *chave) {
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++)
    n = (256 * n + chave[i]) % MAX;
    return n;
}

p_dic cria() {
    p_dic d = malloc(sizeof(Dicionario));
    d->tabela = malloc(M * sizeof(Item));
    for (int i = 0; i < M; i++)
        d->tabela[i].vazio = 1;
    return d;
}

int busca(p_dic d, char *chave) {
    int pos = hash(chave);
    while (!d->tabela[pos].vazio && strcmp(chave, d->tabela[pos].chave) != 0)
        pos = (pos + 1) % M;
    if (d->tabela[pos].vazio)
        return -1;
    return d->tabela[pos].len;
}

void insere(p_dic d, char *chave, int len) {
    int pos = hash(chave);
    while (!d->tabela[pos].vazio && strcmp(chave, d->tabela[pos].chave) != 0)
        pos = (pos + 1) % M;
    if (d->tabela[pos].vazio) {
        d->tabela[pos].vazio = 0;
        strcpy(d->tabela[pos].chave, chave);
    }
    d->tabela[pos].len = len;
}

// Casos de correção
// 1 - Retirar letra -> Vale 1
// 2 - trocar letras na palavra -> Vale 2 !! 
// 3 - adicionar letra -> Vale 1
// 4 - trocar por outras letras que não estão na palavra -> Vale 1

int insere_subtring(p_dic d, char *palavra, char *substring, int index) {
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

// int inverte_letras(p) {
//     char *nova_palavra = malloc(26 * sizeof(char));

// }

int checa_palavras(p_dic d, char *palavra) {
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

    // Caso 3 - Muda letra
        for(i = 0; i < strlen(palavra); i++){
            alfabeto = "abcdefghijklmnopqrstuvwxyz";
            for(j = 0; j < 26; j++){
                strncpy(letra, alfabeto, 1);
                ++alfabeto;
                if(muda_letra(d, palavra, letra, i) != -1)
                    return 1;
            }
        }
    // Caso 4 - Inverte Letras
    }
    return 2;
}

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