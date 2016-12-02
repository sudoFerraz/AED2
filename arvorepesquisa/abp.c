#include <stdio.h>
#include "abp.h"

struct nodoABP {
    Registro reg;
    struct nodoABP *esq;
    struct nodoABP *dir;
};

void Incializa_ABP(ABP** Ptabp) {
    *Ptabp = NULL;
}

int E_Vazia(ABP* Ptabp) {
    if(Ptabp == NULL) return 1;
    else return 0;
}

ABP* Pesquisa_ABP(ABP* Ptabp, int chave) {



}
