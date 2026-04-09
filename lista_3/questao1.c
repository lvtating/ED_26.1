#include <stdio.h>
#include <string.h>

#define max 50

int main(){
    char url[max];
    char delimitador;
    scanf(" %s", url);
    scanf(" %c", &delimitador);

    for(int i = 0; url[i] != '\0'; i++){
        if(url[i] == delimitador){
            break;
        }
        printf("%c", url[i]);
    }
    printf("\n");

    return 0;
}