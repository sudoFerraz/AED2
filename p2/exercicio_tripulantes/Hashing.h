#define M 200

typedef struct{
    char nome[100];
    int idade;
}TipoInfo;

typedef struct{
    int chave;
    TipoInfo info;
}Registro;

typedef struct nodo *End;
typedef End Tabela[M];


void Inicializar(Tabela D);
int Inserir(Tabela D,Registro reg);
Registro* Pesquisar(Tabela D,int chave);
int Remover(Tabela D,int chave);
void Liberar_Dicionario(Tabela D);

