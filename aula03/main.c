#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double fibonacci(int pos) {

    int i;
    double sum, ant = 1, prox = 1;

    for(i = 3; i<pos; i++) {
        sum = ant+prox;
        ant = prox;
        prox = sum;
    }

    return prox;


}

double somatorioQuadrado(int a, int b) {

    if(a > b) return 0;
    if(a < b) return a*a + somatorioQuadrado(a+1, b);

    return b*b;
}

double elevado(double base, int expoente) {

        if(expoente == 0) return 1;

        if(expoente > 0)
            return base * elevado(base, expoente-1);
        else
            return (1/base * elevado(base, expoente+1));

}

void regressiva(int n) {

    if(n == 0)
        printf("Fogo !");
    else {
        printf("%d...", n);
        regressiva(n-1);
    }

}

int main()
{
    int opt;
    int a, b;

    scanf("%d", &a);
    printf("%.2f", fibonacci(a));

    return 0;
}
