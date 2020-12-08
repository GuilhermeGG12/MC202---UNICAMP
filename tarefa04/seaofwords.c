#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

char ** cria_matriz(int l, int c) {
    int i, j;
    char **matriz;
    matriz = malloc(l * sizeof(char*));
    for(i = 0; i < l; i++){
        matriz[i] = malloc(c * sizeof(char));
    }
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }
    return matriz;
}


int checa_letras(char **matriz, char palavra[MAX], int aux, int i, int j, int l, int c) {
    int eh_valida;
    if(i < 0 || i >= l || j < 0 || j >= c){
        return 0;
    }
    else if(matriz[i][j] != palavra[aux]){
        return 0;
    }
    else if(aux == strlen(palavra) - 1){
        return 1;
    }
    matriz[i][j] = '.';

    eh_valida = checa_letras(matriz, palavra, aux + 1, i, j + 1, l, c) ||
                            checa_letras(matriz, palavra, aux + 1, i + 1, j, l, c) ||
                            checa_letras(matriz, palavra, aux + 1, i - 1, j, l, c) ||
                            checa_letras(matriz, palavra, aux + 1, i, j - 1, l, c);
    
    matriz[i][j] = palavra[aux];
    return eh_valida;
}

int letra_valida(char **matriz, char palavra[MAX], int l, int c) {

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(checa_letras(matriz, palavra, 0, i, j, l, c)){
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m, q;
    int i;
    char palavra[MAX];
    char **matriz;
    scanf("%d %d %d", &n, &m, &q);
    matriz = cria_matriz(n, m);
    for(i = 0; i < q; i++){
        scanf("%s", palavra);
        if(letra_valida(matriz, palavra, n, m)){
            printf("sim\n");
        }
        else{
            printf("nao\n");
        }
    }

    for(i = 0; i < n; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}