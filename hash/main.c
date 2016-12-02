#include "hash.h"

int main(){
    Tabela D;
    Registro reg;
    int op = -1;
    int result,chave;
    while(op != 0){
        printf("             HASH             \n");
        printf("==============================\n");
        printf("1. Iniciar hash\n");
        printf("2. Inserir\n");
        printf("3. Pesquisar elemento\n");
        printf("4. Remover elemento\n");
        printf("5. Liberar \n");
        printf("0. Sair\n");
        printf("==============================\n");

        printf("Digite uma opção:");
        scanf("%d",&op);

        switch(op) {

            case 1:

                Inicializar(D);
                printf("Tabela hash iniciada !\n");

                break;

            case 2:

                printf("[CHAVE] \n");
                scanf("%d",&reg.chave);

                printf("[NOME] \n");
                scanf("%s",&reg.info.nome);

                printf("[IDADE] \n");
                scanf("%d",&reg.info.idade);

                result = Inserir(D,reg);

                if(result == -1)
                    printf("!!!!!!! A CHAVE JÁ EXISTE !!!!!!!\n");
                else if(result == 0)
                    printf("!!!!!!! ERRO AO ALOCAR !!!!!!!\n");
                else if(result == 1)
                    printf("!!!!!!! SUCESSO !!!!!!!\n");

                break;

            case 3:

                printf("[CHAVE] \n");
                scanf("%d",&chave);
                Pesquisar(D,chave);

                break;

            case 4:

                printf("[ELEMENTO] \n");
                scanf("%d",&chave);

                result = Remover(D,chave);

                if(result == 1)
                    printf("!!!!!!! REMOVIDO !!!!!!!\n");
                else if(result == -1)
                    printf("!!!!!!! NAO ENCONTRADO !!!!!!!\n");

                break;

            case 5:

                break;
        }
    }
    return 0;
}
