#include <stdio.h>

int soma(int x, int y){
    return x + y;
}

int subtracao(int x, int y){
    return x - y;
}

int multipicacao(int x, int y){
    return x * y;
}

int divisao(int x, int y){
    return x/y;
}

int main(){
    int opcao, n1, n2;
    printf("escolha dois números para a operação: ");
    scanf("%d %d", &n1, &n2);

    printf("escolha um número entre 1 e 5, sendo:\n");
    printf("1. soma\n2. subtração\n3. multiplicação\n4. divisão\n5. sair do programa\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        soma(n1, n2);
        printf("\nsoma = %d\n", soma(n1, n2));
        break;

    case 2:
        subtracao(n1, n2);
        printf("\nsubtração = %d\n", subtracao(n1, n2));
        break;

    case 3:
        multipicacao(n1, n2);
        printf("\nproduto = %d\n", multipicacao(n1, n2));
        break;

    case 4:
        divisao(n1, n2);
        printf("\nquociente = %d\n", divisao(n1, n2));
        break;
    
    default:
        break;
    }


    return 0;
}