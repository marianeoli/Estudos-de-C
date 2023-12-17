
/*Escreva um programa em C para ler uma frase. A seguir, imprima a frase com: (a) todas as letras
maiúsculas, (b) todas as letras minúsculas, (c) início de cada palavra em maiúsculo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(){
	
	//declarei a string
	
	char frase[100];
	
	//pedi uma frase
	
	printf("Digite uma frase: ");
	scanf(" %[^\n]s", frase);
	printf("\n");
	
	//transformando em maiúsculas
	
	for(int i = 0; frase[i] != '\0'; i++){
		frase[i] = toupper(frase[i]);
	}
	
	printf("a) Todas as letras maiúsculas: %s\n", frase);
	
	//transformando em minúsculas
	
	for(int i = 0; frase [i] != '\0'; i++){
		frase[i] = tolower(frase[i]);
	}
	
	printf("b) Todas as letras minúsculas: %s\n", frase);
	
	//iniciando a palavra com maiúsculo
	
	for(int i = 0; frase[i] != '\0'; i++){
		if(i == 0 || frase[i - 1] == ' ')
			frase[i] = toupper(frase[i]);
	}
	
	printf("c) Início de cada palavra em maiúsculo: %s\n", frase);
	
	return 0;
}

