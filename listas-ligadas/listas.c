#include "listas.h"
#include <stdio.h>

p_no criar_list_vazia(){
    return NULL;
}

void destruir_lista(p_no lista){
    if(lista != NULL){
        destruir_lista(lista->prox);
        free(lista);
    }
}

void destruir_iterativa(p_no lista){
    p_no proximo = lista;
    for(p_no atual = lista; atual != NULL; atual = proximo){
        proximo = proximo ->prox;
        free(atual);
    }
}

//criar uma lista nova com o novo elemento incluído
p_no adicionar_elemento(p_no lista, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo ->dado = x;
    novo ->prox = lista;

    return novo;
}

//remover elemento em sua primeira ocorrência
p_no remover_elemento(p_no lista, int x){
    if(lista == NULL)
        return NULL;
    if(lista ->dado == x){
        p_no proximo = lista ->prox;
        free(lista);
        return proximo;
    }
    lista ->prox = remover_elemento(lista ->prox, x);
    return lista;
}

//remover todos as ocorrências do elemento
p_no remover_elemento(p_no lista, int x){
    if(lista == NULL)
        return NULL;
    
    lista ->prox = remover_elemento(lista ->prox, x);
    if(lista ->dado == x){
        p_no proximo = lista ->prox;
        free(lista);
        return proximo;
    }
    return lista;
}

void imprimindo_lista(p_no lista){
    if(lista != NULL){
        printf("%d\n", lista ->dado);
        imprimindo_lista(lista ->prox);
    }
}

void imprimindo_interativa(p_no lista){
    p_no atual;
    for(atual = lista; atual != NULL; atual = atual ->prox)
        printf("%d\n", atual ->dado);
}

p_no copiar_lista(p_no lista){
    p_no novo;
    if(lista == NULL)
        return NULL;
    novo = malloc(sizeof(No));
    novo ->dado = lista ->dado ;
    novo->prox = copiar_lista(lista->prox);

    return novo;
}

p_no copiar_iterativa(p_no lista){
    p_no nova_lista = NULL, ultimo = NULL;
    if(lista == NULL)
        return NULL;
    for(p_no p = lista; p != NULL; p = p->prox){
        p_no novo_no = malloc(sizeof(No));
        novo_no->dado = p->dado;
        novo_no->prox = NULL;

        if(nova_lista == NULL)
            nova_lista = novo_no;
        else
            ultimo->prox = novo_no;
        ultimo = novo_no;
    }
    return nova_lista;
}

p_no inverter(p_no lista){
    p_no atual, ant, inversa = NULL;
    atual = lista;
    while(atual != NULL){
        ant = atual;
        atual = ant->prox;
        ant->prox = inversa;
        inversa = ant;
    }
}

p_no inverter_recursiva(p_no lista){
    p_no inicio;
    inicio->prox = inverter_recursiva(lista->prox);
    lista->prox->prox = lista;
    lista->prox = NULL;
    return inicio;
}

p_no concatenar(p_no primeira, p_no segunda){
    if(primeira == NULL)
        return segunda;

    primeira->prox = concatenar(primeira->prox, segunda);
    return primeira;
}