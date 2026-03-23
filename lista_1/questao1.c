#include <stdio.h>

int ehPropriedade(int soma, int num){
   if(soma*soma == num)
      return 1;
   
   return 0;
}

int naoPropriedade(int soma, int num){
   return(!ehPropriedade(soma, num));
}

int main() {
   int n, numero1, numero2, soma;
   scanf("%d", &n);

   //pega o numero e divide por 100, para conseguir o numero1
   numero1 = n / 100;
   //o resto da divisao é o número2
   numero2 = n % 100;
   //soma dos dois numeros
   soma = numero1 + numero2;

   //chama a função que calcula a propriedade
   if(ehPropriedade(soma, n)){
      printf("o número %d possui a propriedade\n", n);
   } 
   else if (naoPropriedade(soma, n)){

      printf("o número %d NAO possui a propriedade\n", n);
   }
   
      
   return 0;
}


