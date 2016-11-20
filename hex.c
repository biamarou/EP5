#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recebeJogada (int *op_lin, int *op_col) {
    printf("Insira sua jogada.\n");
    scanf("%d %d", op_lin, op_col);
}

void encontraJogada () {
    
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