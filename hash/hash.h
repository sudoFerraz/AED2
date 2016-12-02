#include <stdio.h>
#include <stdlib.h>
#define M 10

typedef struct {
    char nome[30];
    int idade;
}tipoInfo;

typedef struct{
    int chave;
    tipoInfo info;
}Registro;

typedef struct nodo *End;
typedef End Tabela[M];

int H(int chave);
void Inicializar(Tabela D);
int Inserir(Tabela D, Registro reg);
Registro* Pesquisar(Tabela D, int chave);
int Remover(Tabela D, int chave);
