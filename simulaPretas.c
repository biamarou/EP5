#include <stdio.h>
#include "struct.h"
#include "vetorJogadas.h"
#include "simulaBrancas.h"
#include "simulaMovimento.h"

/*Movimento 1 e 2 são de ataque (ponte e parede, respectivamente)*/
int mov_1_direita_P (char **tab, par p, par *c) {
    if (p.l >= 1 && p.c <= 11) {
        
        if (tab[p.l - 1][p.c + 2] == 'p') {
            if (tab[p.l - 1][p.c + 1] == '-' && tab[p.l][p.c + 1] == 'b') {
                c->l = p.l - 1;
                c->c = p.c + 1;
                c->p = 6;
                return 1;
            }
            if (tab[p.l - 1][p.c + 1] == 'b' && tab[p.l][p.c + 1] == '-') {
                c->l = p.l;
                c->c = p.c + 1;
                c->p = 6;
                return 1;
            }
        }

        if (tab[p.l - 1][p.c + 2] == '-') {
            if (tab[p.l - 1][p.c + 1] == '-' && tab[p.l][p.c + 1] == '-') {
                c->l = p.l - 1;
                c->c = p.c + 2;
                c->p = 5;
                return 1;
            }
        }    
    }

    return 0;
}


int mov_1_esquerda_P (char ** tab, par p, par *c) {

    if (p.l <= 12 && p.c >= 2) {
        if (tab[p.l + 1][p.c - 2] == 'p') {
            if (tab[p.l + 1][p.c - 1] == '-' && tab[p.l][p.c - 1] == 'b') {
                c->l = p.l + 1;
                c->c = p.c - 1;
                c->p = 4;
                return 1;
            }
            if (tab[p.l + 1][p.c - 1] == 'b' && tab[p.l][p.c - 1] == '-') {
                c->l = p.l;
                c->c = p.c - 1;
                c->p = 4;
                return 1;
            }
        }

        if (tab[p.l + 1][p.c - 2] == '-') {
            if (tab[p.l + 1][p.c - 1] == '-' && tab[p.l][p.c - 1] == '-') {
                c->l = p.l + 1;
                c->c = p.c - 2;
                c->p = 3;
                return 1;
            }
        }   
    }

    return 0;
}

int mov_2_direita_P (char ** tab, par p, par *c) {
    if (p.c <= 12) {
        if (p.l >= 1 && tab[p.l - 1][p.c + 1] == 'b') {
            if (tab[p.l][p.c + 1] == '-') {
                c->l = p.l;
                c->c = p.c + 1;
                c->p = 2;
                return 1;
            }
        }
        if (p.l >= 1 && tab[p.l - 1][p.c + 1] == '-') {
            if (tab[p.l][p.c + 1] == 'b') {
                c->l = p.l - 1;
                c->c = p.c + 1;
                c->p = 2;
                return 1;
            }
        }
    }
    return 0;
}

int mov_2_esquerda_P (char ** tab, par p, par *c) {
    if (p.c >= 1) {
        if (p.l <= 12 && tab[p.l + 1][p.c - 1] == 'b') {
            if (tab[p.l][p.c - 1] == '-') {
                c->l = p.l;
                c->c = p.c - 1;
                c->p = 2;
                return 1;
            }
        }
        if (p.l <= 12 && tab[p.l][p.c - 1] == 'b') {
            if (tab[p.l + 1][p.c - 1] == '-') {
                c->l = p.l + 1;
                c->c = p.c - 1;
                c->p = 2;
                return 1;
            }
        }
    }
    return 0;
}

/*Movimentos 3 e 4 são de defesa*/
int mov_3_cima_P (char ** tab, par p, par *c) {
    if (p.l >= 2) {
        if (p.c <= 12 && tab[p.l - 2][p.c + 1] == '-') {
            if (tab[p.l - 1][p.c] == '-' && tab[p.l][p.c + 1] == '-') {
                c->l = p.l - 2;
                c->c = p.c + 1;
                c->p = 7;
                return 1;
            }
        }
    }
    return 0;
}

int mov_3_baixo_P (char ** tab, par p, par *c) {
    if (p.l <= 11) {
        if (p.c >= 1 && tab[p.l + 2][p.c - 1] == '-') {
            if (tab[p.l + 1][p.c] == '-' && tab[p.l + 1][p.c - 1] == '-') {
                c->l = p.l + 2;
                c->c = p.c - 1;
                c->p = 8;
                return 1;
            }
        }
    }
    return 0;
}

