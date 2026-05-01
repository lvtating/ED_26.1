 void merge(int *v, int esq, int meio, int dir) {
    int aux[50]; // podia ter feito alocação dinâmica
    int i = esq, j = meio + 1, k = 0;
    // intercala
    while (i <= meio && j <= dir)
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    // copia o resto do subvetor que não terminou
    while (i <= meio)
        aux[k++] = v[i++];
    while (j <= dir)
        aux[k++] = v[j++];
    // copia de volta para v
    for (i = esq, k = 0; i <= dir; i++, k++)
        v[i] = aux[k];
 }