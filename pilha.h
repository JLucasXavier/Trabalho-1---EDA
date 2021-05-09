typedef struct dado Dado;
struct dado
{
    char a[2];
    Dado *prox;
};

typedef struct pilha Pilha;
struct pilha
{
    Dado *topo;
};


Pilha *cria_pilha(void);

void push_pilha(Pilha *p, char a);

int vazia_pilha(Pilha *p);

char pop_pilha(Pilha *p);

void monta_shuting_yard(Pilha* saida, Pilha *operador,char var[],int *tam);

void pilha_libera(Pilha *p);