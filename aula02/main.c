#include <stdio.h>
#include <stdlib.h>

// AULA 02 - RECURSIVIDADE

float fatorial(int n){

    if(n <= 1) return 1;

    return n*fatorial(n-1);

}


float somatorio(int n){

    if(n <= 1) return n;

    return n + somatorio(n-1);

}

float fibonacci(int n){

    if(n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);



}

double fibonacciIterativo(int pos) {

    int i;
    double sum, ant = 1, prox = 1;

    for(i = 3; i<pos+1; i++) {
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

void binario(int n) {

    if(n <= 1) printf("%d", n);
    else {

        binario(n/2);
        printf("%d", n%2);

    }

}


int main()
{
    int m, n, opt;

    printf("------------------ AULA 02 - RECURSIVIDADE ------------------\n\n");

    do {

        printf("(1) Fatorial\n");
        printf("(2) Somatorio\n");
        printf("(3) Fibonacci\n");
        printf("(4) Fibonacci iterativo\n");
        printf("(5) Somatorio dos quadrados\n");
        printf("(6) Exponenciacao\n");
        printf("(7) Contagem regressiva\n");
        printf("(8) Conversao binario decimal\n");
        printf("(0) Sair\n\n");

        printf("Digite a opcao: ");
        scanf("%d", &opt);

        switch(opt) {

            case 1: // Fatorial

                printf("Digite um numero : ");
                scanf("%d", &n);

                printf("O fatorial de %d e %.f\n\n", n, fatorial(n));

                break;

            case 2: // Somatorio

                printf("Digite um numero : ");
                scanf("%d", &n);

                printf("O somatorio de %d e %.f\n\n", n, somatorio(n));


                break;

            case 3: // Fibonacci

                printf("Digite um numero : ");
                scanf("%d", &n);

                printf("O elemento %d na seq. de fibonacci e %.f\n\n", n, fibonacci(n));

                break;

            case 4: // Fibonacci iterativa

                printf("Digite um numero : ");
                scanf("%d", &n);

                printf("O elemento %d na seq. de fibonacci e %.f\n\n", n, fibonacciIterativo(n));

                break;

            case 5: // Somatorio dos quadrados

                printf("[inicio] :");
                scanf("%d", &m);

                printf("[fim] :");
                scanf("%d", &n);

                printf("O somatorio dos quadrados e %.2f\n\n", somatorioQuadrado(m, n));

                break;

            case 6: // Exponenciacao

                printf("[base] :");
                scanf("%d", &m);

                printf("[expoente] :");
                scanf("%d", &n);

                printf("%d elevado a %d e %.2f\n\n", m, n, elevado(m, n));

                break;

            case 7: // Contagem regressiva

                printf("Digite um numero : ");
                scanf("%d", &n);

                regressiva(n);
                printf("\n\n");

                break;

            case 8: // Conversão binário

                printf("Digite um numero : ");
                scanf("%d", &n);

                binario(n);
                printf("\n\n");

                break;

        }


    } while (opt != 0);

    return 0;
}
