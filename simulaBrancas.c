#include "struct.h"
#include "vetorJogadas.h"
#include "simulaPretas.h"
#include "simulaMovimento.h"

/*Movimento 1 e 2 são de ataque (ponte e parede, respectivamente)*/
int mov_1_cima_B (char **tab, par p, par *c) {
    if (p.l >= 2 && p.c <= 12) {
        
        if (tab[p.l - 2][p.c + 1] == 'b') {
            if (tab[p.l - 1][p.c] == '-' && tab[p.l - 1][p.c + 1] == 'p') {
                c->l = p.l - 1;
                c->c = p.c;
                c->p = 6;
                return 1;
            }
            if (tab[p.l - 1][p.c] == 'p' && tab[p.l - 1][p.c + 1] == '-') {
                c->l = p.l - 1;
                c->c = p.c + 1;
                c->p = 6;
                return 1;
            }
        }

        if (tab[p.l - 2][p.c + 1] == '-') {
            if (tab[p.l - 1][p.c] == '-' && tab[p.l - 1][p.c + 1] == '-') {
                c->l = p.l - 2;
                c->c = p.c + 1;
                c->p = 5;
                return 1;
            }
        }    
    }

    return 0;
}


int mov_1_baixo_B (char ** tab, par p, par *c) {

    if (p.l <= 11 && p.c >= 1) {
        if (tab[p.l + 2][p.c - 1] == 'b') {
            if (tab[p.l + 1][p.c] == '-' && tab[p.l + 1][p.c - 1] == 'p') {
                c->l = p.l + 1;
                c->c = p.c;
                c->p = 4;
                return 1;
            }
            if (tab[p.l + 1][p.c] == 'p' && tab[p.l + 1][p.c - 1] == '-') {
                c->l = p.l + 1;
                c->c = p.c - 1;
                c->p = 4;
                return 1;
            }
        }

        if (tab[p.l + 2][p.c - 1] == '-') {
            if (tab[p.l + 1][p.c] == '-' && tab[p.l + 1][p.c - 1] == '-') {
                c->l = p.l + 2;
                c->c = p.c - 1;
                c->p = 3;
                return 1;
            }
        }   
    }

    return 0;
}

int mov_2_cima_B (char ** tab, par p, par *c) {
    if (p.l >= 1) {
        if (p.c <= 12 && tab[p.l - 1][p.c] == 'p') {
            if (tab[p.l - 1][p.c + 1] == '-') {
                c->l = p.l - 1;
                c->c = p.c + 1;
                c->p = 2;
                return 1;
            }
        }
        if (p.c <= 12 && tab[p.l - 1][p.c + 1] == 'p') {
            if (tab[p.l - 1][p.c] == '-') {
                c->l = p.l - 1;
                c->c = p.c;
                c->p = 2;
                return 1;
            }
        }
    }
    return 0;
}

int mov_2_baixo_B (char ** tab, par p, par *c) {
    if (p.l <= 12) {
        if (p.c >= 1 && tab[p.l + 1][p.c] == 'p') {
            if (tab[p.l + 1][p.c - 1] == '-') {
                c->l = p.l + 1;
                c->c = p.c - 1;
                c->p = 1;
                return 1;
            }
        }
        if (p.c >= 1 && tab[p.l + 1][p.c - 1] == 'p') {
            if (tab[p.l + 1][p.c] == '-') {
                c->l = p.l + 1;
                c->c = p.c;
                c->p = 1;
                return 1;
            }
        }
    }
    return 0;
}

/*Movimentos 3 e 4 são de defesa*/
int mov_3_cima (char ** tab, par p, par *c) {
    if (p.l >= 1) {
        if (p.c <= 11 && tab[p.l - 1][p.c + 2] == '-') {
            if (tab[p.l - 1][p.c + 1] == '-' && tab[p.l][p.c + 1] == '-') {
                c->l = p.l - 1;
                c->c = p.c + 2;
                c->p = 7;
                return 1;
            }
        }
    }
    return 0;
}

