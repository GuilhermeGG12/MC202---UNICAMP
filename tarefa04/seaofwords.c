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
    /*
    Função que checa se os elementos da matriz correspondem a alguma das letras da palavra
    procurada
    */
    int eh_valida;
    if(i < 0 || i >= l || j < 0 || j >= c){ // Se o tamanho da matriz foi excedido retornamos 0
        return 0;
    }
    else if(matriz[i][j] != palavra[aux]){ // Caso as letras não sejam iguais retornamos 0
        return 0;
    }
    else if(aux == strlen(palavra) - 1){ // Se o índice auxiliar for igual ao ultimo índice da palavra retornamos 0
        return 1;
    }
    matriz[i][j] = '.'; // Marcamos o elementos atual

    eh_valida = checa_letras(matriz, palavra, aux + 1, i, j + 1, l, c) ||
                            checa_letras(matriz, palavra, aux + 1, i + 1, j, l, c) ||
                            checa_letras(matriz, palavra, aux + 1, i - 1, j, l, c) ||
                            checa_letras(matriz, palavra, aux + 1, i, j - 1, l, c);
    // Chamamos recursivamente a função para as possíveis novas posições
    
    matriz[i][j] = palavra[aux]; // Desmarcamos o elemento estudado atualmente
    return eh_valida;
}

int letra_valida(char **matriz, char palavra[MAX], int l, int c) {
    
    // Função que da início a busca recursiva começando pelo primeiro elemento da matriz
    
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
        if(letra_valida(matriz, palavra, n, m)){ // Printa "sim" se a função retornar 1, e "nao" se retornar 0
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