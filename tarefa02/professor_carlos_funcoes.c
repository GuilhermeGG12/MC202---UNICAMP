#include "professor_carlos.h"

void converte_data(Turma t[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 50; j++){
            int calculo = t[i].alunos[j].nascimento.ano*10000+t[i].alunos[j].nascimento.mes*100+t[i].alunos[j].nascimento.dia;
            if(calculo == 0){
                break;
            }else{
                t[i].alunos[j].nascimento.dia = calculo;
                t[i].alunos[j].nascimento.mes = 0;
                t[i].alunos[j].nascimento.ano = 0;
            }
        }
    }   
}

void define_quantidade(Turma t[], int n){
    int qtd = 0;
    for(int i = 0; i < n; i++){
        qtd = 0;
        for(int j = 0; j < 50; j++){
            if(t[i].alunos[j].nome[0] != 0){
                qtd++;
            }else{
                break;
            }
        }
        t[i].qtd = qtd;
    }
}

Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j){
    int nascimento = t[j].alunos[0].nascimento.dia;
    Aluno aluno_novo;
    int desempatou = 0;
    aluno_novo = t[j].alunos[0];
    for(int i = 1; i <= 49; i++){
        desempatou = 0;
        if(t[j].alunos[i].nascimento.dia == 0){
            break;
        }
        else if(t[j].alunos[i].nascimento.dia > nascimento){
            nascimento = t[j].alunos[i].nascimento.dia;
            aluno_novo = t[j].alunos[i];
        }
        else if(t[j].alunos[i].nascimento.dia == nascimento){
            for(int k = 0; k < 15; k ++){
                if(t[j].alunos[i].nome[k] < aluno_novo.nome[k]){
                    nascimento = t[j].alunos[i].nascimento.dia;
                    aluno_novo = t[j].alunos[i];
                }
                else if(t[j].alunos[i].nome[k] > aluno_novo.nome[k]){
                    break;
                }
                else{
                    if(t[j].alunos[i].nome[k] == aluno_novo.nome[k] && k == 14){
                        for(int l = 0; l < 15; l++){
                            if(t[j].alunos[i].sobrenome[l] < aluno_novo.sobrenome[l]){
                                nascimento = t[j].alunos[i].nascimento.dia;
                                aluno_novo = t[j].alunos[i];
                            }
                            else if(t[j].alunos[i].sobrenome[l] > aluno_novo.sobrenome[l]){
                                desempatou = 1;
                                break;
                            }
                        }
                    }
                }

                if(desempatou == 1){
                    break;
                }
            }

        }
    }
    return aluno_novo;
}

Aluno procura_velho_na_turma(Turma t[], int qtd_turmas, int j){
    int nascimento = t[j].alunos[0].nascimento.dia;
    int desempatou = 0;
    Aluno aluno_velho;
    aluno_velho = t[j].alunos[0];
    for(int i = 1; i <= 49; i++){
        desempatou = 0;
        if(t[j].alunos[i].nascimento.dia == 0){
            break;
        }
        else if(t[j].alunos[i].nascimento.dia < nascimento){
            nascimento = t[j].alunos[i].nascimento.dia;
            aluno_velho = t[j].alunos[i];
        }
        else if(t[j].alunos[i].nascimento.dia == nascimento){
            for(int k = 0; k < 15; k ++){
                if(t[j].alunos[i].nome[k] < aluno_velho.nome[k]){
                    nascimento = t[j].alunos[i].nascimento.dia;
                    aluno_velho = t[j].alunos[i];
                }
                else if(t[j].alunos[i].nome[k] > aluno_velho.nome[k]){
                    break;
                }
                else{
                    if(t[j].alunos[i].nome[k] == aluno_velho.nome[k] && k == 14){
                        for(int l = 0; l < 15; l++){
                            if(t[j].alunos[i].sobrenome[l] < aluno_velho.sobrenome[l]){
                                nascimento = t[j].alunos[i].nascimento.dia;
                                aluno_velho = t[j].alunos[i];
                            }
                            else if(t[j].alunos[i].sobrenome[l] > aluno_velho.sobrenome[l]){
                                desempatou = 1;
                                break;
                            }
                        }
                    }
                }

                if(desempatou == 1){
                    break;
                }
            }

        }
    }
    return aluno_velho;
}

