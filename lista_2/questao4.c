#include <stdio.h>

void determinante(int mat[3][3]){
    int principal, secundaria;
    principal = ((mat[0][0] * mat[1][1] * mat[2][2])
                + (mat[0][1] * mat[1][2] * mat[2][0]) 
                + (mat[0][2] * mat[1][0] * mat[2][1]));

    secundaria = ((mat[0][1] * mat[1][0] * mat[2][2]) 
                + (mat[0][0] * mat[1][2] * mat[2][0])
                + (mat[0][2] * mat[1][1] * mat[2][0]));

    printf("det = %d\n", principal - secundaria);
}

int main(){
    int matriz[3][3];
    printf("digite os elementos da matriz:\n");
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    determinante(matriz);

    return 0;
}