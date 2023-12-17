#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	
	int n;
	int x; 
	int cont = 0;
	srand(time(NULL);
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	printf("Digite o intervalo a ser sorteado: ");
	scanf("%d", &x);
	int v[n];
	
	printf("Números Sorteados:");
	for(int i=0; i<n; i++){
		v[i]= rand() % x;
		printf("\n%d", v[i]);
		for(int j=0; j < i; j++){
				if(v[i] != v[j])
					cont++;
		}
	}
	printf("%d", cont);
	
	return 0;
}

