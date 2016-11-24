#include <stdio.h>
#include <stdlib.h>

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

int mov_2_cima_P (char ** tab, par p, par *c) {
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

int mov_2_baixo_P (char ** tab, par p, par *c) {
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
int mov_3_cima_P (char ** tab, par p, par *c) {
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

int mov_3_baixo_P (char ** tab, par p, par *c) {
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

int mov_4_cima_P (char ** tab, par p, par *c) {
    if (p.l >= 1) {
        if (p.c <= 12 && tab[p.l - 2][p.c + 1] == 'p') {
            if (tab[p.l - 1][p.c] == '-' && tab[p.l - 1][p.c + 1] == 'b') {
                c->l = p.l - 1;
                c->c = p.c;
                c->p = 9;
                return 1;
            }
        }

        if (p.c <= 12 && tab[p.l - 2][p.c + 1] == 'p') {
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

int mov_4_baixo_P (char ** tab, par p, par *c) {
    if (p.l <= 11) {
        if (p.c >= 1 && tab[p.l + 2][p.c - 1] == 'p') {
            if (tab[p.l + 1][p.c] == '-' && tab[p.l + 1][p.c - 1] == 'b') {
                c->l = p.l + 1;
                c->c = p.c;
                c->p = 10;
                return 1;
            }
        }

        if (p.c >= 1 && tab[p.l + 2][p.c - 1] == 'p') {
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

/*Forma caminhos por colunas*/
void encontraJogadaP (char **tab, jogadas *possiveis) {
    int i, j;
    par cord, pos;

    if (possiveis->ind) {
        resetaJogadas(possiveis);
        for (i = 0; i < 14; i++) {
            for (j = 0; j < 14; j++) {
                pos.l = i; 
                pos.c = j;
                if (tab[i][j] == 'p') {
                   
                    if (mov_1_cima_P(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }
                    
                    if (mov_1_baixo_P(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }

                    if (mov_2_cima_P(tab, pos, &cord)) {
                        possiveis->jog[possiveis->ind] = cord;
                        possiveis->ind++;
                    }

                    if (mov_2_baixo_P(tab, pos, &cord)) {
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
}