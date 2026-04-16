//cliente complexos.c

#include <stdio.h>
#include "complexos.h"

int main(){
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    complexo z1 = inicializar(a, b);
    complexo z2 = inicializar(c, d);

    printf("z1: "); imprimir(z1);
    printf("z2: "); imprimir(z2);

    complexo soma = somar(z1, z2);
    printf("soma: "); imprimir(soma);
    
    complexo sub = subtrair(z1,z2);
    printf("diferença: "); imprimir(sub);

    complexo div = dividir(z1, z2);
    printf("divisão: "); imprimir(div);

    complexo mult = multiplicar(z1, z2);
    printf("multiplicação: "); imprimir(mult);

    complexo conj1 = conjugado(z1);
    complexo conj2 = conjugado(z2);
    printf("conjugado 1: "); imprimir(conj1);
    printf("conjugado 2: "); imprimir(conj2);

    return 0;
}