#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{

    int opt, altura;
    char item;
    AB* arvore, *elemento;

    do{

        printf("\n\n================== ARVORES ==================");
        printf("\n1.  Criar arvore");
        printf("\n2.  Criar raiz");
        printf("\n3.  Buscar");
        printf("\n4.  Insere a esquerda");
        printf("\n5.  Insere a direita");
        printf("\n6.  Pre ordem");
        printf("\n7.  Pos ordem");
        printf("\n8.  Em ordem");
        printf("\n9.  Remove folha");
        printf("\n10. Libera arvore");
        printf("\n11. Maior elemento");
        printf("\n12. Descendentes");
        printf("\n13. Estritamente binaria");
        printf("\n14. Altura da arvore");
        printf("\n0. Sair   ");
        printf("\n=============================================");
        printf("\n ELEMENTO SELECIONADO: ");
        if(elemento != NULL)
            Imprime_Nodo(elemento);
        else
            printf("Nenhum");

        printf("\n=============================================");
        printf("\nDigite uma opcao: ");
        scanf("%d", &opt);

        switch(opt) {

            case 1: // Criar arvore
                arvore = Cria_Arvore();
                break;

            case 2: // Criar raiz
                printf("\nDigite o valor do item: ");
                fflush(stdin);
                scanf(" %c", &item);

                if(Cria_Raiz(&arvore, item) == 1)
                    printf("Raiz criada com sucesso");
                else
                    printf("Erro ao criar raiz");
                break;

            case 3: // Buscar

                elemento = NULL;
                printf("\nValor do elemento: ");
                fflush(stdin);
                scanf(" %c", &item);

                if(Busca(arvore, item, &elemento) == 1) {
                    if(elemento != NULL) {
                        printf("\nAchou");
                    }else{
                        printf("\nElemento não encontrado");
                    }
                }else{
                    printf("\nErro ao buscar elemento");
                }

                break;

            case 4: // Insere nodo a esquerda

                printf("\nDigite o valor do nodo: ");
                fflush(stdin);
                scanf(" %c", &item);

                if(Insere_Filho_Esquerda(elemento, item) == 1)
                    printf("\nElemento inserido com sucesso");
                else
                    printf("\nErro ao inserir elemento");

                break;

            case 5:

                printf("\nDigite o valor do nodo: ");
                fflush(stdin);
                scanf(" %c", &item);

                if(Insere_Filho_Direita(elemento, item) == 1)
                    printf("\nElemento inserido com sucesso");
                else
                    printf("\nErro ao inserir elemento");

                break;

            case 6:

                printf("\nArvore: \n");
                Pre_Ordem(arvore);

                break;

            case 7:

                printf("\nArvore: \n");
                Pos_Ordem(arvore);

                break;

            case 8:

                printf("\nArvore: \n");
                Em_Ordem(arvore);

                break;

            case 9:

                printf("\nDigite o valor do nodo: ");
                fflush(stdin);
                scanf(" %c", &item);

                if(Remove_Folha(&arvore, item) == 1) {
                    printf("\nFolha removida com sucesso");
                }else {
                    printf("\nERRO ao remover folha");
                }

                break;

            case 10:

                if(Libera_Arvore(arvore) == NULL) {
                    printf("\nArvore liberada com sucesso");
                }else {
                    printf("\nERRO ao liberar a arvore");
                }

                break;

            case 11: // Maior_Elemento

                Maior_Elemento(arvore, &item);

                if(item != NULL) {
                    printf("\n\nMaior elemento : %c", item);
                }

                break;

            case 12: // Descendentes

                printf("\n\n");
                Descendentes(arvore);

                break;

            case 13: // Estritamente_Binaria

                if(Estritamente_Binaria(arvore))
                    printf("\n\nA arvore é estritamente binaria");
                else
                    printf("\n\nA arvore NAO é estritamente binária");

                break;

            case 14: // Altura

                altura = Altura(arvore);
                printf("\n\nAltura da arvore: %d", altura);

                break;



        }

    } while(opt != 0);

    return 0;
}
