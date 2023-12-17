
/*Faça um programa que receba um número e verifique se ele é ou não um número perfeito.
Um número é perfeito quando a soma de todos os seus divisores inteiros – excluindo ele mesmo – é igual ao próprio
número. Ex: 28 = 1 + 2 + 4 + 7 + 14.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	
	int n;
	int perfeito;
	int imperfeito;
	
	printf("Digite um número: \n");
	scanf(" %d", &n);
	
	for(int i = 1; i < n; i++){
		perfeito += (n%i) == 0 ? i : 0;
		imperfeito += (n%i) != 0 ? i : 0;
	}
	
	if(n == perfeito)
		printf("Ele é um número perfeito!");
	else 
		printf("Ele não é um número perfeito");
		
	return 0;
}

