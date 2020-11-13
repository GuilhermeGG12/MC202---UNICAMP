#include <stdio.h>
#include "professor_carlos_funcoes.h"

int main(){
    int n, m, k;
    int acao;
    int num_turma;
    char substring[15];
    Aluno a;
    scanf("%d %d", &n, &k);
    Turma turmas[50];
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%s %s %d %d %d", turmas[i].alunos[j].nome, turmas[i].alunos[j].sobrenome,
                  &turmas[i].alunos[j].nascimento.dia, &turmas[i].alunos[j].nascimento.mes,
                  &turmas[i].alunos[j].nascimento.ano);
        }
    }
    converte_data(turmas, n);
    define_quantidade(turmas, n);
    while(k > 0){
        scanf("%d", &acao);
        switch(acao){
            case 1:
                scanf("%d", &num_turma);
                printf("%s\n", procura_novo_na_turma(turmas, n, num_turma).nome);
                break;
            case 2:
                scanf("%d", &num_turma);
                printf("%s\n", procura_velho_na_turma(turmas, n, num_turma).sobrenome);
                break;
            case 3:
                printf("%s\n", procura_velho_todas_turmas(turmas, n).nome);
                break;
            case 4:
                printf("%s\n", procura_novo_todas_turmas(turmas, n).sobrenome);
                break;
            case 5:
                scanf("%s", substring);
                printf("%d\n", conta_substrings(turmas, n, substring));
                break;
            case 6:
                scanf("%d", &num_turma);
                scanf("%s %s %d %d %d", a.nome, a.sobrenome, &a.nascimento.dia, &a.nascimento.mes,
                      &a.nascimento.ano);
                printf("%d\n", add_aluno(turmas, a, num_turma));
                break;
            case 7:
                scanf("%d", &num_turma);
                printf("%d\n", remove_aluno(turmas, num_turma));
                break;
        }
        
        k--;
    }
}



