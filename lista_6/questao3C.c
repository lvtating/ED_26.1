#include <stdio.h>
#include <stdlib.h>

void multiplicacao(int **p, int **a, int n){
    int **m;
    m = malloc(n * sizeof(int *));

    if(m == NULL){
        printf("não há memória o suficiente\n"); 
        exit(1);
    }
    
//achar o 1 de P
    for(int i = 0; i < n; i++){
        m[i] = malloc(n * sizeof(int));
        int colunaComUm = -1;
        
        for(int k = 0; k < n; k++){
            if(p[i][k] == 1){
                colunaComUm = k;
                break;
            }
        }
        
        for(int j = 0; j < n; j++){
            m[i][j] = a[colunaComUm][j];
        }
    }
    
//impressão

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < n; i++){
        free(m[i]);
    }
    free(m);
}

int main(){
    int **p, **a;
    int n;

    scanf("%d", &n);

//matriz P
    p = malloc(n * sizeof(int *));
    if(p == NULL){
        printf("não há memória o suficiente\n");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        p[i] = malloc(n * sizeof(int));
        if(p[i] == NULL){
            printf("não há memória o suficiente\n");
            exit(1);
        }
//identidade
        for(int j = 0; j < n; j++){
            if(i == j){
                p[i][j] = 1;
            } else {
                p[i][j] = 0;
            }
        }
    }

//matriz A
    a = malloc(n * sizeof(int *));
    if(a == NULL){
        printf("não há memória o suficiente\n");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        a[i] = malloc(n * sizeof(int));
        if(a[i] == NULL){
            printf("não há memória o suficiente\n");
            exit(1);
        }
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    multiplicacao(p, a, n);
    
    for(int i = 0; i < n; i++){
        free(p[i]);
        free(a[i]);
    }
    free(p);
    free(a);

}