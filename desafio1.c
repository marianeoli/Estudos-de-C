#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <gconio.h>

typedef struct{
	int ataque[10];
	int defesa[10];
	int ambiente, carta, atk;
	char escolha[7];
}Jogo;

int main(){
	
	Jogo jogada;
	int rodada = 0, hp = 0, hppc = 0;
	srand(time(NULL));
	
	printf("O JOGO COMEÇOU!\n");
	for(int i = 0; i < 10; i++){
		jogada.ataque[i] = rand() % 100;
		jogada.defesa[i] = rand() % 100;
	}
	
	do{
		
		printf("Carta\tAtaque\tDefesa\n");
		for(int i = 0; i < 10 - rodada; i++)
			printf("[%d]\t%d\t%d\n", i, jogada.ataque[i], jogada.defesa[i]);
		
		while(jogada.carta < 0 || jogada.carta > (9 - rodada)){
			printf("Escolha uma carta carta válida:\n");
			scanf(" %d", &jogada.carta);
		}
		
		printf("Jogar com o ataque ou defesa?\n");
		scanf(" %[^\n]s", jogada.escolha);
		
		while(jogada.ambiente < 0 || jogada.ambiente > 2){
			printf("Escolha um ambiente válido:\n[0]Verde\n[1]Vermelho\n[2]Amarelo\n");
			scanf(" %d", &jogada.ambiente);
		}
		
		jogada.ambiente == 0 ? textbackground(GREEN) : 0;
		jogada.ambiente == 1 ? textbackground(RED) : 0;
		jogada.ambiente == 2 ? textbackground(YELLOW) : 0;
		clrscr();
		
		for(int i = 0; i < 10 - rodada; i++){
			if(jogada.carta == i){
				if(strcmp(jogada.escolha, "ataque") == 0)
					printf("[%d]\tataque: %d\n", i, jogada.ataque[i]);
				if(strcmp(jogada.escolha, "defesa") == 0)
					printf("[%d]\tdefesa: %d\n", i, jogada.defesa[i]);
			}
		}
		
		jogada.atk = rand() % 3;
		jogada.atk == 0 ? textbackground(GREEN) : 0;
		jogada.atk == 1 ? textbackground(RED) : 0;
		jogada.atk == 2 ? textbackground(YELLOW) : 0;
		clrscr();
		if(jogada.atk == jogada.ambiente){
			printf("Ambiente igual! Sua jogada dobrou: ");
				for(int i = 0; i < 10 - rodada; i++){
					if(jogada.carta == i){
						if(strcmp(jogada.escolha, "ataque") == 0){
							jogada.ataque[i] *= 2;
							printf("%d\n", jogada.ataque[i]);
						}
						if(strcmp(jogada.escolha, "defesa") == 0){
							jogada.defesa[i] *=2;
							printf("%d\n", jogada.defesa[i]);
						}
					}
				}
		}
		
		jogada.atk = rand() % 100;
		printf("Você foi atacado com: %d\n", jogada.atk);
		
		for(int i = 0; i < 10 - rodada; i++){
			if(jogada.carta == i){
				if(strcmp(jogada.escolha, "ataque") == 0){
					hp -= jogada.atk > jogada.ataque[i] ? jogada.atk - jogada.ataque[i] : 0;
					hppc -= jogada.atk < jogada.ataque[i] ? jogada.ataque[i] - jogada.atk : 0;
				}
				if(strcmp(jogada.escolha, "defesa") == 0){
					hppc += jogada.atk > jogada.defesa[i] ? jogada.atk - jogada.defesa[i] : 0;
					hp += jogada.atk < jogada.defesa[i] ? jogada.defesa[i] - jogada.atk : 0;
				}
				printf("Seu HP: %d\nHP do PC: %d\n", hp, hppc);
			}
		}
		
		for(int i = jogada.carta; i < 10 - rodada; i++){
			jogada.ataque[i] = jogada.ataque[i + 1];
			jogada.defesa[i] = jogada.defesa[i + 1];
		}
		
		jogada.carta = 0;
		jogada.ambiente = 0;
		rodada += 1;
		printf("\n");
		
	}while(rodada < 10);
	
	if(hp > hppc)
		printf("VOCÊ VENCEU!\n");
	else
		printf("PC VENCEU!\n");
	
	return 0;
}

