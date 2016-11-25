#ifndef S_MOVIMENTO_H
#define S_MOVIMENTO_H

par recebeJogada (char **tab);

void fazMovimento (char **tab, int lin, int col, int vez, char pecas);

int verificaTroca (char **tab, par op);

int verificaVantagem (par op);

void imprimeTabuleiro (char **tab);

void imprimeJogada (int lin, int col);

#endif