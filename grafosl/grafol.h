#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float tipokm;
typedef struct{
    char endereco[150];
    char bairro[50];
    int tipo;
} tipoVertice;
typedef struct grafo tipoGrafo;

tipoGrafo* criaGrafo(int nVertices);
int insereArestas(tipoGrafo *grafo, tipoVertice v1, tipoVertice v2, tipokm km);
int existeAresta(tipoGrafo *grafo, tipoVertice v1, tipoVertice v2);
int retiraAresta(tipoGrafo *grafo, tipoVertice v1, tipoVertice v2);
void mostraGrafo(tipoGrafo* grafo);
void mostraListaAdjacentes(tipoGrafo* grafo, tipoVertice v);
int consultaAresta(tipoGrafo *grafo, tipoVertice v1, tipoVertice v2, tipokm *km);
tipoGrafo* liberaGrafo(tipoGrafo* grafo);
