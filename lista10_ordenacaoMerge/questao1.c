int busca_binaria(int *vetor, int esquerda, int direita, int numero) {
    int meio = (esquerda + direita)/2;
    if (esquerda > direita)
        return -1;
    if (vetor[meio] == numero)
        return meio;
    else if (vetor[meio] < numero)
        return busca_binaria(vetor, meio + 1, direita, numero);
    else
        return busca_binaria(vetor, esquerda, meio - 1, numero);
}

//meio: posicao do meio do vetor
//esquerda: posicao do inicio do vetor
//direita: posicao do final do vetor
//numero: numero a ser buscado
//retorna -1 quando o numero nao for encontrado, ou a posicao do numero caso seja encontrado