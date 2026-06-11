#include <stdio.h>
#include "listas.h"

typedef struct {
    p_no topo;
} Pilha;
typedef Pilha *p_pilha;

//empilhar
void empilhar(p_pilha p, int x){
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = p->topo;
    p->topo = novo;
}

//desempilhar
int desempilhar(p_pilha p){
    p_no primeiro = p->topo;
    int x = primeiro->dado;
    p->topo = p->topo->prox;
    free(primeiro);
    return x;
}