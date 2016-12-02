#include "hash.h"

struct nodo{
    Registro reg;
    struct nodo* proximo;
};

int H(int chave)
{
    return(chave%M);
}

void Inicializar(Tabela D)
{
    int i ;
    for(i=0; i<M; i++)
        D[i] == NULL;
}

int Inserir(Tabela D, Registro reg)
{
    int entrada;
    struct nodo *pt;

    entrada = H(reg.chave);
    pt = D[entrada];

    while(pt!=NULL && (pt->reg.chave != reg.chave))
        pt = pt->proximo;

    if(pt!=NULL)
        return -1;

    pt = (struct nodo*)malloc(sizeof(struct nodo));

    if(pt==NULL)

        return 0;

    pt->reg = reg;
    pt->proximo = D[entrada];
    D[entrada] = pt;

    return 1;
}

Registro* Pesquisar(Tabela D, int chave)
{
    int entrada;
    struct nodo* pt;
    Registro *reg;
    reg = (Registro*)malloc(sizeof(Registro));
    if(reg == NULL) return NULL;

    entrada = H(chave);

    pt = D[entrada];

    while(pt != NULL && pt->reg.chave != chave)
        pt = pt->proximo;

    if(pt == NULL) return NULL;
    else if(pt != NULL)
    {
        *reg = pt->reg;
        return reg;
    }
}

int Remover(Tabela D, int chave)
{
    int entrada;
    struct nodo *pt, *anterior;
    anterior = NULL;
    entrada = H(chave);

    pt = D[entrada];

    while(pt != NULL && pt->reg.chave != chave)
    {
        anterior = pt;
        pt = pt->proximo;
    }

    if(pt != NULL)
    {
        if(pt == D[entrada]) ///remove inicio
        {
            D[entrada] = pt->proximo;
        }else ///remove fim
        {
            anterior->proximo = pt->proximo;
        }
        free(pt);
        return 1;
    }
    return 0;
}

void Liberar(Tabela D)
{
    int i;
    struct nodo *aux, *pt;
    for(i=0; i<M;i++)
    {
        pt = D[i];
        while(pt!=NULL)
        {
            aux = pt;
            pt = pt->proximo;
            free(aux);
        }
        D[i] = NULL;
    }
}