Aluno procura_novo_todas_turmas(Turma t[], int qtd_turmas){
    int nascimento = t[0].alunos[0].nascimento.dia;
    int desempatou = 0;
    Aluno aluno_novo;
    aluno_novo = t[0].alunos[0];
    for(int i = 0; i < qtd_turmas; i++){
        for(int j = 0; j < 50; j++){
            desempatou = 0;
            if(t[i].alunos[j].nascimento.dia == 0){
                break;
            }else if(t[i].alunos[j].nascimento.dia > nascimento){
                nascimento = t[i].alunos[j].nascimento.dia;
                aluno_novo = t[i].alunos[j];
            }
            else if(t[j].alunos[i].nascimento.dia == nascimento){
                for(int k = 0; k < 15; k ++){
                    if(t[i].alunos[j].nome[k] < aluno_novo.nome[k]){
                        nascimento = t[i].alunos[j].nascimento.dia;
                        aluno_novo = t[i].alunos[j];
                    }
                    else if(t[i].alunos[j].nome[k] > aluno_novo.nome[k]){
                        break;
                    }
                    else{
                        if(t[i].alunos[j].nome[k] == aluno_novo.nome[k] && k == 14){
                            for(int l = 0; l < 15; l++){
                                if(t[i].alunos[j].sobrenome[l] < aluno_novo.sobrenome[l]){
                                    nascimento = t[i].alunos[j].nascimento.dia;
                                    aluno_novo = t[i].alunos[j];
                                }
                                else if(t[i].alunos[j].sobrenome[l] > aluno_novo.sobrenome[l]){
                                    desempatou = 1;
                                    break;
                                }
                            }
                        }
                    }

                    if(desempatou == 1){
                        break;
                    }
            }

            }
        }
    }
    return aluno_novo;
}

Aluno procura_velho_todas_turmas(Turma t[], int qtd_turmas){
    int nascimento = t[0].alunos[0].nascimento.dia;
    int desempatou = 0;
    Aluno aluno_velho;
    aluno_velho = t[0].alunos[0];
    for(int i = 0; i < qtd_turmas; i++){
        for(int j = 0; j < 50; j++){
            desempatou = 0;
            if(t[i].alunos[j].nascimento.dia == 0){
                break;
            }else if(t[i].alunos[j].nascimento.dia < nascimento){
                nascimento = t[i].alunos[j].nascimento.dia;
                aluno_velho = t[i].alunos[j];
            }
            else if(t[i].alunos[j].nascimento.dia == nascimento){
                for(int k = 0; k < 15; k ++){
                    if(t[i].alunos[j].nome[k] < aluno_velho.nome[k]){
                        nascimento = t[i].alunos[j].nascimento.dia;
                        aluno_velho = t[i].alunos[j];
                    }
                    else if(t[i].alunos[j].nome[k] > aluno_velho.nome[k]){
                        break;
                    }
                    else{
                        if(t[i].alunos[j].nome[k] == aluno_velho.nome[k] && k == 14){
                            for(int l = 0; l < 15; l++){
                                if(t[i].alunos[j].sobrenome[l] < aluno_velho.sobrenome[l]){
                                    nascimento = t[i].alunos[j].nascimento.dia;
                                    aluno_velho = t[i].alunos[j];
                                }
                                else if(t[i].alunos[j].sobrenome[l] > aluno_velho.sobrenome[l]){
                                    desempatou = 1;
                                    break;
                                }
                            }
                        }
                    }

                    if(desempatou == 1){
                        break;
                    }
                }

            }
        }
    }
    return aluno_velho;
}

int conta_substrings(Turma t[], int qtd_turmas, char *padrao){
    int i, j, k;
    int contador = 0;
    int contido = 0;
    int aux = 0;
    for(i = 0; i < qtd_turmas; i++){
        for(j = 0; j < 50; j++){
            aux = 0;
            if(t[i].alunos[j].nome[0] == '\0'){
                break;
            }
            for(k = 0; t[i].alunos[j].nome[k] != '\0' && padrao[aux] != '\0'; k++){
                if(t[i].alunos[j].nome[k] == '\0' || t[i].alunos[j].nome[k] != padrao[aux]){
                    contido = 1;
                    aux = 0;
                } 
                else{
                    if(padrao[aux + 1] != '\0'){
                        contido = 1;
                        aux++;
                    }
                    else{
                        contido = 0;
                        aux++;
                    }
                }
                   
            }
            if(contido == 0){
                contador++;
            }
        }
    }
    

    return contador;
}

int add_aluno(Turma t[], Aluno A, int j){
    int h;
    h = t[j].qtd;  
    // Como A.nome é char fazer um for que passa alterando cada caracter
    for(int i = 0; i < 15; i++){
        if(A.nome[i] == 0 && A.sobrenome[i] == 0){
            break;
        }else{
            t[j].alunos[h].nome[i] = A.nome[i];
            t[j].alunos[h].sobrenome[i] = A.sobrenome[i];
        }
    }
    t[j].alunos[h].nascimento.dia = A.nascimento.ano*10000 +A.nascimento.mes*100+A.nascimento.dia;
    t[j].qtd++;

    return h + 1;
}
int remove_aluno(Turma t[], int j){
    int h = t[j].qtd;
    for(int i = 0; i < 15; i++){
        t[j].alunos[h-1].nome[i] = 0;
        t[j].alunos[h-1].sobrenome[i] = 0;
    }
    t[j].alunos[h-1].nascimento.dia = 0;
    t[j].alunos[h-1].nascimento.mes = 0;
    t[j].alunos[h-1].nascimento.ano = 0;

    t[j].qtd--;

    return h - 1;
}

 