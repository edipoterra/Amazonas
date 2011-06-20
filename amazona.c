/* ===================== main.c ======================= */
#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "pecas.h"

/* ==== Matriz principal do programa ==== */
char amazonas[10][10] = {
	{' ',' ',' ','P',' ',' ','P',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'P',' ',' ',' ',' ',' ',' ',' ',' ','P'},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'B',' ',' ',' ',' ',' ',' ',' ',' ','B'},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ','B',' ',' ','B',' ',' ',' '}
};

int vezJogador = 0; /* faz a troca de jogadores */
int fimJogo = 0; 	/* define o fim do jogo */

/* funcao que faz a troca de jogador */
void trocaJogador(){
	if (vezJogador == 1) {
		vezJogador = 0;
	}
	else {
		vezJogador = 1;
	}
}

/* Le posicao final da flecha. Posicao inicial e a posicao final da peca */
void leCoorFlecha(){
	printf("Le coordenadas flecha");
}

/* Atualiza e desenha a tela com as posicoes  */
void desenhaTela(){
	system("clear");
	imprimeTabuleiro();
	montaPecas(amazonas);
	printf("\033[033;0f");
	if (vezJogador == 1){
		printf("Pecas Brancas:\n");
	}
	else {
		printf("Pecas Pretas:\n");
	}
}

/* processo de validacao das coordenadas passadas por parametro */
int validaCoordenadas(int num, char carac){
	if ((num < 1) || (num > 10)){
		desenhaTela();
		printf("Coordenada Invalida! X\n");
		return 0; 
	}
	if ((carac != 'A') && (carac != 'a') &&
		(carac != 'B') && (carac != 'b') &&
		(carac != 'C') && (carac != 'c') &&
		(carac != 'D') && (carac != 'd') &&
		(carac != 'E') && (carac != 'e') &&
		(carac != 'F') && (carac != 'f') &&
		(carac != 'G') && (carac != 'g') &&
		(carac != 'H') && (carac != 'h') &&
		(carac != 'I') && (carac != 'i') &&
		(carac != 'J') && (carac != 'j')){
			
		desenhaTela();
		printf("Coordenada Invalida! Y\n");
		return 0;
	}
	return 1;
}

/* le posicoes iniciais de movimentacoes e finais para pecas */
void leCoordPeca(){
	char texto[3];
	int numIni;
	int numFim;
	char caracIni;
	char caracFim;
	
	INICIAL:
	desenhaTela();
	printf("Entre com as coordenadas iniciais da peca: \n");
	scanf("%s",texto);

	if (texto[2] != '\0'){
		caracIni = texto[2];
		numIni = (texto[0] - '0') * 10 + (texto[1] - '0');
	}
	else{
		caracFim = texto[1];
		numFim = texto[0] - '0';
	}

	if (validaCoordenadas(numIni,caracIni)){
		FINAL:
		desenhaTela();
		printf("Entre com as coordenadas finais da peca: \n");
		scanf("%s",texto);

		if (texto[2] != '\0'){
			caracFim = texto[2];
			numFim = (texto[0] - '0') * 10 + (texto[1] - '0');
		}
		else{
			caracFim = texto[1];
			numFim = texto[0] - '0';
		}
		
		if (validaCoordenadas(numFim,caracFim)){
			printf("validando e executando movimentacao\n");
			leCoorFlecha();
		}
		else {
			goto FINAL;
		}
	}
	else {
		goto INICIAL;
	}
	return;
}

/* valida jogadas verificando posicoes e blablabla */
void validaMovimentacao(){
	printf("Valida movimentacao");
}

/*  processo que monta as mensagens para executar no jogo 
void montaMensagens(){
	if (vezJogador == 1){
		printf("Pecas Brancas:\n");
	}
	else {
		printf("Pecas Pretas:\n");
	}
	leCoordPeca();
} */

int main(){
	system("clear");
	imprimeTabuleiro();
	montaPecas(amazonas); 

	while (!fimJogo){
		leCoordPeca();
		trocaJogador();
	}
/*	leCoordPeca();
	leCoordPeca();
	leCoordPeca(); */

	return 0;
}

