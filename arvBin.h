typedef struct arvBin {
    char info;
    struct arvBin* esq;
    struct arvBin* dir;
    struct arvBin* pai;
}ArvBin;

int arv_vazia (ArvBin* a);

ArvBin* arv_cria (char c, ArvBin* sae, ArvBin* sad,ArvBin* pai);

ArvBin* arv_libera (ArvBin* a);

void arv_imprime (ArvBin* a);

void arvore_expressao(char expressao[]);
