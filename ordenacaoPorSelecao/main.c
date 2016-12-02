#include <stdio.h>
#include <stdlib.h>

void gerarVetor(int* vetor, int tamanho) {

    int i;

    for(i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }

}

void imprimeVetor(int* vetor, int tamanho) {

    int i;
    for(i = 0; i < tamanho; i++){

        printf("  %d  ", vetor[i]);
        if(i != 0 && (i+1) % 10 == 0)
            printf("\n");
    }

}

int main() {

    int vetor[100];

    printf("Vetor gerado\n");
    printf("=======================================================\n\n");
    gerarVetor(&vetor, 100);
    imprimeVetor(&vetor, 100);

    printf("\n\nVetor ordenado\n");
    printf("=======================================================\n\n");
    int comparacoes = ordenacaoPorSelecao(&vetor, 100);
    imprimeVetor(&vetor, 100);

    printf("\n\nCOMPARACOES X = %d", comparacoes);

    return 0;

    return 0;
}
