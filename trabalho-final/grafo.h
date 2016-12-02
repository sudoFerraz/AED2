#include<stdio.h>
#include<stdlib.h>

typedef int TipoPeso;
typedef int TipoVertice;
typedef struct Grafo TipoGrafo;

TipoGrafo* Cria_Grafo(int NVertices);
int Insere_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso peso);
int Retira_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2);
void Mostra_Grafo(TipoGrafo* Grafo);
TipoGrafo* Ler_Arquivo();
int Gravar_Arquivo(TipoGrafo* Grafo);
void Caminho_mais_Curto(TipoGrafo *grafo, int origem, int destino);
