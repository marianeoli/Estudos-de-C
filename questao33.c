
/*Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre X e Y (inclusive).
Imprima-a em formato de tabela (linhas e colunas) e informe a localização do maior e do menor valor da
matriz.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	
	int linhas;
	int colunas;
	int x;
	int y;
	int ma;
	int ma_i;
	int ma_j;
	
	printf("Digite, respectivamente, a quantidade de linhas e colunas que deseja na matriz: \n");
	scanf(" %d %d", &linhas, &colunas);
	printf("Digite o intervalo que deseja que seja sorteado: \n");
	scanf(" %d %d", &x, &y);
	
	srand(time(NULL));
	int m [linhas] [colunas];
	
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			m[i][j] = x + rand() % (y+1) - x;
			printf(" %d", m[i][j]);
		}
		
		printf(" \n");
		
	}
	
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			ma = m[i][j] > ma || i == 0 ? m[i][j] : ma;
		}
	}
	
	printf("O maior número é %d e suas respectivas localizações são: \n", ma);
	
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(ma == m[i][j]){
				ma_i = i + 1;
				ma_j = j + 1;
				printf("Linha: %d - Coluna: %d\n", ma_i, ma_j);
			}
		}
	}
		
	return 0;
}

