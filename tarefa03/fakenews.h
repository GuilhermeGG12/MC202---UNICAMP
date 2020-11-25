
typedef struct termo {
    char *nome;
    double max;
    double min;
    double media;
    double desvio;
} Termo;

typedef struct componente {
    char *nome;
    int qtd;
} Componente;

typedef struct categoria {
    Componente **componentes;
} Categoria;



void separa_dados(Termo **termos, int m, int n);

void define_categorias(Categoria **categorias, int n, Termo **termos);

void libera_termos(Termo **termos, int n);

void libera_categorias(Categoria **categorias, int n);

void imprime_categorias(Categoria **categorias);