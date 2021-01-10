#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

p_no criar_lista() {
    return NULL;
}

p_no le_lista(p_no lista) {
    char algarismo;
    int i;
    for(i = 0; i < 26; i++){ //Ajeitar leitura dos numeros transformar em string é bom!
        scanf("%c", &algarismo);
        if(algarismo == ' ')
            break;
        else{
            lista = adicionar_algarismo(lista, (algarismo - '0'));
        }
    }
    return lista;
}

p_no adicionar_algarismo(p_no num, int algarismo) {
    p_no novo;
    novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro de memória!");
        exit(1);
    }
    novo->algarismo = algarismo;
    novo->prox = num; 
    return novo;
}

p_no inverter_lista(p_no lista) {
    p_no atual, ant, invertida = NULL;
    atual = lista;
    while(atual != NULL){
        ant = atual;
        atual = ant->prox;
        ant->prox = invertida;
        invertida = ant;
    }
    return invertida;
}

void imprime_lista(p_no lista) {
    if(lista != NULL && lista->algarismo == '\0'){
        while(lista->prox != NULL && lista->algarismo == '\0'){
            lista = lista->prox;
        }
    }

    if(lista == NULL){
        printf("0\n");
    }
    else{
        p_no atual;
        for(atual = lista; atual != NULL; atual = atual->prox)
            printf("%d", atual->algarismo);
        printf("\n");
    }
}

