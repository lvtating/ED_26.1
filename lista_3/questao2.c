#include <stdio.h>
#include <string.h>

int main(){
    char string[100];
    scanf(" %s", string);

    int tamanho = strlen(string);
    int cont = 0, max = 0;

    for(int i = 0; i < tamanho; i++){
        if(string[i] == '0'){
            cont++;

            if(cont > max){
                max = cont;
            } 
        } else {
            cont = 0;
        }
    }

    printf("%d\n", max);
    
    return 0;

}