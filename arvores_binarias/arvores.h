struct no {
    int dado;
    struct no *esq, *dir;
};

typedef struct no *p_no;

typedef struct {
    int *v;
    int topo;
} Pilha;

typedef struct {
    p_no ini, fim;
} Fila;
typedef Fila *p_fila;
enfileirar(p_fila f, int x);
desenfileirar(p_fila);

typedef Pilha *p_pilha;
p_pilha criar_pilha();
void empilhar(p_pilha p, int x);
int desempilhar(p_pilha p);
int pilha_vazia(p_pilha p);

p_no criar_arvore(int x, p_no esq, p_no dir);
p_no procurar_no(p_no raiz, int x);
int numero_nos(p_no raiz);
int altura(p_no raiz);