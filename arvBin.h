typedef struct arvBin{
    char info;
    struct arvBin* esq;
    struct arvBin* dir;
    struct arvBin* pai;
}ArvBin;

int arv_vazia (ArvBin* arvore);

ArvBin* arv_cria (char c, ArvBin* sae, ArvBin* sad,ArvBin* pai);

ArvBin* arv_libera (ArvBin* arvore);

void arv_imprime (ArvBin* arvore);

int calcular_expressao(ArvBin* arvore);

void arvore_expressao(char expressao[]);

