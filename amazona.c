/* ===================== main.c ======================= */
#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "pecas.h"

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
int vezJogador = 0;
int fimJogo = 0;

/* Troca jogador */
void trocaJogador(){
	if (vezJogador == 1) {
		vezJogador = 0;
	}
	else {
		vezJogador = 1;
	}
}

/* processo de validacao das coordenadas passadas por parametro */
int validaCoordenadas(int num, char carac){
	printf("%i\n",num);
	printf("%c\n",carac);
	if ((num < 1) || (num > 10)){
		printf("\033[34;0f");
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

		printf("\033[34;0f");
		printf("Coordenada Invalida! Y\n");
		return 0;
	}
	return 1;
}

/* le posicoes iniciais de movimentacoes e finais para pecas */
void leCoordPeca(){
	char texto[3];
	int numero;
	char caracter;
	printf("Entre com as coordenadas iniciais da peca: \n");
	scanf("%s",texto);

	if (texto[2] != ' '){
		caracter = texto[2];
		numero = (texto[0] - '0') * 10 + (texto[1] - '0');
	}
	else{
		caracter = texto[1];
		numero = texto[0] - '0';
	}
	if (validaCoordenadas(numero,caracter)){
		printf("verdadeiro");
	}
	else {
		printf("falso");
	}

	return;
}

/* le posicao final da flecha. Posicao inicial e a posicao final da peca */
void leCoorFlecha(){
	printf("Le coordenadas flecha");
}

/* valida jogadas verificando posicoes e blablabla */
void validaMovimentacao(){
	printf("Valida movimentacao");
}

/* processo que monta as mensagens para executar no jogo */
void montaMensagens(){
	if (vezJogador == 1){
		printf("Pecas Brancas:\n");
	}
	else {
		printf("Pecas Pretas:\n");
	}
	leCoordPeca();
}

int main(){
/*	system("clear");
	imprimeTabuleiro();
	montaPecas(amazonas); 

	while (!fimJogo){
		montaMensagens();
		trocaJogador();
	} */
	leCoordPeca();
	leCoordPeca();
	leCoordPeca();

	return 0;
}

