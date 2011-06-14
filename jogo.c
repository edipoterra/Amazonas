#include <stdio.h>
#include <stdlib.h>

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
	{' ',' ',' ','B',' ',' ','B',' ',' ',' '}};

/* processo que mostra o tabuleiro do jogo na tela */
void imprimeTabuleiro(){
	int i = 0;
	int j = 0;
	printf("|  A   |  B   |  C   |  D   |  E   |  F   |  G   |  H   |  I   |  J   |\n");
	printf("|------|------|------|------|------|------|------|------|------|------|--\n");
	for (i = 0; i < 10; i++){
		for (j = 0; j < 2; j++){
			if (j % 2 == 1){
				printf("|      |      |      |      |      |      |      |      |      |      |\n");
			} 
			else {
				printf("|      |      |      |      |      |      |      |      |      |      | %i\n", i+1);
			}
		}
		if (i < 9){
			printf("|------+------+------+------+------+------+------+------+------+------|--\n");
		}
	}
	printf("|---------------------------------------------------------------------|\n");
}

/* processo que imprime as pecas na posicao passada por parametro */
void imprimePecas(char tipoPeca, int x, int y){
	if ((tipoPeca != 'B') && 
		(tipoPeca != 'P') && 
		(tipoPeca != 'F') &&
		(x > 10 )		  &&
		(y == 0)){
		printf("\033[34;0f");
		printf("Jogada Invalida!\n");
		return;
	}
			
	x = x * 3;
	y = (y - 1) * 7 + 3;
	
	if (tipoPeca == 'B'){
		printf("\033[%i;%if",x,y);
		x++;
		printf("_/\\_\n");
		printf("\033[%i;%if",x,y);
		printf(" \\/ \n");
	}
	else {
		if (tipoPeca == 'P'){
			printf("\033[%i;%if",x,y);
			x++;
			printf("/||\\\n");
			printf("\033[%i;%if",x,y);
			printf(" \\/ \n");			
		}
		else{
			if (tipoPeca == 'F'){
				printf("\033[%i;%if",x,y);
				x++;
				printf("/|\\\n");
				printf("\033[%i;%if",x,y);
				printf(" | \n");							
			}
		}
	}
}

/* recebe letra e converte para numero, para parametrizar coordenadas */
int trocaTipo(char letra){
	switch (letra){
		case 'A':	return 1;
		case 'B':	return 2;
		case 'C':	return 3;
		case 'D':	return 4;
		case 'E':	return 5;
		case 'F':	return 6;
		case 'G':	return 7;
		case 'H':	return 8;
		case 'I':	return 9;
		case 'J':	return 10;
		default: 	return 0;
	}
}

void montaPecas(){
	int i, j;
	char aux;
	
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			if (amazonas[i][j] != ' '){
				imprimePecas(amazonas[i][j],i+1,j+1);
			}
		}
	}
	
}

int main(){
	system("clear");
	imprimeTabuleiro();
	montaPecas();


  	return 0;

}

