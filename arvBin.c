#include <stdio.h>
#include "ArvBin.h"

ArvBin* arv_criavazia (void)
{
    return NULL;
}

ArvBin* arv_cria (char c, ArvBin* sae, ArvBin* sad)
{
    ArvBin* p=(ArvBin*)malloc(sizeof(ArvBin));
    if(p==NULL) exit(1);
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

ArvBin* arv_libera (ArvBin* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

int arv_vazia (ArvBin* a)
{
    return a==NULL;
}

int arv_pertence (ArvBin* a, char c)
{
    if (arv_vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return a->info==c ||
            arv_pertence(a->esq,c) ||
            arv_pertence(a->dir,c);
}

void arv_imprime (ArvBin* a)
{
    if (!arv_vazia(a)){
        
        printf("(%c ",a->info); 
        arv_imprime(a->esq); 
        arv_imprime(a->dir); 
        printf(")");
    }
    else
        printf("() ");
}