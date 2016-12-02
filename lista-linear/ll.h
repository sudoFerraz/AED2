#include<stdio.h>
#include<stdlib.h>

typedef struct nodo Lista;


Lista* Cria_lista();
Lista* Insere_elem(Lista* Ptl, int elem);
int Remove_elem(Lista** Ptl, int elem);
int Consulta_nodo(Lista* Ptl, int pos, int *elem);
int Tamanho_lista(Lista* Ptl);
int E_vazia(Lista* Ptl);
void Libera_lista(Lista* Ptl);
Lista* Consulta_rec(Lista* Ptl, int elem);
