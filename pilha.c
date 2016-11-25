#include <stdlib.h>
#include "struct.h"

pilha* criaPilha () {
	pilha *p;
	p = malloc(sizeof(pilha));
	p->visita = malloc(196*sizeof(par));
	p->topo = 0;

	return p;
}

void inserePilha (pilha *p, par j) {
	p->visita[p->topo] = j;
	p->topo++;
}

par removePilha (pilha *p) {
	par j;
	p->topo--;
	j = p->visita[p->topo];

	return j;
}

int pilhaVazia (pilha *p) {
    if (p->topo == 0)
        return 1;
    else
        return 0;
}

void destroiPilha (pilha *p) {
	free(p->visita);
	p->visita = NULL;

	free(p);
	p = NULL;
}