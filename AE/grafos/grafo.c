#include "grafo.h"
#include<stdio.h>

struct Info {
    char nome[50];
    char endereco[100];
    int status;
};

struct Grafo {
    int NumVertices;
    int NumArestas;
    TipoPeso **Mat;
    TipoInfo *infoVertices;
};

TipoGrafo* Cria_Grafo(int NVertices) {

    int i, k;
    TipoGrafo *Grafo;

    if(NVertices <= 0) return NULL;

    Grafo = (TipoGrafo*) malloc(sizeof(TipoGrafo));
    if(Grafo == NULL) return NULL;

    Grafo->infoVertices = (TipoInfo*) malloc(NVertices*sizeof(TipoInfo));
    if(Grafo->infoVertices == NULL) {
        free(Grafo);
        return NULL;
    }

    Grafo->Mat = (TipoPeso**) malloc(NVertices*sizeof(TipoPeso*));
    if(Grafo->Mat == NULL) {
        free(Grafo);
        return NULL;
    }

    for(i=0; i<NVertices; i++) {

        Grafo->Mat[i] = (TipoPeso*) calloc(NVertices, sizeof(TipoPeso));
        if(Grafo->Mat[i] == NULL) { /// Não conseguiu alocar a linha i da matriz

                free(&(Grafo->infoVertices[i]));
                for(k=0; k<i; k++) { /// Libera linhas previamente alocadas
                    free(Grafo->Mat[k]);
                }

                free(Grafo);
                return NULL;
        }

    }

    Grafo->NumVertices = NVertices;
    Grafo->NumArestas = 0;

    return Grafo;
}

int Insere_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso peso) {

    if(Grafo == NULL) return -1;

    if(Grafo->Mat[v1][v2] != 0 || peso == 0) return 0;

    Grafo->Mat[v1][v2] = peso;
    Grafo->NumArestas++;

    return 1;
}

int Existe_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2) {

    if(Grafo==NULL) return -1;
    if(Grafo->Mat[v1][v2]==0) return 0;

    else return 1;

}

int Retira_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2) {
    if(Grafo==NULL) return -1;

    if(Grafo->Mat[v1][v2]==0) return 0;

    Grafo->Mat[v1][v2] = 0;
    Grafo->NumArestas --;

    return 1;
}

int Consulta_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso *peso) {
    if(Grafo==NULL) return -1;

    if(Grafo->Mat[v1][v2]==0) return 0;

    *peso = Grafo->Mat[v1][v2];

    return 1;
}

void Mostra_Lista_Adjacentes(TipoGrafo* Grafo, TipoVertice v) {

    int i, cont = 0;

    if(Grafo == NULL)
        printf("\nGrafo inexistente.");
    else {

        printf("\nLista de vertices adjacentes a %4d: ", v);
        for(i=0; i < Grafo->NumVertices; i++) {

            if(Grafo->Mat[v][i] != 0) {
                printf("%4d", i);
                cont = 1;
            }

        }

        if(cont == 0) printf("\nO vertice %d nao possui vertices adjacentes.", v);
    }

}

void Mostra_Grafo(TipoGrafo* Grafo) {

    int i,j;

    if(Grafo == NULL || Grafo->NumArestas == 0) {
        printf("\nGRAFO NAO EXISTE OU NAO POSSUI ARESTAS.");
    }else {

        for(i=0; i<Grafo->NumVertices; i++) {
            printf("\nVERTICES ADJACENTES A %4d --- ", i);

            for(j = 0; j < Grafo->NumVertices; j++) {
                if(Grafo->Mat[i][j] != 0) {
                    printf("%4d", j);
                }
            }
        }

    }

}

TipoGrafo* Libera_Grafo(TipoGrafo* Grafo) {

    int i;
    if(Grafo == NULL) return NULL;

    for(i=0; i<Grafo->NumVertices; i++) {
        free(&(Grafo->infoVertices[i]));
        free(Grafo->Mat[i]);
    }

    free(Grafo->Mat);
    free(Grafo);
    Grafo = NULL;

    return Grafo;
}

int Gravar_Arquivo(TipoGrafo* Grafo) {

    int i,j;

    if(Grafo == NULL || Grafo->Mat == NULL) return -1;

    FILE *arquivo = fopen("data.txt", "w");
    if(arquivo == NULL) return 0;

    fprintf(arquivo, "%d\n", Grafo->NumVertices);

    for(i = 0; i<Grafo->NumVertices; i++) {
        for(j = 0; j<Grafo->NumVertices; j++) {
            fprintf(arquivo, "%d,%d,%d\n", i,j,Grafo->Mat[i][j]);
        }
    }

    for(i = 0; i<Grafo->NumVertices; i++) {
        fprintf(arquivo, "%s->%s\n", Grafo->infoVertices[i].nome, Grafo->infoVertices[i].endereco);
    }

    fclose(arquivo);

    return 1;
}

TipoGrafo* Ler_Arquivo() {

    int i,j;

    FILE* arquivo = fopen("data.txt", "r");
    if(arquivo == NULL) return -1;



}

void Mostrar_Vertices(TipoGrafo* Grafo) {


    int i;

    for(i=0; i<Grafo->NumVertices; i++) {
        if(Grafo->infoVertices[i].status == 1)
            printf("%d) %s : %s", i, Grafo->infoVertices[i].nome, Grafo->infoVertices[i].endereco);
    }

}

int Cadastrar_Vertice(TipoGrafo* Grafo, TipoInfo* info) {

    int i = 0;
    if(info == NULL) return -1;

    while(Grafo->infoVertices[i] != NULL) {
        if(i > Grafo->NumVertices) return 0; // Vetor de indices está cheio
        i++;
    }

    Grafo->infoVertices[i]->nome     = info->nome;
    Grafo->infoVertices[i]->endereco = info->endereco;
    Grafo->infoVertices[i]->status   = 1;

    return 1;
}

