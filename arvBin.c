#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvBin.h"

int arv_vazia (ArvBin* arvore){
    return arvore==NULL;
}

ArvBin* arv_cria (char c, ArvBin* sae, ArvBin* sad,ArvBin* pai){
    ArvBin* p=(ArvBin*)malloc(sizeof(ArvBin));
    if(p==NULL) exit(1);
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    p->pai = pai;
    return p;
}

ArvBin* arv_libera (ArvBin* arvore){
    if (!arv_vazia(arvore)){
        arv_libera(arvore->esq);
        arv_libera(arvore->dir);
        free(arvore);
    }
    return NULL;
}

void arv_imprime (ArvBin* arvore){
    if (!arv_vazia(arvore)){
        printf("(%c ",arvore->info); 
        arv_imprime(arvore->esq); 
        arv_imprime(arvore->dir); 
        printf(")");
    }
    else
        printf("() ");
}

int calcular_expressao(ArvBin* arvore){
    if(arvore->info=='+'){
        return calcular_expressao(arvore->esq) + calcular_expressao(arvore->dir);
    }else if(arvore->info=='-'){
        return calcular_expressao(arvore->esq) - calcular_expressao(arvore->dir);
    }else if(arvore->info=='*'){
        return calcular_expressao(arvore->esq) * calcular_expressao(arvore->dir);
    }else if(arvore->info=='/'){
        return calcular_expressao(arvore->esq) / calcular_expressao(arvore->dir);
    }else{
        return (arvore->info)-'0';
    }
}

void arvore_expressao(char expressao[]){
    ArvBin* arvore = arv_cria(expressao[strlen(expressao)-1],NULL,NULL,NULL);
    ArvBin* atual = arvore;
    int i=strlen(expressao)-2;
    while(i>=0){
        if(atual->dir==NULL){
            if(expressao[i]=='+' || expressao[i]=='/' || expressao[i]=='-' || expressao[i]=='*'){
                arvore->dir=arv_cria(expressao[i],NULL,NULL,atual);
                i--;
                atual=arvore->dir;
            }else{
                atual->dir=arv_cria(expressao[i],NULL,NULL,atual);
                i--;
            }
        }else if(atual->esq==NULL){
            if(expressao[i]=='+' || expressao[i]=='/' || expressao[i]=='-' || expressao[i]=='*'){
                arvore->esq=arv_cria(expressao[i],NULL,NULL,atual);
                i--;
                atual=arvore->esq;
            }else{
                atual->esq=arv_cria(expressao[i],NULL,NULL,atual);
                i--;
            }
        }
        else if(atual->dir!=NULL && atual->esq!=NULL){
            ArvBin* temp=arvore->dir;
            arvore->dir=atual->pai;
            arvore->dir->dir=temp;
            atual=atual->pai;
        }
    }
    printf("A representação aninhada da árvore: ");
    arv_imprime(arvore);
    printf("\nO resultado da árvore de expressão é %d",calcular_expressao(arvore));
    arv_libera(arvore);
    arv_libera(atual);
}