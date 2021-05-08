#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Pilha *cria_pilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL){
        exit(1);
    }
    p->topo = NULL;
    return p;
}

void push_pilha(Pilha *p, char a){
    Dado *d = (Dado*)malloc(sizeof(Dado));
    if(d == NULL) exit(1);
    strcpy(d->a, &a);
    d->prox = p->topo;
    p->topo = d;
}

int vazia_pilha(Pilha *p){
    if (p->topo == NULL)
    {
        return 1;
    }
    return 0;
}

char pop_pilha(Pilha *p){
    Dado *d = (Dado*)malloc(sizeof(Dado));
    if (vazia_pilha(p) == 1){
        exit(1);
    }
    d = p->topo;
    //printf("%c teste1\n",*d->a);
    char a=*(d->a);
    //printf("%c teste2\n",a);
    p->topo = d->prox;
    free(d);
    return a;
}

void monta_shuting_yard(Pilha* saida, Pilha *operador){
	char var[] = "((a*b)-(c*d))/(e*f)";
    for (int i = 0; i < strlen(var); ++i)
    {
    	if (var[i] == '+' || var[i] == '-' || var[i] == '*' || var[i] == '/')
    	{
    		if (operador->topo != NULL && ((var[i] == '+') || (var[i] == '-' && (*(operador->topo->a) == '*' || *(operador->topo->a) == '/') ) || (var[i] == '*' && *(operador->topo->a) == '/') ) )
    		{
    			push_pilha(saida, pop_pilha(operador));
    		}
    		
    		push_pilha(operador, var[i]);
    	}
    	
    	else if (var[i] == '(')
    	{
    		push_pilha(operador, var[i]);	
    	}

    	else if (var[i] == ')'){
    		while(*(operador->topo->a) != '('){
    			push_pilha(saida, pop_pilha(operador));
    		}
    		pop_pilha(operador);
    	}

    	else{
    		push_pilha(saida, var[i]);
    	}
    }
    while(operador->topo != NULL){
    	if (*(operador->topo->a) == '(' || *(operador->topo->a) == ')')
    	{
    		pop_pilha(operador);
    	}
    	else{
    		push_pilha(saida, pop_pilha(operador));
    	}
    }
}

//void esvaziar_pilha(Pilha *num){
//	for (int i = 0; num->topo != NULL; ++i)
//	{
//		printf("%c\n", pop_pilha(num));
//	}
//}

void pilha_libera(Pilha *p){
	Dado *d, *q = p->topo;
	while(q != NULL){
		d = q->prox;
		free(q);
		q = d;
	}
	free(p);
}

int main(void){
    Pilha *num = (Pilha*)malloc(sizeof(Pilha));
    num = cria_pilha();
    Pilha *operador = (Pilha*)malloc(sizeof(Pilha));
    operador = cria_pilha();

    monta_shuting_yard(num, operador);
    //esvaziar_pilha(num);
    system("pause");
    return 0;
}