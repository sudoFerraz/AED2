#include<stdio.h>
#include<stdlib.h>

typedef int TipoPeso;
typedef int TipoVertice;
typedef struct Grafo TipoGrafo;
typedef struct Info TipoInfo;

TipoGrafo* Cria_Grafo(int NVertices);
int Insere_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso peso);
int Existe_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2);
int Retira_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2);
int Consulta_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso *peso);
void Mostra_Lista_Adjacentes(TipoGrafo* Grafo, TipoVertice v);
void Mostra_Grafo(TipoGrafo* Grafo);
TipoGrafo* Libera_Grafo(TipoGrafo* Grafo);
int Gravar_Arquivo(TipoGrafo* Grafo);
TipoGrafo* Ler_Arquivo();
void Mostrar_Vertices(TipoGrafo* Grafo);
int Cadastrar_Vertice(TipoGrafo* Grafo, TipoInfo* info);
