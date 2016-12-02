#include<stdio.h>
#include "avl.h"

struct nodoAVL {
    Registro reg;
    int FB;
    struct nodoAVL *esq;
    struct nodoAVL *dir;
};

void Incializa_AVL(AVL** Ptavl) {
    *Ptavl = NULL;
}

int E_Vazia(AVL* Ptavl) {

    if(Ptavl == NULL) return 1;
    else return 0;

}

AVL* Pesquisa_AVL(AVL* Ptavl, int chave) {

    if(Ptavl == NULL) return NULL;

    if(chave == Ptavl->reg.Chave) return Ptavl;
    else if(chave < Ptavl->reg.Chave) return Pesquisa_AVL(Ptavl->esq, chave);
    else return Pesquisa_AVL(Ptavl->dir, chave);

}

void Exibe_Arvore(AVL* Ptavl) {

    if(Ptavl != NULL) {
        Exibe_Arvore(Ptavl->esq);
        printf("%4d", Ptavl->reg.Chave);
        Exibe_Arvore(Ptavl->dir);
    }

}

void Exibe_Decrescente(AVL* Ptavl) {

    if(Ptavl == NULL) return NULL;

    Exibe_Decrescente(Ptavl->dir);
    printf("%4d", Ptavl->reg.Chave);
    Exibe_Decrescente(Ptavl->esq);

}

AVL* Libera_Arvore(AVL* Ptavl) {
    if(Ptavl != NULL) {

        Libera_Arvore(Ptavl->esq);
        Libera_Arvore(Ptavl->dir);
        free(Ptavl);

    }

    return NULL;
}

int Insere_Nodo(AVL** Ptavl, Registro reg, int* flag) {

    AVL *pt, *ptt;

    if(Ptavl == NULL) {

        pt = (AVL*) malloc(sizeof(AVL));

        if(pt == NULL) return 0;

        pt->esq = NULL;
        pt->dir = NULL;
        pt->reg = reg;
        pt->FB  = 0;

        *flag  = 1;
        *Ptavl = pt;
        return 1;
    }

    if (reg.Chave == (*Ptavl)->reg.Chave) {
        *flag = 0;
        return 0;
    } else if (reg.Chave < (*Ptavl)->reg.Chave) {

        Insere_Nodo(&((*Ptavl)->esq), reg, flag);

        if(*flag) {

            switch((*Ptavl)->FB) {

                case 1:
                    (*Ptavl)->FB = 0;
                    break;

                case 0:
                    (*Ptavl)->FB = -1;
                    break;

                case -1:
                    ptt = Balancear_Esquerda(*Ptavl);
                    *Ptavl = ptt;
                    *flag = 0;
                    break;

            }

        }

    } else {

        Insere_Nodo(&(*Ptavl)->dir, reg, flag);

        if(*flag) {

            switch((*Ptavl)->FB) {

                case 1:
                    ptt = Balancear_Direita(*Ptavl);
                    *Ptavl = ptt;
                    *flag = 0;
                    break;

                case 0:
                    (*Ptavl)->FB = -1;
                    break;

               case -1:
                    (*Ptavl)->FB = 0;
                    break;


            }

        }

    }

}

AVL* Balancear_Esquerda(AVL* Ptavl) {

    AVL *pt;

    if(Ptavl->esq->FB < 0) {
        pt = Rotacionar_Direita(Ptavl);
    }else {
        pt = Rotacionar_Dupla_Direita(Ptavl);
    }

    return pt;
}

AVL* Balancear_Direita(AVL* Ptavl) {

    AVL *pt;

    if(Ptavl->dir->FB < 0) {
        pt = Rotacionar_Esquerda(Ptavl);
    }else {
        pt = Rotacionar_Dupla_Esquerda(Ptavl);
    }

    return pt;
}

AVL* Rotacionar_Dupla_Esquerda(AVL* Ptavl) {

    AVL *Ptu, *Ptv;

    Ptu = Ptavl->dir;
    Ptv = Ptu->esq;
    Ptu->esq = Ptb->dir;
    Ptb->dir = Ptu;

    Ptavl->dir = Ptb->esq;
    Ptb->esq = Ptavl;

    if(Ptv->FB == 1) {
        Ptavl->FB = -1;
        Ptu->FB = 0;
    } else if(Ptv->FB == -1) {
        Ptavl->FB = 0;
        Ptu->FB = 1;
    } else {
        Ptavl->FB = 0;
        Ptu->FB = 0;
    }

    Ptv->FB = 0;
    return Ptv;

}

AVL* Rotacionar_Dupla_Direita(AVL* Ptavl) {

    AVL *Ptu, *Ptv;

    Ptu = Ptavl->esq;
    Ptv = Ptu->dir;
    Ptu->dir = Ptb->esq;
    Ptb->esq = Ptu;

    Ptavl->esq = Ptb->dir;
    Ptb->dir = Ptavl;

    if(Ptv->FB == 1) {
        Ptavl->FB = -1;
        Ptu->FB = 0;
    } else if(Ptv->FB == -1) {
        Ptavl->FB = 0;
        Ptu->FB = 1;
    } else {
        Ptavl->FB = 0;
        Ptu->FB = 0;
    }

    Ptv->FB = 0;
    return Ptv;

}

AVL* Rotacionar_Direita(AVL* Ptavl) {

    AVL* Ptu;
    Ptu = Ptavl->esq;
    Ptavl->esq = Ptavl->dir;
    Ptavl->dir = Ptavl;
    Ptavl->FB = 0;
    Ptu->FB = 0;

    return Ptu;
}

AVL* Rotacionar_Esquerda(AVL* Ptavl) {

    AVL* Ptu;
    Ptu = Ptavl->dir;
    Ptavl->dir = Ptavl->esq;
    Ptavl->esq = Ptavl;
    Ptavl->FB = 0;
    Ptu->FB = 0;

    return Ptu;
}
