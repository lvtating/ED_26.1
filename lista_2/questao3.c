#include <stdio.h>
#define MAX 50

void transposta(int matriz[MAX][MAX], int linhas, int colunas){
    int resultado[MAX][MAX];

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
         resultado[j][i] = matriz[i][j];  
        }
    }

    printf("matriz transposta:\n");
    for(int i = 0; i < colunas; i++){
        for(int j = 0; j < linhas; j++){
            printf("%d", resultado[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int linhas, colunas, valor[MAX][MAX];
    printf("digite o número de linhas: ");
    scanf("%d", &linhas);

    printf("digite o número de colunas: ");
    scanf("%d", &colunas);
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &valor[i][j]);
        }
    }

    transposta(valor, linhas, colunas);

    return 0;
}