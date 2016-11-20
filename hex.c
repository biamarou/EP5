#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int l, c;
} par;

typedef struct {
    int t, num_j;
    par *coord;
} vetor;

void recebeJogada (int *op_lin, int *op_col) {
    printf("Insira sua jogada.\n");
    scanf("%d %d", op_lin, op_col);
}

/*Forma caminho por linhas*/
void encontraJogadaB (char **tab, vetor jogadas) {
    int i, j, swap;
    swap = 0;
    if (jogadas.t)

    for (i = 0; i < 14; i++)
        for (j = 0; j < 14; j++)
            if (jogadas.t == 1 && tab[i][j] == 'p')
                swap = 1;
}

/*Forma caminhos por colunas*/
void encontraJogadaP (char **tab) {

}

void imprimeJogada (int lin, int col) {
    printf("%d %d\n", lin, col);
}

void fazMovimento (char **tab, int lin, int col, int vez, char *pecas) {
    if (vez)
        tab[lin][col] = *pecas;
    
    else {
        
        while (lin < 0 || lin > 13 || col < 0 || col > 13) {
            printf("Movimento inválido. Insira um novo.\n");
            scanf("%d %d", &lin, &col);
        }
        if (strcmp(pecas, "b") == 0)
            tab[lin][col] = 'p';
        else
          tab[lin][col] = 'b';  
    }   
}

vetor criaVetordeJogadas () {
    vetor j;
    j.t = 28;
    j.coord = malloc(j.t*sizeof(par));
    j.num_j = 0;

    return j;
}

void realocaVetordeJogadas (vetor j) {
    int i;
    par *v;

    v = malloc(2*j.t*sizeof(par));

    for (i = 0; i < j.t; i++) {
        v[i] = j.coord[i];
    }

    free(j.coord);
    j.coord = v;
    j.t *= 2;
}

void destroiVetordeJogadas (vetor j) {
    free(j.coord);
}

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

    int i, j;
    for (i = 0; i < 14; i++) {
        for (j = 0; j < 14; j++)
            printf("%c ", tab[i][j]); 
        printf("\n");
    }
}

int main (int argc, char **argv) {
    
    int min_lin, min_col, op_lin, op_col;   
    char *pecas, *imprime;
    char **tabuleiro;
    
    pecas = argv[1];
    if (argc > 2)
        imprime = argv[2];

    tabuleiro = criaTabuleiro();

    if (strcmp(pecas, "b") == 0)
        printf("eu começo\n");
    else if (strcmp(pecas, "p") == 0)
        printf("você começa\n");
    else
        printf("argumento inválido\n");

    return 0;
}