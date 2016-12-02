typedef struct {

    char nome[30];
    int idade;

} TipoInfo;

typedef struct {

    int Chave;
    TipoInfo info;

} Registro;

typedef struct nodoAVL AVL;

void Incializa_AVL(AVL** Ptavl);
int E_Vazia(AVL* Ptavl);
AVL* Pesquisa_AVL(AVL* Ptavl, int chave);
void Exibe_Arvore(AVL* Ptavl);
void Exibe_Decrescente(AVL* Ptavl);
AVL* Libera_Arvore(AVL* Ptavl);
int Insere_Nodo(AVL** Ptavl, Registro reg, int* flag);
AVL* Balancear_Esquerda(AVL* Ptavl);
AVL* Balancear_Direita(AVL* Ptavl);
AVL* Rotacionar_Dupla_Esquerda(AVL* Ptavl);
AVL* Rotacionar_Dupla_Direita(AVL* Ptavl);
AVL* Rotacionar_Esquerda(AVL* Ptavl);
AVL* Rotacionar_Direita(AVL* Ptavl);
