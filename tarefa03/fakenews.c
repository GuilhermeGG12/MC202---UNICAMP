#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fakenews.h"


void separa_dados(Termo**termos, int m, int n) {
    double *valores, soma = 0, media = 0, desvio = 0, max, min;
    int i, j;
    valores = malloc(m * sizeof(double));
    
    for(i = 0; i < n; i++){
        scanf("%s", termos[i]->nome);
        for(j = 0; j < m; j++){
            scanf("%lf", &valores[j]);
        }

        for(j = 0; j < m; j++){
            soma += valores[j];
        }
        media = soma/m;
        termos[i]->media = media;
        soma = 0;
        
        for(j = 0; j < m; j++){
            soma += pow(valores[j] - media, 2);
        }
        desvio = sqrt(soma/m);
        soma = 0;
        termos[i]->desvio = desvio;

        max = min = valores[0];
        for(j = 0; j < m; j++){
            if(valores[j] > max)
                max = valores[j];
            else if(valores[j] < min)
                min = valores[j];
        } 

        termos[i]->max = max;
        termos[i]->min = min;
    }
    free(valores);
}

void define_categorias(Categoria **categorias, int n, Termo **termos) {
    int aux_a = 0, aux_b = 0, aux_c = 0, aux_d = 0, aux_e = 0;
    int i;
    
    for(i = 0; i < n; i++){
        if(termos[i]->media >= 60 && termos[i]->desvio > 15){
            strcpy(categorias[0]->componentes[aux_a]->nome, termos[i]->nome);
            categorias[0]->componentes[0]->qtd++;
            aux_a++;
        }
        else if(termos[i]->media >= 60 && termos[i]->desvio <= 15){
            strcpy(categorias[1]->componentes[aux_b]->nome, termos[i]->nome);
            categorias[1]->componentes[0]->qtd++;
            aux_b++;
        }
        else if(termos[i]->media < 60 && termos[i]->max >= 80 && termos[i]->min > 20){
            strcpy(categorias[2]->componentes[aux_c]->nome, termos[i]->nome);
            categorias[2]->componentes[0]->qtd++;
            aux_c++;
        }
        else if(termos[i]->media < 60 && termos[i]->max >= 80 && termos[i]->min <= 20){
            strcpy(categorias[3]->componentes[aux_d]->nome, termos[i]->nome);
            categorias[3]->componentes[0]->qtd++;
            aux_d++;
        }
        else if(termos[i]->media < 60 && termos[i]->max < 80){
            strcpy(categorias[4]->componentes[aux_e]->nome, termos[i]->nome);
            categorias[4]->componentes[0]->qtd++;
            aux_e++;
        }
    }
}

void imprime_categorias(Categoria **categorias) {
    printf("\nRESULTADO:\n");
    printf("Bot (%d): ", categorias[0]->componentes[0]->qtd);
    for(int i = 0; i < categorias[0]->componentes[0]->qtd; i++){
        printf("%s ", categorias[0]->componentes[i]->nome);
    }
    printf("\n");
    printf("Surpreendente (%d): ", categorias[1]->componentes[0]->qtd);
    for(int i = 0; i < categorias[1]->componentes[0]->qtd; i++){
        printf("%s ", categorias[1]->componentes[i]->nome);
    }
    printf("\n");
    printf("Normal (%d): ", categorias[2]->componentes[0]->qtd);
    for(int i = 0; i < categorias[2]->componentes[0]->qtd; i++){
        printf("%s ", categorias[2]->componentes[i]->nome);
    }
    printf("\n");
    printf("Local (%d): ", categorias[3]->componentes[0]->qtd);
    for(int i = 0; i < categorias[3]->componentes[0]->qtd; i++){
        printf("%s ", categorias[3]->componentes[i]->nome);
    }
    printf("\n");
    printf("Irrelevante (%d): ", categorias[4]->componentes[0]->qtd);
    for(int i = 0; i < categorias[4]->componentes[0]->qtd; i++){
        printf("%s ", categorias[4]->componentes[i]->nome);
    }
    printf("\n");
}

void libera_termos(Termo **termos, int n) {
    for(int i = 0; i < n; i++){
        free(termos[i]->nome);
        free(termos[i]);
    }
    
    free(termos);
}


void libera_categorias(Categoria **categorias, int n) {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < n; j++){
            free(categorias[i]->componentes[j]->nome);
            free(categorias[i]->componentes[j]);
        }
    }
    
    for(int i = 0; i < 5; i++){
        free(categorias[i]->componentes);
        free(categorias[i]);
    }
    free(categorias);
}

int main() {
    int m, n;
    int i, j;
    scanf("%d %d", &n, &m);
    Termo **termos = malloc(n * sizeof(Termo*));
    for(i = 0; i < n; i++){
        termos[i] = malloc(sizeof(Termo));
        termos[i]->nome = malloc(26 * sizeof(char));
    }
    Categoria **categorias = malloc(5 * sizeof(Categoria*));
    for(i = 0; i < 5; i++){
        categorias[i] = malloc(sizeof(Categoria*));
    }

    for(i = 0; i < 5; i++){
        categorias[i]->componentes = malloc(n * sizeof(Componente*));
        for(j = 0; j < n; j++){
            categorias[i]->componentes[j] = malloc(sizeof(Componente));
            categorias[i]->componentes[j]->nome = malloc(26 * sizeof(char));
        }
    }



    separa_dados(termos, m, n);

    for(i = 0; i < n; i++){
        printf("%s %.2lf %.2lf %.2lf %.2lf\n", termos[i]->nome, termos[i]->max, termos[i]->min,
                                    termos[i]->media, termos[i]->desvio);
    }

    define_categorias(categorias, n, termos);
    imprime_categorias(categorias);

    libera_categorias(categorias, n);
    libera_termos(termos, n);


    return 0;
}