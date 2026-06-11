#include <stdio.h>
#include <listas.h>

typedef struct No {
    int dado;
    struct No *prox;
};
typedef struct No *p_no;

typedef struct {
    p_no ini, fim;
} Fila;
typedef Fila *p_fila;

//criar fila
p_fila criar(){
    p_fila f;
    f = malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;

    return f;
}

//destruir fila
void destruir(p_fila f){
    destruir_lista(f->ini);
    free(f);
}

//insere no final
void enfileira(p_fila f, int x){
    p_no novo;
    novo = malloc(sizeof(No));   
    novo->dado = x;
    novo->prox = NULL;

    //lista vazia
    if(f->ini == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}

//remove no início
int desenfileira(p_fila f){
    p_no primeiro = f->ini;
    int x = primeiro->dado;
    f->ini = f->ini->prox;
    if(f->ini == NULL)
        f->fim == NULL;
    free(primeiro);
    return x;
}

//lista circular com cabeça
void enfileira_circular(p_fila f, int x){
    p_no novo = malloc(sizeof(No));
    novo->dado = x;

    if(f->fim == NULL){
        f->fim = novo;
        novo->prox = novo;
    } else {
        novo->prox = f->fim->prox;
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileira_circular(p_fila f){
    p_no primeiro = f->fim->prox->prox;
    int x = primeiro->dado;

    if (primeiro == f->fim) {            // se só tiver um elemento (além da cabeça)
        f->fim->prox->prox = f->fim->prox; // cabeça aponta para si mesma
        f->fim = f->fim->prox;             // fim vira o cabeça (fila vazia)
    } else {
        f->fim->prox->prox = primeiro->prox;
    }

    free(primeiro);
    return x;
}



//fila duplamente ligada
typedef struct no {
    int dado;
    struct no *prox, *ant;
} No;
typedef No *p_no;

typedef struct {
    p_no ini, fim;
} Deque;
typedef Deque *p_deque;

//inserir e remover no inicio
void inserir_inicio(p_deque d, int x){
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = d->ini;
    novo->ant = NULL;

    if(d->ini != NULL)
        d->ini->ant = novo;
    else
        d->fim = novo;
    d->ini = novo;
}

int remover_inicio(p_deque d){
    p_no primeiro = d->ini;
    int x = primeiro->dado;
    d->ini = d->ini->prox;
    if(d->ini != NULL)
        d->ini->ant == NULL;
    else
        d->fim = NULL;

    free(primeiro);
    return x;
}

//inserir e remover no final
void inserir_fim(p_deque d, int x){
    p_no novo = malloc(sizeof(No));
    novo->dado = x;
    novo->ant = d->fim;
    novo->prox = NULL;

    if(d->fim != NULL)
        d->fim->prox = novo;
    else
        d->ini = NULL;
    d->fim = novo;
}

int remover_fim(p_deque d){
    p_no primeiro = d->fim;
    int x = primeiro->dado;
    d->fim = d->fim->ant;

    if(d->fim != NULL)
        d->fim->prox = NULL;
    else
        d->ini = NULL;
    
    free(primeiro);
    return x;
}