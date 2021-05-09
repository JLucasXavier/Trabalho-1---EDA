#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvBin.h"

int arv_vazia (ArvBin* a)
{
    return a==NULL;
}

ArvBin* arv_cria (char c, ArvBin* sae, ArvBin* sad,ArvBin* pai)
{
    ArvBin* p=(ArvBin*)malloc(sizeof(ArvBin));
    if(p==NULL) exit(1);
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    p->pai = pai;
    return p;
}

ArvBin* arv_libera (ArvBin* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        arv_libera(a->pai);
        free(a); 
    }
    return NULL;
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

void arvore_expressao(char expressao[]){
    ArvBin* arvore = arv_cria(expressao[strlen(expressao)-1],NULL,NULL,NULL);
    ArvBin* atual = arvore;
    int i=strlen(expressao)-2;
    while(i>=0){
        //printf("char que esta sendo lido:%c\n",expressao[i]);
        if(atual->dir==NULL){
            if(expressao[i]=='+' || expressao[i]=='/' || expressao[i]=='-' || expressao[i]=='*'){
                arvore->dir=arv_cria(expressao[i],NULL,NULL,atual);
                //printf("no da direita: %c\n",arvore->dir->info);
                i--;
                atual=arvore->dir;
                //printf("no atual: %c pai do no atual: %c\n",atual->info,atual->pai->info);
                //printf("no da direita: %c %c\n",arvore->dir->info,arvore->dir->pai->info);
            }else{
                atual->dir=arv_cria(expressao[i],NULL,NULL,atual);
                //printf("no da direita: %c\n",arvore->dir->info);
                i--;
                //printf("no atual: %c pai do no atual: %c %c\n",atual->info,atual->pai->info,atual->dir->info);
            }
        }else if(atual->esq==NULL){
            //printf("CHEGOU AQUI\n");
            if(expressao[i]=='+' || expressao[i]=='/' || expressao[i]=='-' || expressao[i]=='*'){
                arvore->esq=arv_cria(expressao[i],NULL,NULL,atual);
                i--;
                atual=arvore->esq;
                //printf("no atual: %c pai do no atual: %c\n",atual->info,atual->pai->info);
            }else{
                atual->esq=arv_cria(expressao[i],NULL,NULL,atual);
                i--;
                //printf("no atual: %c pai do no atual: %c\n",(atual->info),(atual->pai->info));
            }
        }else if(atual->dir!=NULL && atual->esq!=NULL){
            //printf(" TESTE 1 no atual: %c pai do no atual: %c %c\n",(atual->info),(atual->pai->info),arvore->dir->info);
            //arvore->dir=atual->pai;
            atual=atual->pai;
            //printf(" TESTE 2 no atual: %c pai do no atual: %c %c\n",atual->info,(atual->pai->info),atual->pai->dir->info);
        }
    }
    arv_imprime(arvore);
    printf("\n");
    arv_imprime(atual);
}