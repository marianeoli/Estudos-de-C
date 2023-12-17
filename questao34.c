/*Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre X e Y (inclusive).
Imprima-a em formato de tabela, e os valores que compõem a coluna que resulta na maior soma, e os
valores da linha que resulta na menor soma.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	
	int N; 
	int somacoluna = 0;
	//int somalinha = 0;
	int masoma;
	//int mesoma;
	
	printf("Digite o tamanho da matriz: ");
	scanf(" %d", &N);
	printf("\n");
	
	int x;
	int y;
	
	printf("Digite o intervalo de números desejados: ");
	scanf(" %d %d", &x, &y);
	printf("\n");
	
	int m[N][N];
	srand(time(NULL));
	int indice;
	
	printf("A matriz com os números sorteados: \n");
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			m[i][j] = x + rand() % (y + 1 - x);
			printf(" %d", m[i][j]);
		}
		printf("\n");
	}
	
	/*for(int i = 0; i < n + 1; i++){
		v[i] = 0;
	}*/
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			somacoluna += m[j][i];
		}
		//masoma = somacoluna > masoma ? somacoluna : masoma;
		if(somacoluna >= masoma){
			masoma = somacoluna;
			indice = i;
		}
		printf("soma da coluna %d: %d\n", i + 1, somacoluna);
		somacoluna = 0;
	}
	
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(indice == j)
				printf("O maior valor de soma: %d\n", m[i][j]);
		}
	}
	return 0;
}

