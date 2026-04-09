#include <stdio.h>
#include <string.h>

int main(){
    int idade, acompanhado;
    char classificacao[30];
    scanf("%d", &idade);
    scanf("%s", classificacao);
    scanf("%d", &acompanhado);

    if(strcmp(classificacao, "livre" == 0)){
        printf("sim\n");
    }
    else if(strcmp(classificacao, "violento") != 0 && idade >= 14){
        printf("sim\n");
    }
    else if(acompanhado && !(idade < 14)){
        printf("sim\n");
    }
    else if(idade >= 16){
        printf("sim\n");
    }
    else{
        printf("não\n");
    }

    return 0;
}