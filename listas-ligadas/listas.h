typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct No *p_no;

p_no criar_list_vazia();
void destruir_lista();
void destruir_iterativa();
p_no adicionar_elemento(p_no lista, int x);
p_no remover_elemento(p_no lista, int x);
void imprimindo_lista(p_no lista);
void imprimindo_iterativa(p_no lista);

p_no copiar_lista(p_no lista);
p_no copiar_iterativa(p_no lista);
p_no inverter(p_no lista);
p_no inverter_recursiva(p_no lista);
p_no concatenar(p_no primeira, p_no segunda);