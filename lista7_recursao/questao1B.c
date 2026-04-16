/* Reescreva o algoritmo do item acima de forma iterativa. */

#include <stdio.h>

double potencia_iterativa(double a, int n){
    double resultado = 1;
    for(int i = 0; i < n; i++){
        resultado *= a;
    }
    return resultado;
}

int main() {
    double a;
    int n;

    printf("Digite a base: ");
    scanf("%lf", &a);
    printf("Digite o expoente: ");
    scanf("%d", &n);

    double resultado = potencia_iterativa(a, n);
    printf("%.2lf elevado a %d é %.2lf\n", a, n, resultado);

    return 0;
}