#ifndef PILHA_H
#define PILHA_H

pilha* criaPilha ();

void inserePilha (pilha *p, par j);

par removePilha (pilha *p);

int pilhaVazia (pilha *p);

void destroiPilha (pilha *p);

#endif