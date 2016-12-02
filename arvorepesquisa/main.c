#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

int main()
{
    int opt;
    ABP* arvore;

    do{

        printf("\n ARVORE DE PESQUISA");
        printf("\n ===================================== ");
        printf("\n 1. Inicializar arvore ");
        printf("\n 2. Verifica se é vazia ");
        printf("\n 3. Buscar chave ");
        printf("\n 0. Sair ");
        printf("\n ===================================== ");
        printf("\n Digite uma opção: ");
        scanf("%d", &opt);

        switch(opt) {

            case 1:
                Incializa_ABP(&arvore);
                break;

            case 2:

                if(E_Vazia(arvore) == 1) {
                    printf("\nA arvore é vazia");
                }else {
                    printf("\nA arvore não é vazia");
                }

                break;

        }

    } while(opt != 0);


    return 0;
}
