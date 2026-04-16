#include <stdio.h>

int main(){

int vetor[5] = {1, 2, 3, 4, 5};
int *ponteiro;
ponteiro = vetor + 2;
ponteiro++;
printf("%d %d %d\n", *vetor, *(ponteiro - 1), *ponteiro);
    return 0;
}