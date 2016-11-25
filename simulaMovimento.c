#include <stdio.h>
#include "struct.h"
#include "pilha.h"

par recebeJogada (char **tab) {
    par op;
    printf("Insira sua jogada.\n");
    scanf("%d %d", &op.l, &op.c);
    
    while (op.l < 0 || op.l > 13 || op.c < 0 || op.c > 13) {
        printf("Movimento inválido. Insira um novo.\n");
        scanf("%d %d", &op.l, &op.c);
    }
    
    return op;
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

int verificaFim (char **tab) {
    int i, j, viz;
    par p;
    pilha *caminho = criaPilha();
    ganhou = 0;

    for (i = j = 0; i < 14; i++) {
        if (tab[i][j] == 'b') {
            p.l = i; p.c = j; p.p = 1;
            inserePilha(p);
            
            while (pilhaVazia(caminho) == 0) {
                viz = empilhaVizinhos(caminho, p);
                if (viz) {
                    p = removePilha(caminho);
                    p.p = 1;
                    inserePilha(p);
                }
                else {
                    while (pilhaVazia == 0 && p.p)
                        p = removePilha(caminho);
                }
            }
        }
    }
 

    for (i = j = 0; j < 14; j++) {
        if (tab[i][j] == 'p') {
            p.l = i; p.c = j;
            inserePilha(p);    
        }
    }
}

int verificaTroca (char **tab, par op) {
    int i, j, conta;
    for (i = conta = 0; i < 14; i++) {
        for (j = 0; j < 14; j++) {
            if (tab[i][j] == 'b' && op.l == i && op.c == j)
                conta++;
        }
    }
    if (conta == 1)
        return 1;
    
    return 0;
}

int verificaVantagem (par op) {
    if (op.l == 6 && (op.c == 6 || op.c == 7))
        return 1;

    if (op.l == 7 && (op.c == 6 || op.c == 7))
        return 1;

    return 0;
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

void imprimeJogada (int lin, int col) {
    printf("%d %d\n", lin, col);
}