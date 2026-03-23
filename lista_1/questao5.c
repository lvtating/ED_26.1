#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);

    if((x % 3 == 0) && (x % 5 == 0)){
        printf("%d é divisível por 3 e 5 simultâneamente\n", x);
    } else {
        printf("%d NAO é divisível por 3 e 5 simultâneamente\n", x);
    }

    return 0;
}