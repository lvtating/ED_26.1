#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} ponto;

int main() {
    ponto *v, centro;
    int n;
    scanf("%d", &n);

    v = malloc(n * sizeof(ponto));
    if(v == NULL){
        printf("Não há memória o suficiente\n");
        exit(1);
    }

    for (int i = 0; i < n; i++){
        scanf("%lf %lf", &v[i].x, &v[i].y);
        centro.x = centro.y = 0;
    }
    for(int i = 0; i < n; i++){
        centro.x += v[i].x/n;
        centro.y += v[i].y/n;
    }

    printf("Centroide: %lf %lf\n", centro.x, centro.y);
    free(v);
    
    return 0;
}