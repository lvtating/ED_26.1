#include <stdio.h>
#include <string.h>

int main(){
    char string[100];
    scanf(" %[^\n]", string);

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32;
        } 
        else if (string[i] >= 'a' && string[i] <= 'z'){
            string[i] = string[i] - 32;
        }
    }

    printf("%s\n", string);

    return 0;
}