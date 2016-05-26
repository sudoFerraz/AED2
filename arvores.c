#include <stdio.h>
#include <stdlib.h>


struct no {
  struct no* esq;
  struct no* dir;
  int info;
};

typedef struct no arvorebin;

int main(int argc, char const *argv[]) {

  printf("Doido\n");
  return 0;


}










/*
//Aponta o ponteiro com estrutura no(arvore binaria) para NULL
arvorebin cria_arvorebin(arvorebin *raiz){
  if(raiz != NULL){
    return NULL;

  }
  if(*raiz == NULL){
    return NULL;
  }

*raiz = NULL;
return raiz;
}

//Checa se o ponteiro com estrutura esta vazio
int checasevazio(*arvorebin){
if(*raiz == NULL){
  return 1;
}
else
  return 0;
};

arvorebin deletanodo(*raiz){

}
*/
