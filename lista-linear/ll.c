#include "ll.h"

struct nodo {
    int info;
    struct nodo* prox;
};

Lista* Cria_lista() {
    return NULL;
}

Lista* Insere_elem(Lista* Ptl, int elem) {

    Lista* Ptnodo;
    Ptnodo = (Lista*) malloc(sizeof(Lista));

    // Não alocou o nodo corretamente
    if(Ptnodo == NULL) return Ptl;

    Ptnodo->info = elem;
    Ptnodo->prox = Ptl;

    return Ptnodo;
}

int Remove_elem(Lista** Ptl, int elem) {

    Lista *ant, *atual;

    if((*Ptl) == NULL) return 0;

    atual = *Ptl;

    while(atual != NULL && elem != atual->info) {

        ant = atual;
        atual = atual->prox;

    }

    // Não encontrou o elemento
    if(atual == NULL) return 0;

    if(atual == (*Ptl))
        *Ptl = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual);
    return 1;
}

int Consulta_nodo(Lista* Ptl, int pos, int *elem) {

    int count = 1;
    Lista* pt;
    pt = Ptl;

    // Posição inválida ou lista vazia
    if(pos <= 0 || pt == NULL) return 0;

    while(pt != NULL && count < pos) {
        pt = pt->prox;
        count++;
    }

    // Não encontrou nodo
    if(pt == NULL) return 0;
    // Nodo encontrado
    else{
        *elem = pt->info;
        return 1;
    }
}

int Tamanho_lista(Lista* Ptl) {

    int tamanho = 0;

    while(Ptl != NULL) tamanho++;

    if(Ptl == NULL) return tamanho;
    else return (-1);

}

int E_Vazia(Lista* Ptl){
    return (Ptl == NULL);
}

void Libera_lista(Lista* Ptl) {

    Lista* atual;
    while(Ptl != NULL) {

        atual = Ptl;
        Ptl = Ptl->prox;
        free(atual);

    }

    free(atual);

}

Lista* Consulta_rec(Lista* Ptl, int elem) {

    if(Ptl == NULL) return NULL;
    if(Ptl->info == elem) return Ptl;

    return Consulta_rec(Ptl->prox, elem);
}

Lista* Consulta(Lista* Ptl, int elem) {

    while(Ptl != NULL) {
        if(Ptl->info == elem) return Ptl;
    }

    return NULL;

}
