typedef struct vetores {
    int *dados;
    int n;
    int capacidade;

};

typedef struct vetores *p_vetor;

p_vetor criar_vetor(int capacidade);
void destruir_vetor(p_vetor v);
void inserir_elemento(p_vetor v, int x);
void inserir_ordenado(p_vetor v, int x);
void remover_elemento(p_vetor v, int indice);
void remover_ordenado(p_vetor v, int indice);

// VETORES DINÂMICOS
void inserir_dinamico(p_vetor v, int x);
