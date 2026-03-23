#include <stdio.h>
#include <string.h>

int main(){
    char num[50];
    scanf(" %s", num);
    getchar();

    int tamanho = strlen(num);
    char inversa[tamanho];
    //cont para garantir que a troca comece com o início de 'inversa' ([0])
    int cont = 0;

    //for para inverter os numeros: colocando o ultimo valor de 'num' no início de 'inversa', e assim em diate
    for(int i = tamanho - 1; i >= 0; i--){
        inversa[cont] = num[i];
        cont++;
    }


    int palindromo = 1;

    //for para ir comparando número por número de 'num' e 'inversa'
    for(int i = 0; i < tamanho; i++){
        if(num[i] != inversa[i]){ // se forem diferentes, o loop já quebra
            palindromo = 0;
            break;
        } else {
            continue; // se não, continua
        }
    }
    
    if(palindromo == 1){
        printf("é palíndromo\n");
    } else {
        printf("não é palíndromo\n");
    }

    return 0;
}