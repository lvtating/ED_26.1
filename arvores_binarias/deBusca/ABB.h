struct no {
    int chave;
    struct no *esq, *dir, *pai;
};
typedef struct no *p_no;

p_no buscar(p_no raiz, int chave);
p_no buscar_iterativa(p_no raiz, int chave);
p_no inserir(p_no raiz, int chave);
p_no minimo(p_no raiz);
p_no minimo_iterativa(p_no raiz);
p_no sucessor(p_no x);
p_no ancestral_a_direita(p_no x);
p_no remover_rec(p_no raiz, int chave);
void remover_sucessor(p_no raiz);
void imprime(p_no raiz);