#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <gconio.h>

typedef struct{
	int ataque[10];
	int ambiente;
	int carta;
	char escolha[7];
	int atk;
}Jogo;

int main(){
	
	Jogo jogada;
	int hp = 1000;
	int hppc = 1000;
	int rodada = 0;
	srand(time(NULL));
	
	printf("O JOGO COMEÇOU!\n");
	
	for(int i = 0; i < 10; i++)
		jogada.ataque[i] = rand() % 100;
	
	do{
		printf("Carta\tAtaque\n");
		for(int i = 0; i < (10 - rodada); i++){
		printf(" [%d]\t %d\n", i, jogada.ataque[i]);
		}
		
		jogada.carta = -1;
		while(jogada.carta < 0 || jogada.carta > (10 - rodada)){
			printf("Escolha sua carta:\n");
			scanf(" %d", &jogada.carta);
			if(jogada.carta > (10 - rodada) || jogada.carta < 0)
				printf("Ínválida!\n");
		}

		while(jogada.ambiente < 0 || jogada.ambiente > 2){
			printf("Escolha um ambiente válido:\n[0]Verde\n[1]Amarelo\n[2]Vermelho\n");
			scanf(" %d", &jogada.ambiente);
		}
			jogada.ambiente == 0 ? textbackground(GREEN) : 0;
			jogada.ambiente == 1 ? textbackground(YELLOW) : 0;
			jogada.ambiente == 2 ? textbackground(RED) : 0;
			clrscr();
			
		for(int i = 0; i < (10 - rodada); i++){
			if(jogada.carta == i)
				printf("[%d]\t%i\n", i, jogada.ataque[i]);
		}
			
		jogada.atk = rand() % 3;
		jogada.atk == 0 ? textbackground(GREEN) : 0;
		jogada.atk == 1 ? textbackground(YELLOW) : 0;
		jogada.atk == 2 ? textbackground(RED) : 0;
		if(jogada.ambiente == jogada.atk){
			for(int i = 0; i < (10 - rodada); i++){
				if(jogada.carta == i){
					jogada.ataque[i] *= 2;
					printf("Ambiente igual! Seu valor de ataque foi dobrado: %d\n", jogada.ataque[i]);
				}
			}
		}
		
		clrscr();
		
		jogada.atk = rand() % 100;
		printf("Você foi atacado com %d\n",jogada.atk);
		for(int i = 0; i < (10 - rodada); i++){
			if(jogada.carta == i){
				hp -= jogada.atk > jogada.ataque[i] ? jogada.atk - jogada.ataque[i] : 0;
				hppc -= jogada.atk < jogada.ataque[i] ? jogada.ataque[i] - jogada.atk : 0;
				for(int i = jogada.carta; i < (10 - rodada); i++)
					jogada.ataque[i] = jogada.ataque[i+1];
			}
		}
		
		printf("Seu HP = %d\nHP do PC: %d\n", hp, hppc);
		rodada += 1;
		jogada.ambiente = -1;
		printf("\n");
		
} while(rodada < 10);
	
	if(hp > hppc)
		printf("Você venceu!\n");
	else
		printf("O pc venceu!\n");

	return 0;
}