void destruir_lista(p_no lista) {
    if(lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}

int verifica_tamanho(p_no numero) {
    int tam = 0;
    while(numero != NULL){
        numero = numero->prox;
        tam++;
    }
    return tam;
}

p_no cria_lista_vazia(int tam) {
    p_no novo = NULL;
    while(tam--)
        novo = adicionar_algarismo(novo, 0);
    return novo;
}

p_no adiciona_zeros(p_no numero, int dif) {
    p_no novo = criar_lista();
    p_no aux = NULL;
    novo = adicionar_algarismo(novo, 0);
    dif--;
    p_no temp = novo;
    while(dif--){
        temp->prox = adicionar_algarismo(temp->prox, 0);
        temp = temp->prox;
    }
    if(numero->prox != NULL){
        aux = numero->prox;
    }
    else{
        aux = numero;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return numero;
}

p_no somar_listas(p_no primeiro, p_no segundo) {
    p_no res = NULL;
    p_no aux, ant = NULL;
    int soma = 0, carry = 0;

    while(primeiro != NULL || segundo != NULL){
        soma = 0;
        soma += carry;

        if(primeiro){
            soma += primeiro->algarismo;
        }
        else{
            soma += 0;
        }
        if(segundo){
            soma += segundo->algarismo;
        }
        else{
            soma += 0;
        }

        if(soma >= 10){
            carry = soma / 10;
        }else{
            carry = 0;
        }
        soma = soma % 10;
        
        aux = criar_lista();

        aux = adicionar_algarismo(aux, soma);

        if(res == NULL){
            res = aux;
        }else{
            ant->prox = aux;
        }

        ant = aux;

        if(primeiro)
            primeiro = primeiro->prox;
        if(segundo)
            segundo = segundo->prox;
    }
    if(carry > 0) {
        aux->prox = adicionar_algarismo(aux->prox, carry);
    }
    return res;
}

p_no subtrai_listas(p_no primeiro, p_no segundo) { //Finalizar essa e func que tira zero na esquerda
    p_no res = NULL;
    p_no aux, ant = NULL;
    int subt, carry = 0;    
    while(primeiro != NULL || segundo != NULL){
        subt = 0;
        
        primeiro->algarismo += carry;

        subt += primeiro->algarismo;

        carry = 0;
        
        if(segundo->algarismo > primeiro->algarismo){
            subt += 10 - segundo->algarismo;
            carry = -1;
        }
        else{
            subt -= segundo->algarismo;
            carry = 0;
        }

        aux = criar_lista();

        aux = adicionar_algarismo(aux, subt);

        if(res == NULL){
            res = aux;
        }
        else{
            ant->prox = aux;
        }
        ant = aux;
        if(primeiro)
            primeiro = primeiro->prox;
        if(segundo)
            segundo = segundo->prox;
    }
    return res;
}

p_no arranja_listas(p_no primeiro, p_no segundo) {
    int len1 = verifica_tamanho(primeiro);
    int len2 = verifica_tamanho(segundo);
    p_no maior = NULL;
    p_no menor = NULL;

    p_no aux1 = primeiro;
    p_no aux2 = segundo;


    if(len1 != len2) {
        if(len1 > len2){
            maior = primeiro;
            menor = segundo;
            menor = adiciona_zeros(menor, (len1 - len2));
        }
        else{
            maior = segundo;
            menor = primeiro;
            menor = adiciona_zeros(menor, (len2 - len1));
        }
    }
    else{
        while(primeiro && segundo){
            if(primeiro->algarismo != segundo->algarismo){
                if(primeiro->algarismo > segundo->algarismo){
                    maior = aux1;
                    menor = aux2;
                    
                }
                else{
                    maior = aux2;
                    menor = aux1;
                }
            }
            primeiro = primeiro->prox;
            segundo = segundo->prox;
        }
    }
    return subtrai_listas(maior, menor);
}

p_no multiplica_listas(p_no primeiro, p_no segundo) {
    
    int len1 = verifica_tamanho(primeiro);
    int len2 = verifica_tamanho(segundo);

    p_no res = cria_lista_vazia(len1 + len2 + 1);
    p_no seg_parcial = segundo;
    p_no res_parcial1 = res, res_parcial2 = NULL, prim_parcial = NULL;  

    while (seg_parcial){  
        int carry = 0;  
    
        res_parcial2 = res_parcial1;  
  
        prim_parcial = primeiro;  
  
        while(prim_parcial){  
  
            int mul = prim_parcial->algarismo * seg_parcial->algarismo  
                    + carry;  
  
            res_parcial2->algarismo += mul % 10;  
  
            carry = mul / 10 + res_parcial2->algarismo / 10;  
            res_parcial2->algarismo = res_parcial2->algarismo % 10;  
  
            prim_parcial = prim_parcial->prox;  
            res_parcial2 = res_parcial2->prox;  
        }  
  
        if (carry > 0) {  
            res_parcial2->algarismo += carry;  
        }  
  
        res_parcial1 =res_parcial1->prox;  
        seg_parcial = seg_parcial->prox;  
    }  

    return res;  
}

int main() {
    p_no primeiro, segundo, resultado;
    primeiro = criar_lista();
    segundo = criar_lista();
    char op, algarismo;
    int i, n;
    
    scanf("%d ", &n);
    while(n > 0){
        scanf(" %c ", &op);
        for(i = 0; i < 26; i++){ //Ajeitar leitura dos numeros transformar em string é bom!
            scanf("%c", &algarismo);
            if(algarismo == ' ')
                break;
            else{
                primeiro = adicionar_algarismo(primeiro, (algarismo - '0'));
            }
        }
        for(i = 0; i < 26; i++){
            scanf("%c", &algarismo);
            if(algarismo == '\n' || algarismo == ' ')
                break;
            else{
                segundo = adicionar_algarismo(segundo, (algarismo - '0'));
            }
        }
        switch(op){
            case '+':
                resultado = somar_listas(primeiro, segundo); 
                resultado = inverter_lista(resultado);
                imprime_lista(resultado);
                destruir_lista(primeiro);
                destruir_lista(segundo);
                destruir_lista(resultado);
                primeiro = criar_lista();
                segundo = criar_lista();
                break;

            case '-':
                resultado = arranja_listas(primeiro, segundo); 
                resultado = inverter_lista(resultado);
                imprime_lista(resultado);
                destruir_lista(primeiro);
                destruir_lista(segundo);
                destruir_lista(resultado);
                primeiro = criar_lista();
                segundo = criar_lista();
                break;
            case '*':
                resultado = multiplica_listas(primeiro, segundo); 
                resultado = inverter_lista(resultado);
                imprime_lista(resultado);
                destruir_lista(primeiro);
                destruir_lista(segundo);
                destruir_lista(resultado);
                primeiro = criar_lista();
                segundo = criar_lista();
                break;
        }
        n--;
    }
    return 0;
}