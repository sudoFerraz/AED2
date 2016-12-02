#include "Hashing.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

    Tabela D;
    Registro reg;
    Registro* busca;

    int opcao = -1,verifica,chave;

    while(opcao != 6)
    {

        printf("\n      HASH        ");
        printf("\n====================\n");


        printf("1.INICIALIZAR\n");
        printf("2.INSERIR\n");
        printf("3.PESQUISAR\n");
        printf("4.REMOVER\n");
        printf("5.LIBERAR\n");
        printf("6.SAIR\n");
        printf("\n====================");
        printf("\n");
        printf("[OPÇÃO] ");
        scanf("%d",&opcao);


        switch(opcao)
        {
            case 1:

                Inicializar(D);
                printf("!!! TABELA INICIALIZADA !!!\n");
                break;

            case 2:

                printf("[CHAVE] ");
                scanf("%d",&reg.chave);

                printf("[NOME] ");
                scanf("%s",&reg.info.nome);

                printf("[IDADE] ");
                scanf("%d",&reg.info.idade);

                verifica= Inserir(D,reg);

                if(verifica == -1)
                    printf("!!! A CHAVE JÁ EXISTE !!!\n");
                else if(verifica == 0)
                    printf("!!! ERRO AO ALOCAR !!!\n");
                else if(verifica == 1)
                    printf("!!! SUCESSO !!!\n");

                break;

            case 3:

                printf("[CHAVE DO ELEMENTO]");
                scanf("%d",&chave);

                busca = Pesquisar(D,chave);
                if(busca == NULL) printf("!!! ELEMENTO NAO ENCONTRADO !!!\n");
                else printf("!!! ELEMENTO ENCONTRADO !!!\n");

                break;

            case 4:

                printf("[CHAVE DO ELEMENTO]");
                scanf("%d",&chave);
                verifica = Remover(D,chave);

                if(verifica == 1)
                    printf("!!! REMOVIDO COM SUCESSO !!!\n");
                else if(verifica == -1)
                    printf("!!! NAO ENCONTRADO !!!\n");

                break;

            case 5:
                Liberar_Dicionario(D);
                printf("!!! LIBERADO COM SUCESSO !!!");
                break;
        }
    }
    return 0;
}