int mov_3_baixo (char ** tab, par p, par *c) {
    if (p.l <= 12) {
        if (p.c >= 2 && tab[p.l + 1][p.c - 2] == '-') {
            if (tab[p.l + 1][p.c] == '-' && tab[p.l + 1][p.c - 1] == '-') {
                c->l = p.l + 1;
                c->c = p.c - 2;
                c->p = 8;
                return 1;
            }
        }
    }
    return 0;
}

int mov_4_cima (char ** tab, par p, par *c) {
    if (p.l >= 1) {
        if (p.c <= 12 && tab[p.l - 2][p.c + 1] == 'p') {
            if (tab[p.l - 1][p.c] == '-' && tab[p.l - 1][p.c + 1] == 'b') {
                c->l = p.l - 1;
                c->c = p.c;
                c->p = 9;
                return 1;
            }
        
            if (tab[p.l - 1][p.c] == 'b' && tab[p.l - 1][p.c + 1] == '-') {
                c->l = p.l - 1;
                c->c = p.c + 1;
                c->p = 9;
                return 1;
            }
        }
    }

    return 0;
}

int mov_4_baixo (char ** tab, par p, par *c) {
    if (p.l <= 11) {
        if (p.c >= 1 && tab[p.l + 2][p.c - 1] == 'p') {
            if (tab[p.l + 1][p.c] == '-' && tab[p.l + 1][p.c - 1] == 'b') {
                c->l = p.l + 1;
                c->c = p.c;
                c->p = 10;
                return 1;
            }
        
            if (tab[p.l + 1][p.c] == 'b' && tab[p.l + 1][p.c - 1] == '-') {
                c->l = p.l + 1;
                c->c = p.c - 1;
                c->p = 10;
                return 1;
            }
        }
    }

    return 0;
}

/*Forma caminho por linhas*/
void encontraJogadaB (char **tab, jogadas *possiveis) {
    int i, j;
    par cord, pos;

    if (possiveis->ind) {
        resetaJogadas(possiveis);
        for (i = 0; i < 14; i++) {
            for (j = 0; j < 14; j++) {
                pos.l = i; 
                pos.c = j;
                if (tab[i][j] == 'b') {
                   
                    if (mov_1_cima_B(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }
                    
                    if (mov_1_baixo_B(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }

                    if (mov_2_cima_B(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }

                    if (mov_2_baixo_B(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }
                }

                if (tab[i][j] == 'p') {
                    if (mov_3_cima(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }

                    if (mov_3_baixo(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }

                    if (mov_4_cima(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }

                    if (mov_4_baixo(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }
                }
            }
        }
    }

    else {
        tab[6][6] = 'b';
        cord.l = cord.c = cord.p = 6;
        possiveis->jog[possiveis->ind] = cord;
        possiveis->ind = 1;
    }
}

void simulaJogoB (char **tab, char imp, int feitas) {
    int conta = 0;
    int i, ataque, defesa, pie;
    par op, m_at, m_df;
    jogadas p;

    pie = 0;
    p = criaVetorJogadas(); 

    while (conta < 10) {

        ataque = defesa = 0;
        m_at.p = m_df.p = 0;

        encontraJogadaB(tab, &p);
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
     
        if (ataque >= defesa) {
            fazMovimento(tab, m_at.l, m_at.c, 1, 'b');
            imprimeJogada(m_at.l, m_at.c);
        }
        else {
            fazMovimento(tab, m_df.l, m_df.c, 1, 'b');
            imprimeJogada(m_df.l, m_df.c);
        }

        imprimeTabuleiro(tab);
        op = recebeJogada(tab);

        if (pie == 0 && feitas == 0) {
            if (verificaTroca(tab, op)) {
                simulaJogoP(tab, imp, 1);
                return;
            }
        }

        fazMovimento(tab, op.l, op.c, 0, 'b');
        imprimeTabuleiro(tab);
        conta++;
        pie++;
    }
}