#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <gconio.h>

typedef struct{
		int x,y;
}Ponto;


int main(){

	Ponto v[10], p;
	int dis,menor,alvo;
	srand(time(NULL));
	for (int i = 0; i < 10; i++){ //valor de x
		v[i].x= 1 + rand()%80;
	}
	for (int i = 0; i < 10; i++){ //valor de y
		v[i].y= 1 + rand()%20;
	}
	for (int i = 0; i < 10; i++){ //printar tabela
		gotoxy(v[i].x,v[i].y);
		printf("%d", i);
	}
	gotoxy(1,21); 
	printf("Diga sua jogada (x y): ");
	scanf(" %d %d", &p.x, &p.y);
	gotoxy(p.x,p.y);
	printf("X");

	for (int i = 0; i < 10; i++){
		dis=sqrt(((p.x-v[i].x)*(p.x-v[i].x))+((p.y-v[i].y)*(p.y-v[i].y)));
		menor= menor>dis || i==0? dis : menor;						//ver o mais perto
		alvo= menor==dis? i : alvo;
	}
	gotoxy(1,22);
	printf("O ponto mais proximo é: %d", alvo); //dizer


	return 0;
}

