#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

clock_t tempoInicial;

void geraCrescente(int* vetor) {

    geraAleatorio(vetor);

    int i,j;

    for(i = SIZE-1; i >= 1; i--) {
        for(j = 0; j < i; j++) {

            if(vetor[j] > vetor[j+1]) {

                int temp = vetor[j];
                vetor[j]   = vetor[j+1];
                vetor[j+1] = temp;

            }

        }
    }

}

void geraDecrescente(int* vetor) {

    geraAleatorio(vetor);

    int i,j;

    for(i = SIZE-1; i >= 1; i--) {
        for(j = 0; j < i; j++) {

            if(vetor[j] < vetor[j+1]) {

                int temp = vetor[j];
                vetor[j]   = vetor[j+1];
                vetor[j+1] = temp;

            }

        }
    }
}

void geraAleatorio(int* vetor) {

    int i;

    for(i = 0; i < SIZE; i++) {
        vetor[i] = rand() % 451;
    }

}

void startCounter() {

    tempoInicial = clock();

}

double getCounter() {

    clock_t tempoFinal = clock();
    double tempoGasto = (double) (tempoFinal-tempoInicial) / CLOCKS_PER_SEC;

    return tempoGasto;
}

void bubble(int* vetor, int* comparacoes, double* tempoExecucao) {

    startCounter();
    int i,j;

    *comparacoes = 0;

    for(i = SIZE-1; i >= 1; i--) {
        for(j = 0; j < i; j++) {

            *comparacoes = *comparacoes + 1;
            if(vetor[j] > vetor[j+1]) {

                int temp = vetor[j];
                vetor[j]   = vetor[j+1];
                vetor[j+1] = temp;

            }

        }
    }

    *tempoExecucao = getCounter();

}

void quick(int* vetor, int* comparacoes, double* tempoExecucao) {

    *comparacoes = 0;
    startCounter();
    quick_ordena(vetor, 0, SIZE-1, comparacoes);

    *tempoExecucao = getCounter();

}

void quick_ordena(int* vetor, int esq, int dir, int* comparacoes) {

    int i, j;
    quick_particao(vetor, esq, dir, &i, &j, comparacoes);

    (*comparacoes)++;
    if(esq < j){
        quick_ordena(vetor, esq, j, comparacoes);
    }

    (*comparacoes)++;
    if(i < dir) {
        quick_ordena(vetor, i, dir, comparacoes);
    }

}

void quick_particao(int* vetor, int esq, int dir, int* i, int* j, int* comparacoes) {

    int x, aux;
    *i = esq;
    *j = dir;

    x = vetor[(*i+*j)/2];

    do {

        while(vetor[*i] < x)
            (*i)++;
        while(vetor[*j] > x)
            (*j)--;

        (*comparacoes)++;
        if((*i) <= (*j)) {

            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;

            (*i)++;
            (*j)--;
        }

    } while(*i <= *j);

}

void insercao(int* vetor, int* comparacoes, double* tempoExecucao) {


    startCounter();

    int i, j, temp;
    *comparacoes = 0;

    for(i=1;i<SIZE;i++) {

        temp = vetor[i];
        j = i-1;

        while (j >=0 && vetor[j] > temp) {
            vetor[j+1] = vetor[j];
            j--;
            (*comparacoes)++;
        }

        vetor[j+1] = temp;
    }

    *tempoExecucao = getCounter();

}

void selecao(int* vetor, int* comparacoes, double* tempoExecucao) {

    startCounter();

    int i, j, min, temp;

    *comparacoes = 0;

    for(i=0; i<SIZE-1;i++) {

        min = i;

        for (j=i+1; j<SIZE;j++) {

            *comparacoes = *comparacoes+1;
            if (vetor[j] < vetor[min])
                min = j;

        }

        temp = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = temp;
    }

    *tempoExecucao = getCounter();

}

void imprime(int* vetor) {

    int i;
    for(i = 0; i < SIZE; i++){

        printf(" [%d]  ", vetor[i]);
        if(i != 0 && (i+1) % 10 == 0)
            printf("\n");
    }

}

int main()
{
    int vetor[SIZE], opt, comparacoes = 0;
    double tempoExecucao = 0;

    do {

        printf("\n================== ORDENAÇÃO ===================");
        printf("\n 1. GERAR VETOR ALEATORIO");
        printf("\n 2. GERAR VETOR CRESCENTE");
        printf("\n 3. GERAR VETOR DECRESCENTE");
        printf("\n 4. BUBBLE SORT");
        printf("\n 5. QUICK SORT");
        printf("\n 6. ORDENAÇÃO POR INSERÇÃO");
        printf("\n 7. ORDENAÇÃO POR SELEÇÃO");
        printf("\n 8. IMPRIMIR VETOR ATUAL");
        printf("\n 0. SAIR");
        printf("\n======== Gere um vetor antes de ordenar ========");
        printf("\n\n Digite uma opção: ");
        scanf("%d", &opt);

        switch(opt) {

            case 1: // Gerar aleatório
                geraAleatorio(&vetor);
                break;

            case 2: // Gerar crescente
                geraCrescente(&vetor);
                break;

            case 3: // Gerar decrescente
                geraDecrescente(&vetor);
                break;

            case 4: // Bubble sort
                bubble(&vetor, &comparacoes, &tempoExecucao);
                printf("\nNumero de comparacoes: %d", comparacoes);
                printf("\nTempo de execucao: %.4f segundos", tempoExecucao);
                break;

            case 5: // Quick sort
                quick(&vetor, &comparacoes, &tempoExecucao);
                printf("\nNumero de comparacoes: %d", comparacoes);
                printf("\nTempo de execucao: %.4f segundos", tempoExecucao);
                break;

            case 6: // Inserção
                insercao(&vetor, &comparacoes, &tempoExecucao);
                printf("\nNumero de comparacoes: %d", comparacoes);
                printf("\nTempo de execucao: %.4f segundos", tempoExecucao);
                break;

            case 7: // Seleção
                selecao(&vetor, &comparacoes, &tempoExecucao);
                printf("\nNumero de comparacoes: %d", comparacoes);
                printf("\nTempo de execucao: %.4f segundos", tempoExecucao);
                break;

            case 8:
                printf("\n\n");
                imprime(&vetor);
                break;

        }

    } while(opt != 0);


    return 0;
}
