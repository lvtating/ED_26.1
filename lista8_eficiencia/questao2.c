/*Sempre que o expoente é par, nós elevamos a base ao quadrado e dividimos o expoente por 2. 
Se for ímpar, apenas tiramos um da conta para ele ficar par e multiplicamos o resultado pela base.*/

#include <stdio.h>

double potencia_recursiva(double base, int expoente) {
    if (expoente == 0) return 1;

    // calcular a potência da metade: a^(n/2)
    double metade = potencia_recursiva(base, expoente / 2);

    if (expoente % 2 == 0) {
        // se expoente é par: (a^(expoente/2)) * (a^(expoente/2))
        return metade * metade;

    } else {
        // se expoente é ímpar: base * (a^(expoente/2)) * (a^(expoente/2))
        return base * metade * metade;
    }
}



/*imagine que você quer calcular 3¹³.
0 número 13 em binário é 1101, o que significa: 13 = 8 + 4 + 1.
então, 3¹³ = 3⁸ · 3⁴ · 3¹.*/

double potencia_iterativa(double base, int expoente) {
    double resultado = 1.0;
    double base_atual = base;

    while (expoente > 0) {
        // se o bit menos significativo de expoente for 1 (expoente é ímpar)
        if (expoente % 2 == 1) {
            resultado *= base_atual;
        }
        // eleva a base ao quadrado (prepara para o próximo bit)
        base_atual *= base_atual;
        // divide expoente por 2
        expoente /= 2;
    }

    return resultado;
}