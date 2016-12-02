#include "grafo.h"

struct Grafo {
    int NumVertices;
    int NumArestas;
    TipoPeso **Mat;
};

TipoGrafo* Cria_Grafo(int NVertices) {

    int i, k;
    TipoGrafo *Grafo;

    if(NVertices <= 0) return NULL;

    Grafo = (TipoGrafo*) malloc(sizeof(TipoGrafo));
    if(Grafo == NULL) return NULL;

    Grafo->Mat = (TipoPeso**) malloc(NVertices*sizeof(TipoPeso*));
    if(Grafo->Mat == NULL) {
        free(Grafo);
        return NULL;
    }

    for(i=0; i<NVertices; i++) {

        Grafo->Mat[i] = (TipoPeso*) calloc(NVertices, sizeof(TipoPeso));
        if(Grafo->Mat[i] == NULL) { /// Não conseguiu alocar a linha i da matriz

                for(k=0; k<i; k++) { /// Libera linhas previamente alocadas
                    free(Grafo->Mat[k]);
                }

                free(Grafo);
                return NULL;
        }

    }

    Grafo->NumVertices = NVertices;
    Grafo->NumArestas = 0;

    return Grafo;
}

int Insere_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2, TipoPeso peso) {

    if(Grafo == NULL) return -1;

    if(Grafo->Mat[v1][v2] != 0 || peso == 0) return 0;

    Grafo->Mat[v1][v2] = peso;
    Grafo->NumArestas++;

    return 1;
}

int Retira_Aresta(TipoGrafo *Grafo, TipoVertice v1, TipoVertice v2) {

    if(Grafo==NULL) return -1;

    if(Grafo->Mat[v1][v2]==0) return 0;

    Grafo->Mat[v1][v2] = 0;
    Grafo->NumArestas --;

    return 1;
}

void Mostra_Grafo(TipoGrafo* Grafo) {

    int i,j;

    if(Grafo == NULL || Grafo->NumArestas == 0) {
        printf("\nGRAFO NAO EXISTE OU NAO POSSUI ARESTAS.");
    }else {
        printf("NUMVERTICES %d\nNUMARESTAS %d", Grafo->NumVertices, Grafo->NumArestas);
        for(i=0; i<Grafo->NumVertices; i++) {
            printf("\nCONEXOES PARTINDO DE %2d : ", i);

            for(j = 0; j < Grafo->NumVertices; j++) {
                if(Grafo->Mat[i][j] != 0) {
                    printf("%4d", j);
                }
            }
        }

    }

}

TipoGrafo* Ler_Arquivo() {

    int l = 0;
    char ch;
    FILE* arquivo = fopen("data.txt", "r");
    int v1,v2,peso,n;

    if(arquivo == NULL) return NULL;

    fscanf(arquivo, "%d\n", &n);
    if(n != NULL) l = 1;

    TipoGrafo* Grafo = Cria_Grafo(n);

    if(l != 0) {
        while((fscanf(arquivo, "%d,%d,%d\n", &v1,&v2,&peso)) != EOF) {
            Insere_Aresta(Grafo, v1, v2, peso);
        }
    }

    return Grafo;
}

int Gravar_Arquivo(TipoGrafo* Grafo) {

    int i,j;

    if(Grafo == NULL || Grafo->Mat == NULL) return -1;

    FILE *arquivo = fopen("data.txt", "w");
    if(arquivo == NULL) return 0;

    fprintf(arquivo, "%d\n", Grafo->NumVertices);

    for(i = 0; i<Grafo->NumVertices; i++) {
        for(j = 0; j<Grafo->NumVertices; j++) {
            fprintf(arquivo, "%d,%d,%d\n", i,j,Grafo->Mat[i][j]);
        }
    }

    fclose(arquivo);

    return 1;

}

void Caminho_mais_Curto(TipoGrafo *grafo, int origem, int destino) {

    int i, vert,k, NovaDist, min;
    int *M, *L, *A, *caminho;

    M = (int *)malloc(grafo->NumVertices*sizeof(int));
    L = (int *)malloc(grafo->NumVertices*sizeof(int));
    A = (int *)malloc(grafo->NumVertices*sizeof(int));

    caminho = (int *)malloc(grafo->NumVertices*3*sizeof(int));

    for (i=0; i<grafo->NumVertices; i++) {
        M[i] = 0; //  false -- determina se um vertice ja foi visitado
        A[i] = -1;  // determina o caminho mais curto entre origem e destino
        L[i] = 300000; //infinito determina o comprimento do caminho mais curto
    }

    vert = origem;
    L[vert] = 0;

    while (vert != destino && vert != -1) {

        for(i=0;i<grafo->NumVertices; i++) {

            if (grafo->Mat[vert][i] != 0 && M[i]==0) {
                NovaDist = L[vert] + grafo->Mat[vert][i];

                if (NovaDist < L[i]) {
                    L[i] = NovaDist;
                    A[i] = vert;
                }
            }

        }

        M[vert] = 1;   // toda a lista de adjacentes de vert já foi analisada
        min = 300000;   //infinito
        vert = -1;  // valor invalido

        for (i=0; i<grafo->NumVertices; i++) {
            if (M[i]==0 && L[i] < min) {
               min = L[i];   // atualiza min
               vert = i;      //atualiza vert
            }

        }

     }

     if (vert == destino) {

        printf(" O CAMINHO MAIS CURTO ENTRE O CENTRO %d E %d DURA %d HORAS\n ROTA -> ", origem, destino, L[destino] );
        caminho[0] = destino;

        k = 1;

        while (vert != origem) {

            caminho[k]= A[vert];
            vert = A[vert];
            k++;

        }


        for (i=k-1; i>=0; i--)
            printf("%4d", caminho[i]);
     }



     else printf("NAO EXISTE ROTA DE %d ATE %d", origem, destino);
}
