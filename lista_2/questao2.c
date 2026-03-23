#include <stdio.h>

int ehSimetrica(int i, int j){
    if(i == j)
        return 1;

    return 0;
}

int main(){
    int linhas, colunas;
    printf("digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    if(ehSimetrica(linhas, colunas)){
        printf("a matriz %dx%d é simétrica\n", linhas, colunas);
    } else {
        printf("a matriz %dx%d NÃO é simétrica\n", linhas, colunas);
    }

    return 0;
}