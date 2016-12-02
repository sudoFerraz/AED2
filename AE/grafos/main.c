#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

int main()
{

    TipoGrafo* Grafo;
    TipoVertice v1, v2;
    TipoPeso peso;
    TipoInfo* info;
    int n, opt, res, status;
    char nome[50], endereco[100];


    do {

        printf("\n        MOTOBOY         ");
        printf("\n========================");
        printf("\n1. CRIAR DADOS");
        printf("\n2. IMPORTAR DADOS");
        printf("\n0. SAIR");
        printf("\n========================");
        printf("\nOPCAO: ");
        scanf("%d", &opt);

        switch(opt) {

            case 1:
                printf("NUMERO MAXIMO DE EMPRESAS: ");
                scanf("%d", &n);

                Grafo = Cria_Grafo(n);

                if(Grafo != NULL) {
                    printf("\nDADOS CRIADOS COM SUCESSO !");
                    opt = 0;
                }

                break;

            case 2:

                Grafo = Ler_Arquivo();

                if(Grafo != NULL) {
                    printf("\nDADOS IMPORTADOS COM SUCESSO !");
                    opt = 0;
                }

                break;

        }

        printf("\n========================");

    }while(opt != 0);

    do {

        printf("\n              GRAFOS            ");
        printf("\n================================");
        printf("\n1. INSERIR EMPRESA");
        printf("\n2. INSERIR CAMINHO");
        printf("\n3. VERIFICAR SE CAMINHO EXISTE");
        printf("\n4. REMOVER CAMINHO");
        printf("\n5. CONSULTAR CAMINHO");
        printf("\n6. MOSTRAR LISTA DE ADJACENTES");
        printf("\n7. MOSTRAR GRAFO");
        printf("\n8. LIBERAR GRAFO");
        printf("\n9. SALVAR");
        printf("\n9. REMOVER EMPRESA");
        printf("\n9. CALCULAR ROTA");
        printf("\n9. MOSTRAR EMPRESAS");
        printf("\n0. SAIR");
        printf("\n================================");
        printf("\nDIGITE UMA OPCAO: ");
        scanf("%d", &opt);
        printf("================================");


        switch(opt) {

            case 1: ///INSERIR EMPRESA

                printf("NOME: ");
                scanf("%s", nome);

                printf("\nENDERECO: ");
                scanf("%s", endereco);

                info->nome = nome;
                info->endereco = endereco;
                info->status = 1;

                res = Cadastrar_Vertice(Grafo, info);

                if(res == 0) printf("\n!!! TABELA DE EMPRESAS JÁ ESTÁ CHEIA !!!")
                else if(res == -1) printf("\n!!! INFORMAÇÕES INVALIDAS !!!");
                else printf("\nEMPRESA CADASTRADA COM SUCESSO !");

                break;

            case 2: ///INSERIR ARESTA

                Mostrar_Vertices();

                printf("\nEMPRESA ORIGEM: ");
                scanf("%d", &v1);

                printf("\nEMPRESA DESTINO: ");
                scanf("%d", &v2);

                printf("\nPESO DA ARESTA: ");


                scanf("%d", &peso);

                if(Insere_Aresta(Grafo, v1, v2, peso) == 1)
                    printf("\nARESTA INSERIDA COM SUCESSO !");
                else
                    printf("\nERRO AO INSERIR ARESTA.");

                break;

            case 3: ///VERIFICA SE ARESTA EXISTE

                printf("\nVERTICE 1:");
                scanf("%d", &v1);

                printf("\nVERTICE 2:");
                scanf("%d", &v2);

                res = Existe_Aresta(Grafo, v1, v2);

                if(res == -1)
                    printf("\nGRAFO INEXISTENTE !");
                else if(res == 1)
                    printf("\nARESTA EXISTENTE !");
                else
                    printf("\nARESTA INEXISTENTE !");

                break;

            case 4: ///REMOVER ARESTA

                printf("\nVERTICE 1:");
                scanf("%d", &v1);

                printf("\nVERTICE 2:");
                scanf("%d", &v2);

                res = Retira_Aresta(Grafo, v1, v2);

                if(res == -1)
                    printf("\nGRAFO INEXISTENTE !");
                else if(res == 0)
                    printf("\nARESTA INEXISTENTE !");
                else
                    printf("\nARESTA REMOVIDA !");

                break;

            case 5: ///CONSULTAR ARESTA

                printf("\nVERTICE 1:");
                scanf("%d", &v1);

                printf("\nVERTICE 2:");
                scanf("%d", &v2);

                res = Consulta_Aresta(Grafo, v1, v2, &peso);

                if(res == -1)
                    printf("\nGRAFO INEXISTENTE !");
                else if(res == 0)
                    printf("\nARESTA INEXISTENTE !");
                else
                    printf("\nPESO DA ARESTA: %d", peso);

                break;

            case 6: ///MOSTRAR LISTA DE ADJACENTES

                printf("\nVERTICE: ");
                scanf("%d", &v1);

                Mostra_Lista_Adjacentes(Grafo, v1);

                break;

            case 7: ///MOSTRAR GRAFO

                Mostra_Grafo(Grafo);

                break;

            case 8: ///LIBERAR GRAFO

                if(Libera_Grafo(Grafo) == NULL) {
                    printf("\nGRAFO LIBERADO !");
                }else{
                    printf("\nERRO AO LIBERAR GRAFO !");
                }

                break;

            case 9: ///LIBERAR GRAFO

                printf("%d", Gravar_Arquivo(Grafo));

                break;

        }

        printf("\n================================");
        printf("\nDIGITE UMA OPCAO : ");
        scanf(&opt);

    } while(opt != 0);

}
