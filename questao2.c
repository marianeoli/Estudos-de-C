#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Faça um programa que preencha um vetor com N números inteiros aleatórios, sorteados no intervalo
 * entre 0 e X. O programa deve imprimir os números sorteados, e ao final o seguinte resumo:
 * a) Quantos números distintos foram sorteados;
 * b) O(s) número(s) mais vezes sorteados;
 * c) O(s) número(s) menos vezes sorteados;
*/

int main(){
	
	int x;
	int n; 
	srand(time(NULL));
	
	printf("Digite a quantidade de números que serão sorteados: \n");
	scanf(" %d", &n);
	printf("Deseja um intervalo entre 0 e? \n");
	scanf(" %d", &x);
	
	int v[n];
	int v1[x+1];
	int diferentes = n;
	
	printf("Os números sorteados são:");
	
	for(int i = 0; i < n; i++){
		v[i] = rand() % (x + 1);
		printf(" %d ", v[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i < n; i++){
		for(int j=0; j < i; j++){
			if(v[j] == v[i])
				diferentes -= 1;
		}
	}
	
	printf("A quantidade de números distintos sorteados é de: %d\n", diferentes);
	
	for(int i = 0; i < (x+1); i++){
		v1[i] = 0;
	}
	
	for(int i = 0; i < (x+1); i++){
		for(int j = 0; j < n; j++){
			if( i == v[j])
				v1[i] += 1;
		}
		
	}
	
	printf("A quantidade de cada número sorteado é de:\n");
	
	
	for(int i = 0; i < (x+1); i++)
		printf("número %d - %d\n", i, v1[i]);
	
	return 0;
}
