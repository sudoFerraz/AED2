typedef struct {
    char nome[30];
    int idade;
} TipoInfo;

typedef struct {
    int Chave;
    TipoInfo info;
} Registro;

typedef struct nodoABP ABP;

void Incializa_ABP(ABP** Ptabp);
int E_Vazia(ABP* Ptabp);
ABP* Pesquisa_ABP(ABP* Ptabp, int chave);
