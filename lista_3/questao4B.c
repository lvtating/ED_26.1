#include <stdio.h>
#include <string.h>

int main(){
    int idade, acompanhado;
    char classificacao[30];
    scanf("%d", &idade);
    scanf("%s", classificacao);
    scanf("%d", &acompanhado);

    if(!(strcmp(classificacao, "livre" == 0)) || 
    !(strcmp(classificacao, "violento") != 0 && idade >= 14) ||
    !(acompanhado && !(idade < 14)) || !(idade >= 16)){
        printf("não\n");
    } else {
        printf("sim\n");
    }

    return 0;
}