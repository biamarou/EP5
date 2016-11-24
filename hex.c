#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int l, c, p;
} par;

typedef struct {
    int ind;
    par *jog;
} jogadas;

char** criaTabuleiro () {

    int i, j;
    char **tab;

    tab = malloc(14*sizeof(char*));
    
    for (i = 0; i < 14; i++ ) {
        tab[i] = malloc(14);
        for (j = 0; j < 14; j++)
            tab[i][j] = '-';
    }

    return tab;
}

void destroiTabuleiro (char **tab) {

    int i, j;
    
    for (i = 0; i < 14; i++ ) {
        for (j = 0; j < 14; j++)
            tab[i][j] = 0;
        free(tab[i]);
    }

    free(tab);
}

void imprimeTabuleiro (char **tab) {

    int i, j, k;
    for (i = 0; i < 14; i++) {
        for (k = 0; k < i; k++)
            printf(" ");
        for (j = 0; j < 14; j++)
            printf("%c ", tab[i][j]); 
        printf("\n");
    }
}

par recebeJogada (char **tab) {
    par oponente;
    printf("Insira sua jogada.\n");
    scanf("%d %d", &oponente.l, &oponente.c);
    
    while (lin < 0 || lin > 13 || col < 0 || col > 13) {
        printf("Movimento inválido. Insira um novo.\n");
        scanf("%d %d", &oponente.l, &oponente.c);
    }

    while (tab[oponente.l][oponente.c] != '-') {
        printf("Posição já ocupada. Insira nova jogada.\n");
        scanf("%d %d", &oponente.l, &oponente.c);
    }
    return oponente;
}

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

int mov_4_baixo (char ** tab, par p, par *c) {
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

jogadas criaVetorJogadas () {
    jogadas j;
    j.jog = malloc(196*sizeof(par));
    j.ind = 0;

    return j;
}


void resetaJogadas (jogadas *p) {
    int i;
    par zerador;
    zerador.l = zerador.c = zerador.p = 0; 

    for (i = 0; i < p->ind; i++)
        p->jog[i] = zerador;

    p->ind = 0;
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

void imprimeJogada (int lin, int col) {
    printf("%d %d\n", lin, col);
}
/*lin e col separadas por causa da jogada do oponente*/
void fazMovimento (char **tab, int lin, int col, int vez, char pecas) {
    if (vez)
        tab[lin][col] = pecas;
    
    else {
        
        if (pecas == 'b')
            tab[lin][col] = 'p';
        else
          tab[lin][col] = 'b';  
    }   
}

int verificaTroca (char **tab) {
    int i, j;
    for (i = 0; i < 14; i++) {
        for (j = 0; j < 14; j++) {
            if (tab[i][j] == 'p')
                return 0;
        }
    }
    
    return 1;
}

void simulaJogoB (char **tab, char *imp) {
    int cont = 0;
    int i, ataque, defesa, pie;
    par op, m_at, m_df;
    jogadas p;

    pie = 0;
    p = criaVetorJogadas(); 

    while (cont < 10) {
        
        if (pie == 1) {
            if (verificaTroca(tab)) {
                simulaJogoP(tab, imp);
                return;
            }
        }

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
        op = recebeJogada();
        fazMovimento(tab, op.l, op.c, 0, 'b');
        imprimeTabuleiro(tab);
        cont++;
        pie++;
    }
}

int main (int argc, char **argv) {
       
    char *pecas, *imprime;
    char **tabuleiro;
    
    pecas = argv[1];
    if (argc > 2)
        imprime = argv[2];

    tabuleiro = criaTabuleiro();

    if (strcmp(pecas, "b") == 0) {
        printf("eu começo\n");
        simulaJogoB(tabuleiro, imprime);
    }

    else if (strcmp(pecas, "p") == 0){
        printf("você começa\n");
        simulaJogoP(tabuleiro, imprime);
    }
    else
        printf("argumento inválido\n");

    return 0;
}