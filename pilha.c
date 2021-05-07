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
	if (p == NULL)
	{
		exit(1);
	}

	p->topo = NULL;
	return p;
}

void push_pilha(Pilha *p, char *a){
	Dado *d = (Dado*)malloc(sizeof(Dado));
	if(d == NULL) exit(1);

	strcpy(d->a, a);
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

char * pop_pilha(Pilha *p){
	Dado *d;
	char a[2];
	if (vazia_pilha(p) == 1)
	{
		exit(1);
	}
	d = p->topo;
	strcpy(a, d->a);
	p->topo = d->prox;
	free(d);
	return a;
}

int main(void)
{
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p = cria_pilha();
	char var[ ] = "a";
	push_pilha(p, var);
	printf("%s\n", p->topo->a);
	printf("%c\n", pop_pilha(p));
	system("pause");
	return 0;
}