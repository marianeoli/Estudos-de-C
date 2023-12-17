
/*Faça um programa que usando o símbolo asterisco (*) desenhe na tela uma pirâmide cuja base tenha um tamanho
de N símbolos (O valor de N deverá ser informado pelo usuário e obrigatoriamente deverá ser ímpar).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	
	//declarando o tamanho 
	int N;
	
	//conferindo se é ímpar
	do {
		printf("Digite a tamanho (um número ímpar) desejado para a base do triângulo de simbolo asterisco: \n");
		scanf(" %d", &N);
		if(N % 2 == 0){
			printf("\n");
			printf("Número inválido!\n");
			printf("\n");
		}
	} while (N % 2 == 0);
	
	//fazendo o triângulo
	for(int i = N+1; i >= 2; i--){
		for(int j = 0; j < (i - 1); j++){
			printf(" ");
		}
		for(int k = 0; k <= (N - i)+1; k++){
			printf(" *");
		}
		printf("\n");
	}
	
	return 0;
}
