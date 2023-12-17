#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	int v[30];
	int ma;
	int me;
	int soma = 0;
	int qnt = 0;
	float media = 0;
	int cont = 0;
	
	printf("Umidade relativa do ar em cada dia do mês:\n");
	
	for(int i=0; i < 30; i++){
		v[i] = 12 + rand() % (81 - 12);
		soma += v[i];
		cont += 1;
		ma = v[i] > ma || i==0 ? v[i] : ma;
		me = v[i] < me || i==0 ? v[i] : me;

		printf("Dia %d: %d\n", (i+1), v[i]);
	}
	
	media = (float)soma / cont;
	printf("A média mensal é de: %.2f\n", media);
	
	for(int i=0; i < 30; i++){
		if(v[i] == ma)
			printf("Dia com maior umidade relativa: %d\n", i + 1);
		if(v[i] == me)
			printf("Dia com menor umidade relativa: %d\n", i +1);
		if(v[i] > media)
			qnt += 1;
	}
	
	printf("A quantidade de dias acima da média é de: %d\n", qnt);
		
	return 0;
}

