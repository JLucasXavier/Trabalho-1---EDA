#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

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

void monta_shuting_yard(Pilha* saida, Pilha *operador,char var[],int *tam){
    for (int i = 0; i < strlen(var); ++i)
    {
    	if (var[i] == '+' || var[i] == '-' || var[i] == '*' || var[i] == '/')
    	{
    		if (operador->topo != NULL && ((var[i] == '+') || (var[i] == '-' && (*(operador->topo->a) == '*' || *(operador->topo->a) == '/') ) || (var[i] == '*' && *(operador->topo->a) == '/') ) )
    		{
    		    *tam=*tam+1;
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
    			*tam=*tam+1;
    		}
    		pop_pilha(operador);
    	}

    	else{
    		push_pilha(saida, var[i]);
    		*tam=*tam+1;
    	}
    }
    while(operador->topo != NULL){
    	if (*(operador->topo->a) == '(' || *(operador->topo->a) == ')')
    	{
    		pop_pilha(operador);
    	}
    	else{
    		push_pilha(saida, pop_pilha(operador));
    		*tam=*tam+1;
    	}
    }
    
}

void pilha_libera(Pilha *p){
	Dado *d, *q = p->topo;
	while(q != NULL){
		d = q->prox;
		free(q);
		q = d;
	}
	free(p);
}