int mov_4_cima_P (char ** tab, par p, par *c) {
    if (p.l >= 1) {
        if (p.c <= 12 && tab[p.l - 2][p.c + 1] == 'b') {
            if (tab[p.l - 1][p.c] == '-' && tab[p.l - 1][p.c + 1] == 'p') {
                c->l = p.l - 1;
                c->c = p.c;
                c->p = 9;
                return 1;
            }
       
            if (tab[p.l - 1][p.c] == 'p' && tab[p.l - 1][p.c + 1] == '-') {
                c->l = p.l - 1;
                c->c = p.c + 1;
                c->p = 9;
                return 1;
            }
        }
    }

    return 0;
}

int mov_4_baixo_P (char ** tab, par p, par *c) {
    if (p.l <= 11) {
        if (p.c >= 1 && tab[p.l + 2][p.c - 1] == 'b') {
            if (tab[p.l + 1][p.c] == '-' && tab[p.l + 1][p.c - 1] == 'p') {
                c->l = p.l + 1;
                c->c = p.c;
                c->p = 10;
                return 1;
            }
        

            if (tab[p.l + 1][p.c] == 'p' && tab[p.l + 1][p.c - 1] == '-') {
                c->l = p.l + 1;
                c->c = p.c - 1;
                c->p = 10;
                return 1;
            }
        }
    }

    return 0;
}

/*Forma caminhos por colunas*/
void encontraJogadaP (char **tab, jogadas *possiveis) {
    int i, j;
    par cord, pos;

    if (possiveis->ind)
        resetaJogadas(possiveis);
    
    for (i = 0; i < 14; i++) {
        for (j = 0; j < 14; j++) {
            pos.l = i; 
            pos.c = j;
            if (tab[i][j] == 'p') {
                   
                if (mov_1_direita_P(tab, pos, &cord)) {
                    possiveis->jog[possiveis->ind] = cord;
                    possiveis->ind++;
                }
                    
                if (mov_1_esquerda_P(tab, pos, &cord)) {
                    possiveis->jog[possiveis->ind] = cord;
                    possiveis->ind++;
                }

                if (mov_2_direita_P(tab, pos, &cord)) {
                    possiveis->jog[possiveis->ind] = cord;
                    possiveis->ind++;
                }

                if (mov_2_esquerda_P(tab, pos, &cord)) {
                    possiveis->jog[possiveis->ind] = cord;
                    possiveis->ind++;
                }
            }

            if (tab[i][j] == 'b') {
                if (mov_3_cima_P(tab, pos, &cord)) {
                    possiveis->jog[possiveis->ind] = cord;
                    possiveis->ind++;
                }

                if (mov_3_baixo_P(tab, pos, &cord)) {
                    possiveis->jog[possiveis->ind] = cord;
                    possiveis->ind++;
                }

                if (mov_4_cima_P(tab, pos, &cord)) {
                    possiveis->jog[possiveis->ind] = cord;
                    possiveis->ind++;
                }

                if (mov_4_baixo_P(tab, pos, &cord)) {
                    possiveis->jog[possiveis->ind] = cord;
                    possiveis->ind++;
                }
            }
        }
    }  
}

void simulaJogoP (char **tab, char imp, int feitas) {
    int cont = 0;
    int i, ataque, defesa, pie;
    par op, m_at, m_df;
    jogadas p;

    pie = 0;
    p = criaVetorJogadas(); 

    while (cont < 10) {
        
        if (feitas == 0 || cont > 0) {
            op = recebeJogada(tab);
            fazMovimento(tab, op.l, op.c, 0, 'p');
            imprimeTabuleiro(tab);
        }

        if (pie == 0 && feitas == 0) {
            if (verificaVantagem(op)) {
                simulaJogoB(tab, imp, 1);
                return;
            }
        }

        ataque = defesa = 0;
        m_at.p = m_df.p = 0;

        encontraJogadaP(tab, &p);
        for (i = 0; i < p.ind; i++) {
            if (p.jog[i].p >= 1 && p.jog[i].p <= 6) {
                ataque++;
                if (p.jog[i].p > m_at.p)
                    m_at = p.jog[i];
            }
            else {
                defesa++;
                if (p.jog[i].p > m_df.p)
                    m_df = p.jog[i];
            }
        }

        if (ataque > defesa) {
            fazMovimento(tab, m_at.l, m_at.c, 1, 'p');
            imprimeJogada(m_at.l, m_at.c);
        }
        else {
            fazMovimento(tab, m_df.l, m_df.c, 1, 'p');
            imprimeJogada(m_df.l, m_df.c);
        }
        
        imprimeTabuleiro(tab);
        cont++;
        pie++;
    }
}