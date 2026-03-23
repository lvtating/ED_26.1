#include <stdio.h>
#include <stdlib.h>

#define MAX 8

int main(){
    int lista[MAX];
    printf("digite uma lista de 8 números: ");

    for(int i = 0; i <  MAX; i++){
    // for para ler os valores da lista
        scanf("%d", &lista[i]);
    }

    // assume o primeiro elemento como valores iniciais de menor e maior
    int maior = lista[0];
    int menor = lista[0];

    // for para pegar o menor e o maior valor, comparando com os valores assumidos
    for(int i = 0; i < MAX; i++){
        if(lista[i] > maior){
            maior = lista[i];
        }
        else if(lista[i] < menor){
            menor = lista[i];
        }
    }


    printf("maior: %d\nmenor: %d\n", maior, menor);
    printf("diferença absoluta = %d\n", abs(maior - menor));

    return 0;
}