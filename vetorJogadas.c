#include <stdlib.h>
#include "struct.h"

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