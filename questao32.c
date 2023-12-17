
/*Em uma eleição para representante da turma, existem K candidatos. Faça com que seu programa leia o
valor de K e o nome de cada um dos candidatos.
Após isso, programe uma espécie de urna eletrônica, onde o voto do candidato é representado pelo seu
número de sequência de cadastro na urna (p.ex.: 1 - 2 - 3 - ... - K).
O valor 0 corresponde a um voto em BRANCO, e um valor superior a K representa um voto NULO.
A votação deve ser encerrada assim que for informado um voto com valor negativo.
Ao final da votação, seu programa deve gerar o seguinte relatório:
a) A quantidade total de votos;
b) O nome e a quantidade de votos para cada candidato;
c) A quantidade de votos nulos;
d) A quantidade de votos em branco;
e) O nome do vencedor das eleições;
f) O percentual do vencedor em relação ao número de votos válidos;*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main(){
	
	//declarei o que ia ser usado
	int k;
	int vot;
	int cont = 0;
	int branco = 0;
	int nulo = 0;
	int vencedor;
	int validos;
	float percentual;
	
	//pedi a quantidade de candidatos
	printf("Digite a quantidade de candidatos: \n");
	scanf(" %d", &k);
	
	//Declarei a string e o vetor da quantidade de votos de cada candidato
	char nomes[k][100];
	int qnt[k];
	
	//inicializei o vetor da quantidade
	for(int i = 0; i < k; i++)
		qnt[i] = 0;
			
	//Defini o nome que seria armazenado em cada índice
	printf("Digite o nome deles: \n");
	
	for(int i = 0; i < k; i++)			//ler dentro de um for de string
		scanf(" %[^\n]s", nomes[i]);
	
	//para saber a hora de parada (quando número negativo for digitado)
	do{
		cont += 1;  //para contar a quantidade de votos no total
		
		//printei os candidatos e o número para voto
		printf("\nVoto em branco = 0\n");
		printf("Voto nulo > %d\n", k);
		printf("Encerrar votação < 0\n");
		for(int i = 0; i < k; i++){
			printf("Candidato %s: [%d]\n", nomes[i], i + 1);
		}
		
		//li o voto
		printf("\nSeu voto: ");
		scanf(" %d", &vot);
		printf("\n");
		
		//contei a quantidade de votos brancos e nulos
		branco += vot == 0 ? 1 : 0;
		nulo += vot > k ? 1 : 0;
		
		//contei a quantidade de votos para cada candidato e de cada voto válido
		for(int i = 0; i < k; i++){
			if(vot == i + 1){
				qnt[i] += 1;
				validos += 1;
			}
		}
		
	} while (vot >= 0);
	
	//tirei o número negativo digitado
	cont -= 1;
	
	printf("Votação encerrada!\n");
	
	//respostas das questões
	printf("a) A quantidade total de votos é de: %d\n", cont);
	printf("b) A quantidade de votos de cada candidado: \n");
	
	for(int i = 0; i < k; i++){
		printf("Candidato %s: %d\n", nomes[i], qnt[i]);
	}
	
	printf("c) Quantidade de votos nulos: %d\n", nulo);
	printf("d) Quantidade de votos brancos: %d\n", branco);
	
	//definindo o vencedor e tirando o percentual
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			vencedor = qnt[j] > qnt[i] || i == 0 ? j : vencedor;
		}
		
		if(vencedor == i){
		printf("e) O candidato vencedor é: %s\n", nomes[i]);	//printando o vencedor e tirando o percentual
		percentual = (float)(qnt[i] * 100) / validos;
		}
	}
	
	//printando o percentual
	printf("f) O percentual do vencedor em relação à quantidade de votos válidos é de: %.2f", percentual);

	return 0;
}
