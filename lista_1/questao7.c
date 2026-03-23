#include <stdio.h>
#include <string.h>

void intersecao(char v1[], char v2[], int n1, int n2){
    int encontrou = 0;

    printf("interseção: ");
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(v1[i] == v2[j] && v1[i] != ' ' && v1[i] != ','){
                printf("%c ", v1[i]);
                encontrou = 1;
                break;
            }
        }
    }

    printf("\n");
}

void uniao(char v1[], char v2[], int n1, int n2){
    printf("união: ");
    
// for para imprimir os elementos do conjunto 1
    for(int i = 0; i < n1; i++){
        if(v1[i] == ' ' || v1[i] == ','){
            continue;
        }

        printf("%c ", v1[i]);
    }
    
// imprimir elementos do conjunto 2 que não estão no conjunto 1
    for(int j = 0; j < n2; j++){
        
        if(v2[j] == ' ' || v2[j] == ','){
            continue;
        }

//verifica se o elemento já está em v1
        int emV1 = 0;
        for(int i = 0; i < n1; i++){
            if(v2[j] == v1[i]){
                emV1 = 1;
                break;
            }
        }

        if(emV1 == 0){
            printf("%c ", v2[j]);
        }
    }

    printf("\n");
}

void diferenca(char v1[], char v2[], int n1, int n2){
    printf("diferença: ");

// percorre v1
    for(int i = 0; i < n1; i++){
        if(v1[i] == ' ' || v1[i] == ','){
            continue;
        }
// verifica se o elemento está presente em v2. se não, ele é impresso
        int jaEmv2 = 0;
        for(int j = 0; j < n2; j++){
            if(v2[j] == ' ' || v2[j] == ',') continue;

            if(v1[i] == v2[j]){
                jaEmv2 = 1;
                break;
            }
        }

        if(!jaEmv2){
            printf("%c ", v1[i]);
        }
    }
    printf("\n");
}

int main(){
    char conjunto1[50], conjunto2[50];
    printf("digite o conjunto 1: ");
    scanf(" %[^\n]", conjunto1);
    int tamanho1 = strlen(conjunto1);

    printf("digite o conjunto 2: ");
    scanf(" %[^\n]", conjunto2);
    int tamanho2 = strlen(conjunto2);

    intersecao(conjunto1, conjunto2, tamanho1, tamanho2);
    uniao(conjunto1, conjunto2, tamanho1, tamanho2);
    diferenca(conjunto1, conjunto2, tamanho1, tamanho2);

    return 0;
}