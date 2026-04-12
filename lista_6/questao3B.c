#include <stdio.h>
#include <stdlib.h>

void multiplicar(int **t, int **a, int n){
    int **m;
    m = malloc(n * sizeof(int *));
    if(m == NULL){
        exit(1);
    }
    
    for(int i = 0; i < n; i++){
        m[i] = malloc (n * sizeof(int));
        
        for(int j = 0; j < n; j++){
            m[i][j] = 0;
            
            for(int k = 0; k < n; k++){
                m[i][j] += t[i][k] * a[k][j];
            }
        }
    }
    
    //printar
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

void trocarEmultiplicar(int **p, int **a, int n) {
    int i_troca = 0; 
    int j_troca = 1;

    if (n > 1) {
        int *temp = p[i_troca];
        p[i_troca] = p[j_troca];
        p[j_troca] = temp;
    }

    multiplicar(p, a, n);
}


int main(){
    int **p, **a, n;
    scanf("%d", &n);
    
    //matriz A
    a = malloc(n * sizeof(int *));
    if(a == NULL){
        exit(1);
    }
    
    for(int i = 0; i < n; i++){
        a[i] = malloc(n * sizeof(int));
        
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    //matriz P
    p = malloc(n * sizeof(int *));
    if(p == NULL){ 
        exit(1); 
    }

    for(int i = 0; i < n; i++){
        p[i] = malloc(n * sizeof(int));

        for(int j = 0; j < n; j++){
            if(i == j){
                p[i][j] = 1;
            } else {
                p[i][j] = 0;
            }
        }
    }
    
    
        
    trocarEmultiplicar(p, a, n);
    
    for(int i = 0; i < n; i++){
        free(p[i]);
        free(a[i]);
    }
    free(p);
    free(a);
    
    return 0;

}