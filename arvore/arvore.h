#include <stdio.h>
#include <stdlib.h>

typedef struct nodo AB;

AB* Cria_Arvore();
int Cria_Raiz(AB** Ptab, char item);
int Busca(AB* Ptab, char item, AB** pt);
void Imprime_Nodo(AB* nodo);
int Inserir_Filho_Esquerda(AB* pai, char item);
int Inserir_Filho_Direita(AB* pai, char item);
void Pre_Ordem(AB* Ptab);
void Pos_Ordem(AB* Ptab);
void Em_Ordem(AB* Ptab);
int Remove_Folha(AB** Ptab, char item);
void Localiza_Pai(AB* Ptab, char item, AB **pt, AB **pai);
AB* Libera_Arvore(AB *Ptab);
void Maior_Elemento(AB* Ptab, char *maior);
void Descendentes(AB* Ptab);
int Estritamente_Binaria(AB* Ptab);
int Altura(AB* Ptab);
