#include "arvore.h"

struct nodo {
    struct nodo* esq;
    struct nodo* dir;
    char info;
};

AB* Cria_Arvore() {
    return NULL;
}

int Cria_Raiz(AB** Ptab, char item) {

    if(*Ptab != NULL) return 0;

    AB* novo = (AB*) malloc(sizeof(AB));

    if(novo != NULL) {
        novo->esq  = NULL;
        novo->dir  = NULL;
        novo->info = item;
    }

    *Ptab = novo;

    if(*Ptab == NULL) return 0;

    return 1;

}

void Imprime_Nodo(AB* nodo) {
    printf("%c", nodo->info);
}

int Busca(AB* Ptab, char item, AB** pt){

    if(Ptab == NULL || *pt != NULL) return 0;

    if(Ptab->info != item) {

        Busca(Ptab->esq, item, pt);
        if(*pt == NULL) Busca(Ptab->dir, item, pt);

    }else{
        *pt = Ptab;
    }

    return 1;
}

int Insere_Filho_Esquerda(AB* pai, char item){

    if(pai == NULL || pai->esq != NULL) return 0;

    AB* novo = (AB*) malloc(sizeof(AB));

    if(novo != NULL){
        novo->info = item;
        novo->esq  = NULL;
        novo->dir  = NULL;
    }else{
        return 0;
    }

    pai->esq = novo;
    return 1;

}

int Insere_Filho_Direita(AB* pai, char item){

    if(pai == NULL || pai->dir != NULL) return 0;

    AB* novo = (AB*) malloc(sizeof(AB));

    if(novo != NULL){
        novo->info = item;
        novo->esq  = NULL;
        novo->dir  = NULL;
    }else{
        return 0;
    }

    pai->dir = novo;
    return 1;

}

void Pre_Ordem(AB* Ptab) {

    if(Ptab != NULL) {
        printf(" [%c] ", Ptab->info);

        Pre_Ordem(Ptab->esq);
        Pre_Ordem(Ptab->dir);
    }

}

void Pos_Ordem(AB* Ptab) {

    if(Ptab != NULL) {
        Pos_Ordem(Ptab->esq);
        Pos_Ordem(Ptab->dir);

        printf(" [%c] ", Ptab->info);
    }

}

void Em_Ordem(AB* Ptab) {

    if(Ptab != NULL) {

        Em_Ordem(Ptab->esq);
        printf(" [%c] ", Ptab->info);
        Em_Ordem(Ptab->dir);

    }

}

int Remove_Folha(AB** Ptab, char item) {

    AB* pai, *ptnodo;

    if(*Ptab == NULL)
        return 0;

    if((*Ptab)->info == item) {

        if((*Ptab)->esq == NULL && (*Ptab)->dir == NULL) {

            free(*Ptab);
            *Ptab = NULL;
            return 1;

        }

    }else {

        ptnodo = NULL;
        pai = NULL;
        Localiza_Pai(*Ptab, item, &ptnodo, &pai);

        if(ptnodo == NULL)
            return 0;
        if(ptnodo->esq == NULL && ptnodo->dir == NULL) {

            if(pai->esq == ptnodo) {

                free(pai->esq);
                pai->esq = NULL;

                return 1;
            }else {

                free(pai->dir);
                pai->dir = NULL;

                return 1;
            }

        }else {
            return 0;
        }

    }

}

void Localiza_Pai(AB* Ptab, char item, AB **pt, AB **pai) {

    if(Ptab != NULL) {

        if(Ptab->esq != NULL && Ptab->esq->info == item) {

            *pt  = Ptab->esq;
            *pai = Ptab;

             return;
        }

        if(Ptab->dir != NULL && Ptab->dir->info == item) {

            *pt  = Ptab->dir;
            *pai = Ptab;

             return;
        }

        Localiza_Pai(Ptab->esq, item, pt, pai);
        if(*pt == NULL)
            Localiza_Pai(Ptab->dir, item, pt, pai);

    }else {
        return;
    }

}

AB* Libera_Arvore(AB *Ptab) {

    if(Ptab != NULL) {

        Libera_Arvore(Ptab->esq);
        Libera_Arvore(Ptab->dir);
        free(Ptab);

    }

    return NULL;
}

void Maior_Elemento(AB* Ptab, char *maior) {

    if(Ptab != NULL) {
        if(Ptab->info > *maior)
            *maior = Ptab->info;

        Maior_Elemento(Ptab->esq, maior);
        Maior_Elemento(Ptab->dir, maior);

    }

}


void Descendentes(AB* Ptab) {

    if(Ptab != NULL) {

        printf("%c ", Ptab->info);
        Descendentes(Ptab->esq);
        Descendentes(Ptab->dir);

    }

}

int Estritamente_Binaria(AB* Ptab) {

    if (Ptab == NULL)
        return 1;
    if ((Ptab->esq != NULL && Ptab->dir ==NULL) || (Ptab->esq == NULL && Ptab->dir != NULL))
        return 0;

    return (Estritamente_Binaria(Ptab->esq) && Estritamente_Binaria(Ptab->dir));

}

int Altura(AB* Ptab) {

    int max(int Esq, int Dir){
        if (Esq > Dir)
            return Esq;
        else return Dir;
    }


    if (Ptab == NULL)
        return 0;

    return(max(Altura(Ptab->esq),Altura(Ptab->dir))+1);
}
