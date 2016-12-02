#include "Hashing.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo *End;
typedef End Tabela[M];

struct nodo
{
    Registro reg;
    struct nodo *prox;

};

int H(int chave){
    return (chave % M);

}

void Inicializar(Tabela D){
    int i;
    for(i=0;i<M;i++){
        D[i]=NULL;
    }
}

int Inserir(Tabela D,Registro reg){

    int entrada;
    struct nodo *pt;

    entrada = H(reg.chave);
    pt=D[entrada];

    while(pt!=NULL&&pt->reg.chave!=reg.chave)

        pt=pt->prox;

        if(pt!=NULL)
            return -1;

        pt=(struct nodo*)malloc(sizeof(struct nodo));

        if(pt==NULL)
            return 0;

        pt->reg=reg;
        pt->prox=D[entrada];
        D[entrada]=pt;

        return 1;


}

Registro* Pesquisar(Tabela D,int chave){

   int entrada;
   struct nodo *pt;
   Registro *reg;
   reg=(Registro*)malloc(sizeof(Registro));

   if(reg==NULL)
    return NULL;

   entrada=H(chave);
   pt=D[entrada];

   while(pt!=NULL&&pt->reg.chave!=chave)
    pt=pt->prox;

   if(pt!=NULL) {
        *reg=pt->reg;
        return reg;
   }else
        return NULL; //chave nao encontrada
}

int Remover(Tabela D,int chave){
    int entrada;
    struct nodo *ant;
    struct nodo *pt;
    Registro *reg;
    reg=(Registro*)malloc(sizeof(Registro));
    if(reg==NULL)
        return NULL;

    entrada=H(chave);
    pt=D[entrada];
    ant=D[entrada];
    while(pt!=NULL&&pt->reg.chave!=chave){
        ant=pt;
        pt=pt->prox;
    }
    if(pt!=NULL) {
        if(pt==D[entrada]){
            D[entrada]=pt->prox;
            return 1;
        }
        else
        ant->prox = pt->prox;
        free(pt);
        return 1;
    }
    else return 0;
}

void Liberar_Dicionario(Tabela D){
    int i;
    struct nodo *aux,*pt;
    for(i=0;i<M;i++){
        pt=D[i];
        while(pt!=NULL){
            aux=pt;
            pt=pt->prox;
            free(aux);
        }
        D[i]=NULL;

    }
}


