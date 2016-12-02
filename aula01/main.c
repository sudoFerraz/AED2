#include <stdio.h>
#include <stdlib.h>

// AULA 01 - COMPLEXIDADE DE ALGORITMOS

int Max(int* A, int n) {

    // COMPLEXIDADE: n-1
    int i, maior = A[0];

    for(i = 0; i<n; i++){

        if(A[i] > maior){
            maior = A[i];
        }

    }

    return maior;
}

void MaxMin(int *A, int n, int *max, int *min) {

    // COMPLEXIDADE: (3n-3)/2

    *max = A[0];
    *min = A[0];

    int i;

    for(i = 0; i<n; i++){

        if(A[i] > *max)
            *max = A[i];
        else if(A[i] < *min)
            *min = A[i];


    }

}

int main() {

    int *vetor, max, min;

    vetor = (int) malloc(sizeof(int)*4);

    vetor[0] = 10;
    vetor[1] = 9;
    vetor[2] = 7;
    vetor[3] = 9;

    MaxMin(vetor, 4, &max, &min);
    printf("max: %d min: %d", max, min);

    return 0;
}
