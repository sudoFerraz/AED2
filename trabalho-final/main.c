#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    //TipoGrafo* Grafo = Ler_Arquivo();
    TipoGrafo* Grafo = Ler_Arquivo();
    TipoVertice v1, v2;
    TipoPeso peso;
    int n, opt, res;


    do {

        printf("\n             ROTAS              ");
        printf("\n================================");
        printf("\n1. INSERIR CAMINHO");
        printf("\n2. REMOVER CAMINHO");
        printf("\n3. CALCULAR MELHOR ROTA");
        printf("\n4. MOSTRAR CAMINHOS");
        printf("\n5. SALVAR");
        printf("\n0. SAIR");
        printf("\n================================");
        printf("\nDIGITE UMA OPCAO: ");
        scanf("%d", &opt);

        switch(opt) {

            case 1:

                printf("PONTO DE ORIGEM: ");
                scanf("%d", &v1);

                printf("PONTO DE DESTINO: ");
                scanf("%d", &v2);

                printf("TEMPO DE VIAGEM (EM HORAS): ");
                scanf("%d", &peso);

                res = Insere_Aresta(Grafo, v1, v2, peso);

                break;

            case 2:

                printf("PONTO DE ORIGEM: ");
                scanf("%d", &v1);

                printf("PONTO DE DESTINO: ");
                scanf("%d", &v2);

                res = Retira_Aresta(Grafo, v1, v2);

                break;

            case 3:

                printf("PONTO DE ORIGEM: ");
                scanf("%d", &v1);

                printf("PONTO DE DESTINO: ");
                scanf("%d", &v2);

                printf("\n================================\n");

                Caminho_mais_Curto(Grafo, v1, v2);

                break;

            case 4:

                Mostra_Grafo(Grafo);

                break;

            case 5:

                res = Gravar_Arquivo(Grafo);

                break;

        }

        printf("\n================================");
    } while(opt != 0);

}
