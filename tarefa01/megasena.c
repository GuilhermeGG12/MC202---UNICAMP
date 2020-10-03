#include <stdio.h>
#define COLUNAS 60
#define MAX_APOSTAS 15
#define MAX_PESSOAS 1000

void le_matriz(int apostas[][COLUNAS], int m){
    int i = 0, j = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < COLUNAS; j++){
            scanf("%d", &apostas[i][j]);
            if(apostas[i][j] == 1){
                apostas[i][j] = j + 1;
            }
        }
    }
}

void separa_apostas(int apostas[][COLUNAS], int corretos[MAX_PESSOAS], int m, int sorteados[6]){
    int i = 0, j = 0, k = 0;
    int l = 0;
    int certos = 0;
    for (i = 0; i < m; i++){
        certos = 0;
        for (j = 0; j < 6; j++){
            for (k = 0; k < 60; k++){
                if(sorteados[j] == apostas[i][k]){
                    certos += 1;
                    corretos[l] = certos;
                }
            }
        }
        l++;
    }
}

void define_premios(int corretos[MAX_PESSOAS], double premios[MAX_PESSOAS], int m, double n){
    int i = 0, j = 0;
    int aux = 0;
    for (i = 0; i < m; i++){
        aux = 0;
        if(corretos[i] >= 0 && corretos[i] < 4){
            printf("0.00\n");
        }
        else if(corretos[i] == 6){
            for(j = 0; j < m; j++){
                if(corretos[i] == corretos[j]){
                    aux++;
                }
            }
            printf("%.2lf\n", (n * (62.0/100))/aux);
        }
        else if(corretos[i] == 5 || corretos[i] == 4){
            for(j = 0; j < m; j++){
                if(corretos[i] == corretos[j]){
                    aux++;
                }
            }
            printf("%.2lf\n", (n * (19.0/100))/aux);
        }
    }
}

int main(){
    int m;
    int i = 0;
    double n;
    int sorteados[5], corretos[MAX_PESSOAS];
    double premios[MAX_PESSOAS];
    scanf("%d %lf", &m, &n);
    int apostas[MAX_PESSOAS][COLUNAS];
    le_matriz(apostas, m);
    for(i = 0; i < 6; i++){
        scanf("%d", &sorteados[i]);
    }
    separa_apostas(apostas, corretos, m, sorteados);
    define_premios(corretos, premios, m, n);
    return 0;
}

