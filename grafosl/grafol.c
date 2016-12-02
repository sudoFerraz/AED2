#include "grafol.h"

typedef struct {
    tipoVertice vertice;
    tipokm km;
}tipoInfo;

struct nodo{
    tipoInfo info;
    struct nodo *proximo;
};

struct grafo{
    int numVertices;
    int numArestas;
    struct nodo **mat; ///vetor de ponteiros para struct nodo;
};

tipoGrafo* criaGrafo(int nVertices)
{
    int j;
    tipoGrafo *grafo;

    if(nVertices <= 0) return NULL;

    grafo = (tipoGrafo*)malloc(sizeof(tipoGrafo));
    if(grafo == NULL) return NULL;

    grafo->numVertices = nVertices;
    grafo->numArestas = 0;

    grafo->mat = (struct nodo**)malloc(nVertices*sizeof(struct nodo*));
    if(grafo->mat == NULL)
    {
        free(grafo);
        return NULL;
    }
    for(j=0; j<nVertices; j++)
    {
        grafo->mat[j] = NULL;
    }
    return grafo;
}

int insereArestas(tipoGrafo *grafo, tipoVertice v1, tipoVertice v2, tipokm km)
{
    struct nodo *aux;

    if(grafo == NULL) return -1;
    strcpy(grafo->mat[v1],aux);

    while(aux != NULL && strcmp(aux->info.vertice,v2)){
            aux = aux->proximo;
    }

    if(aux != NULL) return 0;

    aux = (struct nodo*)malloc(sizeof(struct nodo));

    if(aux == NULL) return 0;

    strcpy(aux->info.vertice,v2);
    aux->info.km = km;
    aux->proximo = grafo->mat[v1];
    grafo->mat[v1] = aux;
    grafo->numArestas++;
    return 1;
}

int existeAresta(tipoGrafo *grafo, tipoVertice v1, tipoVertice v2)
{
    struct nodo *aux;
    if(grafo == NULL) return -1;

    aux = grafo->mat[v1];

    while(aux != NULL && strcmp(aux->info.vertice,v2))
    {
        aux = aux->proximo;
    }
    if(aux == NULL) return 0;
    else return 1;
}

int retiraAresta(tipoGrafo *grafo, tipoVertice v1, tipoVertice v2)
{
    struct nodo *p, *anterior;
    if(grafo == NULL) return -1;

    if(grafo->mat[v1] == NULL) return 0;
    p = grafo->mat[v1];

    while(p != NULL && strcmp(p->info.vertice,v2))
    {
       anterior = p;
       p = p->proximo;
    }

    if(p == NULL) return 0;
    else{
        if(anterior == NULL) ///remove a cabeça da lista
            grafo->mat[v1] = p->proximo;
        else{
            anterior->proximo = p->proximo;
            free(p);
            grafo->numArestas--;
            return 1;
            }
    }
}

void mostraGrafo(tipoGrafo *grafo)
{
    int i;
    struct nodo* p;

    if(grafo == NULL || grafo->numArestas == 0)
        printf("\ngrafo NAO EXISTE OU NAO POSSUI ARESTAS.");

    for(i=0; i<grafo->numVertices; i++)
    {
        printf("\n%c: ", i);
        p = grafo->mat[i];
        while(p != NULL){
            printf("%c - ", p->info.vertice);
            p = p->proximo;
        }
    }
}

void mostraListaAdjacentes(tipoGrafo *grafo, tipoVertice v)
{
    int cont = 0;
    struct nodo* p;
    p = grafo->mat[v];

    if(grafo == NULL)
        printf("\nGrafo Inexistente.");
    else{

        printf("\nLista de vertices adjacentes a %c: ",v);
        while(p != NULL){
            printf("%4c", p->info.vertice);
            cont = 1;
            p = p->proximo;
            }
    }
    if(cont == 0) printf("\nO vertice %c nao possui vertices adjacentes.", v);
}

int consultaAresta(tipoGrafo *grafo, tipoVertice v1, tipoVertice v2, tipokm *km)
{
    struct nodo* p;
    p = grafo->mat[v1];

    if(grafo==NULL) return -1;
    if(grafo->mat[v1] == NULL) return 0;
    p = grafo->mat[v1];

    while(p != NULL && strcmp(p->info.vertice,v2))
    {
        p = p->proximo;
    }

    if(p == NULL){
            return 0;
    }else{
        *km = p->info.vertice;
    }
    return 1;
}

tipoGrafo* liberaGrafo(tipoGrafo *grafo)
{
    int i;
    struct nodo *p, *aux;
    if(grafo == NULL) return NULL;

    for(i=0; i<grafo->numVertices; i++)
    {
        p = grafo->mat[i];
        while(p != NULL)
        {
            aux = p;
            p = p->proximo;
            free(aux);
        }
    }

    free(grafo->mat);
    free(grafo);

    return grafo;
}
