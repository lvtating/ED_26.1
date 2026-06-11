#include <stdio.h>
#include "listas.h"

typedef struct {
    int *v;
    int ini, fim, N, tamanho;
} Fila;
typedef Fila *p_fila;

//criando fila vazia
p_fila criar(int N){

    p_fila f = malloc(sizeof(Fila));
    f->v = malloc(N*sizeof(int));
    f->ini = 0;
    f->fim = 0;
    f->N = N;
    f->tamanho = 0;

    return f;
}

//adicionando
void enfileira(p_fila f, int x){
    f->v[f->fim] = x;
    f->fim = (f->fim+1) % f->N;
    f->tamanho++;
}

//removendo
int desenfileira(p_fila f){
    int x = f->v[f->ini];
    f->ini = (f->ini+1) % f->N;
    f->tamanho--;

    return x;
}