#include <stdio.h>
#include <stdlib.h>


struct no {
  int info;
  struct no *esq;
  struct no *dir;
};

typedef struct no arvbin;

//Cria e aloca um endereço de memória para a árvore com valores nulos
arvbin* cria_arvbin(){
  arvbin* raiz = (arvbin*) malloc(sizeof(arvbin));
  if (raiz != NULL){
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->info = 0;
  }
  return raiz;
}

void libera_no(arvbin* no){
  if (no == NULL){
    return;
  }
  libera_no(no->esq);
  libera_no(no->dir);
  free(no);
  no = NULL;
}

void libera_arvbin(arvbin* raiz){
  if(raiz == NULL)
    return;
  libera_no(raiz);
  free(raiz);
}

int checasevazio(arvbin* raiz){
  if(raiz == NULL){
    return 1;
  }
  if(raiz->info == 0){
    return 1;
  }
  return 0;
}



int main(int argc, char const *argv[]) {

arvbin* x;

int i;
while (i != 0) {


printf("Programa com principais aplicações da materia de AED2\n");
printf("Digite um numero para escolher uma opção ou um submenu e 0 para sair\n");
printf("1. Cria uma raiz vazia de uma arvore binaria de busca\n");
printf("2. Checa se uma árvore existe\n");
printf("3. Apaga a árvore binária\n");

scanf("%d\n", &i);
switch (i) {
  case 1:
    printf("Criando uma raiz vazia na posição de memória X...\n");
    x = cria_arvbin();
    break;
  case 2:

    break;
  return 0;
    }
  }
};









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
