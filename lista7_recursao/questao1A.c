/*Crie um algoritmo recursivo que calcule a n-ésima potência de um número.*/

#include <stdio.h>

double potencia(double a, int n) {
    if (n == 0)
        return 1;
    else
        return a * potencia(a, n - 1);
}

int main() {
    double a;
    int n;

    printf("Digite a base: ");
    scanf("%lf", &a);
    printf("Digite o expoente: ");
    scanf("%d", &n);

    double resultado = potencia(a, n);
    printf("%.2lf elevado a %d é %.2lf\n", a, n, resultado);

    return 0;
}