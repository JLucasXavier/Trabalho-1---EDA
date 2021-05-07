typedef struct arvBin {
    char info;
    struct arvBin* esq;
    struct arvBin* dir;
} ArvBin;

ArvBin* arv_criavazia (void);

ArvBin* arv_cria (char c, ArvBin* sae, ArvBin* sad);

ArvBin* arv_libera (ArvBin* a);

int arv_vazia (ArvBin* a);

int arv_pertence (ArvBin* a, char c);

void arv_imprime (ArvBin* a);