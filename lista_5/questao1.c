#include <stdio.h>
#include <stdlib.h>

// Questão 1. Veja o código: 

void f(int a, int b) { 
    int c = a;           //função só modifica os números localmente, não os trocando de forma permanente
    a = b; 
    b = c; 
}
 
void g(int *c, int n) {
    c = malloc(sizeof(int) * n);     //c é cópia do ponteiro. o malloc se perde → ninguém guarda esse endereço 
} 
void h(int *h) {
    *h = 100; 
} 

int main() {
    int a = 1, b = 2, c = 3; 
    int **d; 
    d = malloc(sizeof(int*)); 
    f(a, b); 
    g(d[1], 1);         // d só tem espaço para 1 ponteiro (d[0]). d[1] acessa memória inválida
    h(*d);              // *d nunca foi inicializado
    free(d); 
    printf("%d, %d, %d", a, c, d[1][1]); 

    return 0; 
} 

//(a) É possível determinar a saída do programa (ou parte dela)? Qual?
/* questão comentada no programa */ 
//(b) Existe memory leak? 
/* sim, pois a memória alocada em g não é liberada */

//(c) Modifique para que toda memória alocada seja liberada e a saída seja a esperada: 2, 3, 100.

void f(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void g(int **c, int n) {
    *c = malloc(sizeof(int) * n);
}

void h(int *h) {
    *h = 100;
}

int main() {
    int a = 1, b = 2, c = 3;
    int *d;

    f(&a, &b);   // troca de verdade
    g(&d, 1);    // aloca memória
    h(d);        // coloca 100

    printf("%d, %d, %d", a, c, d[0]);

    free(d);

    return 0;
}