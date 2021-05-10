#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvBin{
    char info;
    struct arvBin* esq;
    struct arvBin* dir;
    struct arvBin* pai;
}ArvBin;

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
        arv_libera(arvore->pai);
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
                //printf("no atual: %c pai do no atual: %c %c\n",(atual->info),(atual->pai->info),atual->esq->info);
                //arv_imprime(arvore);
            }
        }
        else if(atual->dir!=NULL && atual->esq!=NULL){
            //printf(" TESTE 1 no atual: %c pai do no atual: %c %c %c\n",(atual->info),(atual->pai->info),arvore->dir->info,arvore->info);
            ArvBin* temp=arvore->dir;
            arvore->dir=atual->pai;
            arvore->dir->dir=temp;
            //printf("VAMO VER COMO TÁ AQUI\n");
            //arv_imprime(arvore);
            //printf("\n");
            atual=atual->pai;
            //printf("FUNCIONOU");
            //printf(" TESTE 2 no atual: %c pai do no atual: %c %c %c\n",(atual->info),(atual->pai->info),arvore->dir->info,arvore->info);
        }
        
    }
    arv_imprime(arvore);
    printf("\no resultado da expressão é %d",calcular_expressao(arvore));
}

int main(void){
    char exp[] ="2384-*+";
    arvore_expressao(exp);
}