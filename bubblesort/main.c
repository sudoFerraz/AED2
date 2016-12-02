#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void gerarVetor(int* vetor, int tamanho) {

    int i;

    for(i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10;
    }

}

int bubbleSort(int* vetor, int tamanho) {

    int i, j, aux;
    int k = tamanho-1;

    int comparacoes = 0;

    for(i = 0; i < tamanho; i++) {

        for(j = 0; j < k; j++) {

            comparacoes++;

            if(vetor[j] > vetor[j+1]) {

                aux        = vetor[j];
                vetor[j]   = vetor[j+1];
                vetor[j+1] = aux;

            }

        }

        k--;
    }

    return comparacoes;

}

int bubbleSortMaster(int* vetor, int tamanho) {

    int i, j, aux, comparacoes;
    int k = tamanho-1;


    for(i = 0; i < tamanho; i++) {

        int troca = 0;

        for(j = 0; j < k; j++) {

            comparacoes++;

            if(vetor[j] > vetor[j+1]) {

                aux        = vetor[j];
                vetor[j]   = vetor[j+1];
                vetor[j+1] = aux;
                troca = 1;

            }

        }


        k--;

        if(troca == 0)
            return comparacoes;
    }

    return comparacoes;
}

int bubbleSortRuim(int* vetor, int tamanho) {

    int i, j, aux;
    int k = tamanho-1;

    int comparacoes = 0;

    for(i = 0; i < tamanho; i++) {

        for(j = 0; j < tamanho-1; j++) {

            comparacoes++;

            if(vetor[j] > vetor[j+1]) {

                aux        = vetor[j];
                vetor[j]   = vetor[j+1];
                vetor[j+1] = aux;

            }

        }
    }

    return comparacoes;

}

void imprimeVetor(int* vetor, int tamanho) {

    int i;
    for(i = 0; i < tamanho; i++){

        printf(" [%d]  ", vetor[i]);
        if(i != 0 && (i+1) % 10 == 0)
            printf("\n");
    }

}

int ordenacaoPorSelecao(int* vetor, int tamanho) {

    int i, j, min, temp, comparacoes = 0;

    for(i=0; i < tamanho-1; i++) {

        min = i;

        for(j = (i+1); j < tamanho; j++) {

            if(vetor[j] < vetor[min])
                min = j;
            comparacoes++;
        }

        temp = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = temp;

    }

    return comparacoes;
}

int ordenacaoPorInsercao(int* vetor, int tamanho) {
    int i, j, aux, comparacoes = 0;

    for(i = 1; i < tamanho; i++) {
        j = i;

        while(j != 0) {

            comparacoes++;

            if(vetor[j] < vetor[j-1]){
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
            }

            j--;
        }
    }

    return comparacoes;
}


int main()
{
    int vetor[100];
    int opt, comparacoes;

    do{

        printf("\n1. Bubble Sort");
        printf("\n2. Bubble Sort Master");
        printf("\n3. Bubble Sort Master Blaster");
        printf("\n4. Ordenacao por selecao");
        printf("\n5. Ordenacao por insercao");
        printf("\n0. Sair");

        printf("\nDigite uma opcao: ");
        scanf("%d", &opt);


        switch(opt) {

            case 1: // Bubble sort
                gerarVetor(&vetor, 100);
                comparacoes = bubbleSortRuim(&vetor, 100);

                imprimeVetor(&vetor, 100);
                printf("\nCOMPARACOES = %d", comparacoes);
                break;

            case 2: // Bubble sort master
                gerarVetor(&vetor, 100);
                comparacoes = bubbleSort(&vetor, 100);

                imprimeVetor(&vetor, 100);
                printf("\nCOMPARACOES = %d", comparacoes);

                break;

            case 3: // Bubble sort master blaster
                gerarVetor(&vetor, 100);
                comparacoes = bubbleSortMaster(&vetor, 100);

                imprimeVetor(&vetor, 100);
                printf("\nCOMPARACOES = %d", comparacoes);

                break;

            case 4: // Ordenacao por selecao
                gerarVetor(&vetor, 100);
                comparacoes = ordenacaoPorSelecao(&vetor, 100);

                imprimeVetor(&vetor, 100);
                printf("\nCOMPARACOES = %d", comparacoes);

                break;

            case 5: // Ordenacao por selecao
                gerarVetor(&vetor, 100);
                comparacoes = ordenacaoPorInsercao(&vetor, 100);

                imprimeVetor(&vetor, 100);
                printf("\nCOMPARACOES = %d", comparacoes);

                break;
        }

    }while(opt != 0);

    return 0;
}
