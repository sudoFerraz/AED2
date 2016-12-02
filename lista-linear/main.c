#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main()
{
    int opt, elem, pos, tamanho;
    int *resultado;
    Lista* Ptl;

    do {

        printf("----------- LISTA LINEAR -----------\n");
        printf("(1) Criar lista\n");
        printf("(2) Inserir elemento\n");
        printf("(3) Remover elemento\n");
        printf("(4) Consultar nodo\n");
        printf("(5) Tamanho da lista\n");
        printf("(6) Verificar se e vazia\n");
        printf("(8) Imprime lista\n");
        printf("(7) Liberar lista\n");
        printf("(0) Sair\n");

        printf("Digite uma opcao: ");
        scanf("%d", &opt);

        switch(opt) {

            case 1: // Cria lista

                Ptl = Cria_lista();

                break;

            case 2: // Insere elemento

                printf("\nValor do elemento : ");
                scanf("%d", &elem);

                Ptl = Insere_elem(Ptl, elem);

                break;

            case 3: // Remove elemento

                printf("\nElemento a ser removido: ");
                scanf("%d", &elem);

                Ptl = Remove_elem(Ptl, elem);

                break;

            case 4: // Consulta nodo

                printf("\nPosicao do nodo : ");
                scanf("%d", &pos);

                if(Consulta_nodo(Ptl, pos, resultado) == 1)
                    printf("\nValor do nodo encontrado : %d", *resultado);
                else
                    printf("Nodo nao encontrado");

                break;

            case 5: // Tamaho da lista

                tamanho = Tamanho_lista(Ptl);
                if(tamanho != -1)
                    printf("\nTamanho da lista: %d", &tamanho);
                else
                    printf("Erro ao calcular tamanho da lista");

                break;

            case 6: // Lista vazia

                if(E_Vazia(Ptl))
                    printf("\nLista vazia");
                else
                    printf("\nA lista nao e vazia");

                break;

            case 7: // Imprime lista



                break;

            case 8: // Libera lista

                Libera_lista(Ptl);

                break;



        }

    } while(opt != 0);

}
