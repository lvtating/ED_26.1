#include <stdio.h>
#include <stdlib.h>

void transposta(int **v, int n){
    int **t;
    
    t = malloc(n * sizeof(int *));
    if(t == NULL){
        printf("não há memória o suficiente\n");
        exit(1);
    }
    
    for(int i = 0; i < n; i++){
        t[i] = malloc(n * sizeof(int));
        if(t[i] == NULL){
            printf("não há memória o suficiente\n");
            exit(1);
        }
        
        for(int j = 0; j < n; j++){
            t[i][j] = v[j][i];
        }
    }
    
    
    //printar
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++){
        free(t[i]);
    }
    free(t);
}

int main(){
    int **v, n;

    scanf("%d", &n);
    v = malloc(n * sizeof(int *));
    if(v == NULL){
        printf("Não há memória o suficiente\n");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        v[i] = malloc(n * sizeof(int));
        if(v[i] == NULL){
            printf("Não há memória o suficiente\n");
            exit(1);
        }
        for(int j = 0; j < n; j++){
            scanf("%d", &v[i][j]);
        }
    }

    transposta(v, n);

    for(int i = 0; i< n; i++){
        free(v[i]);
    }

    free(v);

    return 0;
}