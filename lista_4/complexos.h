typedef struct {
    double real;
    double img;
} complexo;

/* a)*/
complexo inicializar (double a, double b);
/* b) */
complexo imprimir (complexo c);
/* c) */
complexo somar(complexo c1, complexo c2);
complexo multiplicar(complexo c1, complexo c2);
complexo subtrair (complexo c1, complexo c2);
complexo dividir(complexo c1, complexo c2);
complexo potencia (complexo c, int n);
/* d) */
int comparar (complexo c1, complexo c2);
/* e) */
complexo conjugado (complexo c);