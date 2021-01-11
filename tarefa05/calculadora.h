typedef struct No {
    char algarismo;
    struct No *prox;
} No;

typedef struct No * p_no;

p_no criar_lista();

p_no adicionar_algarismo(p_no num, int algarismo);

p_no inverter_lista(p_no lista);

void imprime_lista(p_no lista);

void destruir_lista(p_no lista);

int verifica_tamanho(p_no numero);

p_no cria_lista_vazia(int tam);

p_no adiciona_zeros(p_no numero, int dif);

p_no somar_listas(p_no primeiro, p_no segundo);

p_no subtrai_listas(p_no primeiro, p_no segundo);

p_no arranja_listas(p_no primeiro, p_no segundo);

p_no multiplica_listas(p_no primeiro, p_no segundo);