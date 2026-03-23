#include <stdio.h>
#define max 50

void produto(int m1[][max], int m2[][max], int l1, int c1, int l2, int c2){
    /*a matriz resultante será de dimensão l1xc2*/
    int resultante[max][max];

    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c2; j++){
            resultante[i][j] = 0;

            for(int k = 0; k < c1; k++){
                resultante[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    printf("produto das matrizes:\n");
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c2; j++){
            printf("%d ", resultante[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int mat1[max][max], mat2[max][max];
    int l1, col1, l2, col2;

    /*dados matriz 1*/
    printf("digite o número de linhas e colunas da matriz 1: ");
    scanf("%d %d", &l1, &col1);
    printf("digite os elementos da matriz:\n");
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < col1; j++){
            scanf("%d", &mat1[i][j]);
        }
    }

    /*dados matriz 2*/ 
    printf("digite o número de linhas e colunas da matriz 2: ");
    scanf("%d %d", &l2, &col2);
    printf("digite os elementos da matriz:\n");
    for(int i = 0; i < l2; i++){
        for(int j = 0; j < col2; j++){
            scanf("%d", &mat2[i][j]);
        }
    }

    if(col1 != l2){
        printf("não é possível calcular o produto das matrizes");
    } else {
        produto(mat1, mat2, l1, col1, l2, col2);
    }


    return 0;
}