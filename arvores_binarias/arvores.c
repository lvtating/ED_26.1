#include <stdio.h>
#include "arvores.h"

p_no criar_arvore(int x, p_no esq, p_no dir){
    p_no r = malloc(sizeof(struct no));
    r->dado = x;
    r->esq = esq;
    r->dir = dir;
    
    return r;
}

p_no procurar_no(p_no raiz, int x){
    if(raiz == NULL || raiz->dado == x)
        return raiz;
    p_no esq = procurar_no(raiz->esq, x);
    if(esq != NULL)
        return esq;
    return procurar_no(raiz->dir, x);
}

int numero_nos(p_no raiz){
    if(raiz == NULL)
        return 0;
    return numero_nos(raiz->dir) + numero_nos(raiz->esq) + 1;
}

int altura(p_no raiz){
    if(raiz ==  NULL)
        return 0;
    int h_esq = altura(raiz->esq);
    int h_dir = altura(raiz->dir);

    if(h_esq > h_dir)
        return h_esq + 1;
    else
        return h_dir + 1;

    /*ou return 1 + (h_esq > h_dir ? h_esq : h_dir);*/
}


/*torneio*/

p_no torneio(int *v, int inicio, int fim){
    if(inicio == fim)
        return criar_arvore(v[inicio], NULL, NULL);
    int meio = (inicio+fim)/2;
    p_no esq = torneio(v, inicio, meio);
    p_no dir = torneio(v, meio+1, fim);
    int valor = esq->dado > dir->dado ? esq->dado : dir->dado;

    return criar_arvore(valor, esq, dir);
}

/*percurso em profundidade e expressões*/
void pre_ordem(p_no raiz){
    if(raiz != NULL){
        printf("%d\n", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(p_no raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d\n", raiz->dado);
    }
}

void inordem(p_no raiz){
    if(raiz != NULL){
        inordem(raiz->esq);
        printf("%d\n", raiz->dado);
        inordem(raiz->dir);
    }
}

/*(com pilha)*/
//*
void pre_ordem(p_no raiz){
    p_pilha pilha = criar_pilha;
    empilhar(pilha, raiz);

    while(!pilha_vazia(pilha)){
        raiz = desempilhar(pilha);
        if(raiz != NULL){
            empilhar(pilha, raiz->dir);
            empilhar(pilha, raiz->esq);
            printf("%d\n", raiz->dado);
        }
    }
    destruir_pilha(pilha);
}

//percurso em largura (com fila)
//*
void percurso_em_largura(p_no raiz){
    p_fila fila = criar_fila();
    enfileirar(fila, raiz);

    while(!fila_vazia(fila)){
        raiz = desenfileirar(fila);
        if(raiz != NULL){
            enfileirar(fila, raiz->esq);
            enfileirar(fila, raiz->dir);
            printf("%d", raiz->dado);
        }
    }
    destruir_fila(fila);
}

//numero de folhas
int folhas(p_no raiz){
    if(raiz == NULL)
        return 0;
    if(raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    return folhas(raiz->dir) + folhas(raiz->esq);
}

//apagar todas as folhas que tenham um valor dado
p_no apaga_folhas(p_no raiz, int x){
    if(raiz == NULL)
        return NULL;
    if(raiz->esq == NULL && raiz->dir == NULL && raiz->dado == x){
        free(raiz);
        return NULL;
    }
    raiz->esq = apaga_folhas(raiz->esq, x);
    raiz->dir = apaga_folhas(raiz->dir, x);
    return raiz;
}

//comparar se duas arvores sao iguais
int iguais(p_no arvore1, p_no arvore2){
    if(arvore1 == NULL && arvore2 == NULL)
        return 1;
    if(arvore1 == NULL || arvore2 == NULL)
        return 0;
    return arvore1->dado == arvore2->dado &&
    iguais(arvore1->esq, arvore2->esq) && iguais(arvore1->dir, arvore2->dir);
}