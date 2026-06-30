#include <stdio.h>
#include "ABB.h"

p_no buscar(p_no raiz, int chave){
    if(raiz == NULL || raiz->chave == chave)
        return raiz;
    if(chave < raiz->chave)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
}

p_no buscar_iterativa(p_no raiz, int chave){
    while(raiz!= NULL || raiz->chave != chave)
        if(chave < raiz->chave)
            raiz = raiz->esq;
        else   
            raiz = raiz->dir;
    return raiz;
}

p_no inserir(p_no raiz, int chave){
    p_no novo;
    if(raiz == NULL){
        novo = malloc(sizeof(struct no));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        return novo;
    }
    if(chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else
        raiz->dir = inserir(raiz->dir, chave);

    return raiz;
}

p_no minimo(p_no raiz){
    if(raiz == NULL || raiz->esq == NULL)
        return raiz;
    return minimo(raiz->esq);
}

p_no minimo_iterativa(p_no raiz){
    while(raiz != NULL && raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

p_no sucessor(p_no x){
    if(x->dir != NULL)
        return minimo(x->dir);
    else
        return ancestral_a_direita;
}

p_no ancestral_a_direita(p_no x){
    if(x == NULL)
        return NULL;
    if(x->pai == NULL || x->pai->esq == x)
        return x->pai;
    else 
        return ancestral_a_direita(x->pai);
}

p_no remover_rec(p_no raiz, int chave){
    if(raiz == NULL)
        return NULL;
    if(chave < raiz->chave)
        raiz->esq = remover_rec(raiz->esq, chave);
    else if(chave > raiz->chave)
        raiz->dir = remover_rec(raiz->dir, chave);
    else if(raiz->esq == NULL)
        return raiz->dir;
    else if(raiz->dir == NULL)
        return raiz->esq;
    else
        remover_sucessor(raiz);
    return raiz;
}

void remover_sucessor(p_no raiz){
    p_no min = raiz->dir;
    p_no pai = raiz;
    while(min->esq != NULL){
        pai = min;
        min = min->esq;
    }
    if(pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;

    raiz->chave = min->chave;
}

void imprime(p_no raiz){
    if(raiz != NULL){
        imprime(raiz->esq);
        printf("%d", raiz->chave);
        imprime(raiz->dir);
    }
}

p_no ancestral_sem_pai(p_no x, p_no raiz){
    p_no atual = raiz;
    p_no ancestral = NULL;
    while(atual->chave != x->chave){
        if(atual->chave > x->chave){
            ancestral = atual;
            atual = atual->esq;
        } else
            atual = atual->dir;
    }
    return ancestral;
}