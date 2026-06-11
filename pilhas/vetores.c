#include <stdio.h>

typedef struct {
    int *v;
    int topo;
} Pilha;

typedef Pilha *p_pilha;

//vazia
int pilha_vazia(p_pilha p){
    if(p->topo == NULL)
        return 1;
    return 0;
}

//empilhar
void empilhar(p_pilha p, int x){
    p->v[p->topo] = x;
    p->topo++;
}

//desempilhar
int desempilhar(p_pilha p){
    p->topo--;
    return p->v[p->topo];
}

//balancear
int balancear(char *expressao){
    p_pilha p;
    int i, ok = 1;
    for(i = 0; ok && expressao[i] != '\0'; i++)
        if(expressao[i] == '(' || expressao[i] == '[')
            empilhar(p, expressao[i]);
        else if(pilha_vazia)
            ok = 0;
        else{
            char par = desempilhar(p);
            if(expressao[i] == '(' && par != ')')
                ok = 0;
            else if(expressao[i] == '[' && par != ']')
                ok = 0;
        }
    if(!pilha_vazia)
        ok = 0;

    return ok;
}