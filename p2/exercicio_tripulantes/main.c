#include "Hashing.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    Tabela D;
    Registro reg;
    Registro* busca;

    int opcao = -1,verifica,chave;

    Inicializar(D);



    printf("[CHAVE DO ELEMENTO]");
    scanf("%d",&chave);

    busca = Pesquisar(D,chave);
    if(busca == NULL) printf("!!! ELEMENTO NAO ENCONTRADO !!!\n");
    else printf("!!! ELEMENTO ENCONTRADO !!!\n");


    return 0;
}
