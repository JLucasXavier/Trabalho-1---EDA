#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "arvBin.h"

int main(void){
    Pilha *num = (Pilha*)malloc(sizeof(Pilha));
    num = cria_pilha();
    Pilha *operador = (Pilha*)malloc(sizeof(Pilha));
    operador = cria_pilha();
    int tamanho=0;
    char var[] = "((a*b)-(c*d))/(e*f)";
    char temp[1000];
    monta_shuting_yard(num, operador,var,&tamanho);

    for (int i = tamanho-1; num->topo != NULL;i--){
        temp[i]=pop_pilha(num);
	}
	
	pilha_libera(num);
	pilha_libera(operador);
	printf("A STRING EH ESSA AQUI: %s\n",temp);
	
	arvore_expressao(temp);
    
    return 0;
}