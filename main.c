#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "arvBin.h"

int main(void){
    //Inicializando a pilha
    Pilha *num = (Pilha*)malloc(sizeof(Pilha));
    num = cria_pilha();
    Pilha *operador = (Pilha*)malloc(sizeof(Pilha));
    operador = cria_pilha();
    
    // Pegando a expressão do usuário
    char s1[100];
    printf("Digite uma expressão que deseja resolver: ");
    scanf("%s",s1);
    
    //Utilizando o algoritmo de Shunting Yard para traduzir a expressão do formato infix para o formato postfix
    int tamanho=0;
    char buffer[50];
    monta_shuting_yard(num, operador,s1,&tamanho);
    
    //Passando a expressão em postfix da pilha para dentro de uma variável string para ser passada como parâmetro na árvore de expressão 
    for (int i = tamanho-1; num->topo != NULL;i--){
        buffer[i]=pop_pilha(num);
	}
	
	//Mostrando a expressão no formato postfix
	printf("A expressão em postfix é: %s\n",buffer);
	
	//Criando uma árvore de expressão, imprimindo a árvore de expressão e apresentando o resultado da expressão ao usuário
	arvore_expressao(buffer);
	
	
	//Liberando a pilha
	pilha_libera(num);
	pilha_libera(operador);
	
    return 0;
}