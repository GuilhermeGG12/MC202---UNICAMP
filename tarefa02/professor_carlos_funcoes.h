#include "professor_carlos.h"

void converte_data(Turma t[], int n);

void define_quantidade(Turma t[], int n);

Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j);

Aluno procura_velho_na_turma(Turma t[], int qtd_turmas, int j);

Aluno procura_novo_todas_turmas(Turma t[], int qtd_turmas);

Aluno procura_velho_todas_turmas(Turma t[], int qtd_turmas);

int conta_substrings(Turma t[], int qtd_turmas, char *padrao);

int add_aluno(Turma t[], Aluno A, int j);

int remove_aluno(Turma t[], int j);