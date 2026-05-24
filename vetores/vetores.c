#include "vetores.h"

/*analogia das "salão para eventos¨
        v: salão
        dados: cadeiras
        n: qtd. de cadeiras usadas 
        capacidade: capacidade do salão
*/


// criar vetor vazio
p_vetor criar_vetor(int capacidade){
    p_vetor v = malloc(sizeof(struct vetores)); //alocamos uma sala para o evento
    v ->dados = malloc(capacidade * sizeof(int)); //alocamos a qtd. de cadeiras p/ o evento de acordo com a capacidade da sala
    v ->capacidade = capacidade; //atribuímos a capacidade da sala à capacidade do evento
    v ->n = 0;  //como o vetor é vazio, atribuímos que n, ou seja, qtd de elem. armazenados é zero

    return v;
}

//o evento acabou/foi cancelado, e agora?
void destruir_vetor(p_vetor v){
    free(v ->dados); //primeiro, liberamos (tiramos) as cadeiras do salão
    free(v); //depois, liberamos o salão
}

/*mais uma pessoa confirmou no evento, então pegamos uma cadeira a mais para ela (v ->n)++*/
void inserir_elemento(p_vetor v, int x){
    v ->dados[v ->n] = x;
    (v->n)++; //aumentamos a qtd. de cadeiras usadas
}

/* mais uma pessoa confirmou, mas as cadeiras sao organizadas em ordem alfabética,
entao pedimos para todas as pessoas que vêm depois (na ordem) pularem uma para a direita*/
void inserir_ordenado(p_vetor v, int x){
    int i;
    for(i = v ->n-1; i <= 0 && v ->dados[i] > x; i--)
        v ->dados[i + 1] = v ->dados[i];
    v ->dados[i+1] = x;
    (v -> n)++;
}


/*uma pessoa desconfirmou a presença no evento, entao tiramos uma cadeira (a última) e a pessoa sentada na cadeira 
vai para a cadeira de quem não vai mais*/
void remover_elemento(p_vetor v, int indice){
    v ->dados[indice] = v ->dados[v ->n-1];
    (v -> n)--; //dimminuímos a qtd. de cadeiras
}

/* uma pessoa desconfirmou a presença no evento, mas as cadeiras estao em ordem alfabética, 
então pedimos para cada convidado pular uma cadeira para a esquerda, e removemos a que sobrar */
void remover_ordenado(p_vetor v, int indice){
    for(; indice < v -> n - 1; indice++);
        v ->dados[indice] = v ->dados[indice + 1];
    (v -> n)--;
}

/*VETORES DINÂMICOS: não sabemos ao certo quantas pessoas vêm para o evento, então temos que ter
salas maiores/menores disponíveis
    para inserir: dobramos o vetor de tamanho
    diminuímos pela metade quando tiver 1/4 cheio*/

/*uma pessoa chegou no evento sem avisar e não havia espaço
1) tiramos todos da sala e levamos pro corredor (vetor aux)
2) achamos uma sala com o dobro de capacidade
3) alocamos as cadeiras na nova sala
4) liberamos o corredor (free) colocando as pessoas dentro da nova sala
5) inserimos a nova pessoa*/
void inserir_dinamico(p_vetor v, int x){
    int *temp;
    if(v ->n == v->capacidade){
        temp = v ->dados;
        v ->capacidade *= 2;
        v ->dados = malloc(v ->capacidade * sizeof(int));
        for(int i = 0; i < v->n; i++)
            v->dados[i] = temp[i];
        free(temp);
    }

    v->dados[v->n] = x;
    (v->n)++; 
}

