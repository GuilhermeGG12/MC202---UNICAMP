typedef struct No {
    char algarismo;
    struct No *prox;
} No;

typedef struct No * p_no;

p_no criar_lista();

p_no adicionar_algarismo(p_no num, int algarismo);

p_no somar_listas(p_no primeiro, p_no segundo);