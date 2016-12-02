#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

int main()
{
    int opt, chave;
    AVL* arvore, *ptArvore;

    Registro reg;
    TipoInfo info;
    char nome[30];
    int idade;

    do{

        printf("\n ARVORE DE PESQUISA");
        printf("\n ===================================== ");
        printf("\n 1. Inicializar arvore ");
        printf("\n 2. Verificar se e vazia ");
        printf("\n 3. Buscar chave ");
        printf("\n 4. Insere nodo");
        printf("\n 5. Exibir arvore");
        printf("\n 6. Exibir em ordem decrescente");
        printf("\n 7. Libera arvore");
        printf("\n 8. Remover nodo");
        printf("\n 0. Sair ");
        printf("\n ===================================== ");
        printf("\n Digite uma opcao: ");
        scanf("%d", &opt);

        switch(opt) {

            case 1: // Inicializa
                Incializa_AVL(&arvore);
                break;

            case 2: // É vazia

                if(E_Vazia(arvore)) printf("\nA arvore e vazia\n");
                else printf("\nA arvore nao e vazia\n");

                break;

            case 3: // Pesquisa chave

                printf("\nDigite a chave:");
                scanf("%d", &chave);

                if(Pesquisa_AVL(arvore, chave) != NULL) printf("\nElemento encontrado\n[nome] => %s\n[idade] => %d\n", reg.info.nome, reg.info.idade);
                else printf("\nElemento NAO encontrado\n");

                break;

            case 4: // Insere nodo

                printf("\nDigite a chave:");
                scanf("%d", &chave);

                printf("\nDigite o nome:");
                fflush(stdin);
                gets(nome);

                printf("\nDigite a idade:");
                scanf("%d", &idade);

                strcpy(info.nome, nome);
                info.idade = idade;

                reg.Chave = chave;
                reg.info = info;

                if(Insere_Nodo(&arvore, reg) == 1) printf("\nNodo inserido com sucesso\n");
                else printf("\nERRO ao inserir nodo\n");

                break;

            case 5: // Exibe arvore
                printf("\n\n");
                Exibe_Arvore(arvore);
                printf("\n\n");
                break;

            case 6: // Exibe decrescente

                printf("\n\n");
                Exibe_Decrescente(arvore);
                printf("\n\n");

                break;

            case 7: // Libera arvore
                Libera_Arvore(arvore);
                printf("\nArvore liberada\n");
                break;

            case 8: // Remove nodo

                printf("\nDigite uma chave: ");
                scanf("%d", &chave);

                if(Remover_Nodo(&arvore, chave) == 1)
                    printf("\nRemovido com sucesso\n");
                else
                    printf("\nERRO ao remover elemento\n");

                break;

        }

    } while(opt != 0);


    return 0;
}
