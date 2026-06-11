#include "listas.h"
#include <stdio.h>

// (a) Escreva um algoritmo para, dada uma lista ordenada, insira um número em ordem.
p_no adicionar_elemento_ordenado(p_no lista, int x){
    p_no novo = malloc(sizeof(No));
    novo->dado = x;

    if(lista == NULL || lista->dado > x){
        novo->prox = lista;
        return novo;
    }

    p_no atual = lista;
    while(atual != NULL && atual->prox->dado < x){
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    
    return novo;
}


// (b) Escreva um algoritmo que, dadas duas listas arbitrárias, devolva uma lista com a união de todos os
// elementos. Qual a complexidade? O(n²)
int existe(p_no lista, int x){
    while(lista != NULL){
        if(lista->dado == x)
            return 1;
        lista = lista->prox;
    }
    return 0;
}

p_no uniao(p_no lista1, p_no lista2){
    p_no resultado = copiar_lista(lista1);
    
    while(lista2 != NULL){
        if(!existe(resultado, lista2->dado)){
            p_no novo = malloc(sizeof(No));
            novo->dado = lista2->dado;
            novo->prox = resultado;
            resultado = novo;
        }
        lista2 = lista2->prox;
    }
    
    return resultado;
}


// (c) Escreva um algoritmo que, dadas duas listas ordenadas, devolva uma lista com a união de todos os
// elementos. Qual a complexidade?

int existe(p_no lista, int x){
    while(lista != NULL){
        if(lista->dado == x)
            return 1;
        lista = lista->prox;
    }
    return 0;
}

p_no copiar_lista(p_no lista){
    if(lista == NULL)
        return NULL;
    p_no novo = malloc(sizeof(No));
    novo->dado = lista->dado;
    novo->prox = copiar_lista(lista->prox);
}

p_no copiar_iterativa(p_no lista){
    p_no nova_lista = NULL, ultimo = NULL;
    for(p_no p = lista; p != NULL; p = p->prox){
        p_no novo_no = malloc(sizeof(No));
        novo_no->dado = p->dado;
        novo_no->prox = NULL;
        if(nova_lista == NULL){
            nova_lista = novo_no;
        }
        else{
            ultimo->prox = novo_no;
        }
        ultimo = novo_no;
    }
    return nova_lista;
}

p_no uniao(p_no lista1, p_no lista2){
    p_no resultado = copiar_lista(lista1);

    while(lista2 != NULL){
        if(!existe(resultado, lista2->dado)){
            resultado = adicionar_elemento_ordenado(resultado, lista2->dado);
        }
        lista2 = lista2->prox;
    }
    return resultado;
} 