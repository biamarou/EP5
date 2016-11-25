#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    int l, c, p;
} par;

typedef struct {
    int ind;
    par *jog;
} jogadas;

typedef struct {
	int topo;
	par *visita;
} pilha;

#endif