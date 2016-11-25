#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "vetorJogadas.h"
#include "simulaBrancas.h"
#include "simulaPretas.h"

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

int main (int argc, char **argv) {
       
    char pecas, imprime;
    char **tabuleiro;
    
    pecas = argv[1][0];
    if (argc > 2)
        imprime = argv[2][0];

    tabuleiro = criaTabuleiro();

    if (pecas == 'b') {
        printf("eu começo\n");
        simulaJogoB(tabuleiro, imprime, 0);
    }

    else if (pecas == 'p'){
        printf("você começa\n");
        simulaJogoP(tabuleiro, imprime, 0);
    }
    else
        printf("argumento inválido\n");

    return 0;
}