#include <stdio.h>
#include <math.h>
#include "complexos.h"

typedef struct {
    double real;
    double img;
} complexo;

/* a) inicializar complexo */
complexo inicializar (double a, double b){
    complexo c;
    c.real = a;
    c.img = b;

    return c;
}

/* b) imprimir */
complexo imprimir (complexo c){
    if(c.img >= 0){
        printf("%.2lf + %.2lf\n", c.real, c.img);
    } else {
        printf("%.2lf - %.2lf\n", c.real, -c.img);
    }
}


/* c) operações */
        complexo somar(complexo c1, complexo c2){
            return (inicializar(c1.real + c2.real, c1.img + c2.img));
        }

        complexo multiplicar(complexo c1, complexo c2){
            //(a + bi) * (c + di) = (ac - bd) + (bc + ad)i
            double r = (c1.real * c2.real) - (c1.img * c2.img);
            double i = (c1.img * c2.real) + (c1.real * c2.img);

            return (inicializar(r, i));
        }

        complexo subtrair (complexo c1, complexo c2) {
            return (inicializar(c1.real - c2.real, c1.img - c2.img));
        }

        complexo dividir(complexo c1, complexo c2){
            double denominador = pow(c2.real, 2) + pow(c2.img, 2);
            if(denominador == 0){
                printf("Erro: divisão por zero não definida!\n");
                return (inicializar (0, 0));
            }

            double r = (c1.real * c2.real) + (c1.img * c2.img) / denominador;
            double i = (c1.img * c2.real) - (c1.real * c2.img) / denominador;
            return (inicializar (r, i));
        }

        complexo potencia (complexo c, int n){
            if(n == 0){
                return (inicializar(1,0));
            }
            complexo resultado = c;
            for(int i = 0; i < n; i++){
                resultado = multiplicar(resultado, c);
            }
            return resultado;
        }


/* d) comparar números */
int comparar (complexo c1, complexo c2){
    return(c1.real == c2.real && c1.img == c2.img);
}

/* e) obter conjugado */
complexo conjugado (complexo c){
    return (inicializar (c.real, - c.img));
}

int main(){
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    complexo z1 = inicializar(a, b);
    complexo z2 = inicializar(c, d);

    printf("z1: "); imprimir(z1);
    printf("z2: "); imprimir(z2);

    complexo soma = somar(z1, z2);
    printf("soma: "); imprimir(soma);
    
    complexo sub = subtrair(z1,z2);
    printf("diferença: "); imprimir(sub);

    complexo div = dividir(z1, z2);
    printf("divisão: "); imprimir(div);

    complexo mult = multiplicar(z1, z2);
    printf("multiplicação: "); imprimir(mult);

    complexo conj1 = conjugado(z1);
    complexo conj2 = conjugado(z2);
    printf("conjugado 1: "); imprimir(conj1);
    printf("conjugado 2: "); imprimir(conj2);

    return 0;
}