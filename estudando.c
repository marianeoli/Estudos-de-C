#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct{
	char nome[100];
	int idade;
	float altura;
	float peso;
}Pessoa;

int main(){
	
	Pessoa individuo;
	
	printf("Digite seu nome:\n");
	scanf(" %[^\n]s", individuo.nome);
	printf("Digite sua idade:\n");
	scanf(" %d", &individuo.idade);
	printf("Digite sua altura:\n");
	scanf(" %f", &individuo.altura);
	printf("Digite seu peso:\n");
	scanf(" %f", &individuo.peso);
	
	system("clear");
	
	printf("a) Informações lidas:\n");
	printf("Nome: %s\nIdade: %d\nAltura: %.2f\nPeso: %.2f\n", individuo.nome, individuo.idade, individuo.altura, individuo.peso);
	
	float imc = individuo.peso/(individuo.altura*individuo.altura);
	
	printf("b) Seu IMC(Índice de Massa Corpóreas) é de: %.2f\n", imc);
	
	if(imc < 18.5)
		printf("c) Seu resultado levando em consideração o seu IMC: Abaixo do peso\n");
	if((imc >= 18.5) && (imc <= 24.9))
		printf("c) Seu resultado levando em consideração o seu IMC: saudável\n");
	if((imc >= 25) && (imc <= 29.9))
		printf("c) Seu resultado levando em consideração o seu IMC: Acima do peso\n");
	if(imc >= 30)
		printf("c) Seu resultado levando em consideração o seu IMC: Obesidade\n");
	
	return 0;
}

