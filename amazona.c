/* ===================== main.c ======================= */
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include <windows.h> // inclua esse header se for usar no devc++
//#include <cstdlib> // inclua esse header se for usar no devc++

void gotoxy(int x, int y){
HANDLE hstdout;
    // primeiro pega o handle do stdou STD_OUTPUT_HANDLE
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    //prestes a mover o curor para 10,10
    SetConsoleCursorPosition(hstdout,(COORD) {y,x});
    // done!
}

/* ========== Processo que imprime o tabuleiro ============ */
void imprimeTabuleiro(){
  int i = 0;
  int j = 0;
  gotoxy(0,0);
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
    if (i < 9)
      printf("|------+------+------+------+------+------+------+------+------+------|--\n");
    else
      printf("|---------------------------------------------------------------------|\n");
  }
}

/* processo que imprime as pecas na posicao passada por parametro */
void imprimePecas(char tipoPeca, int x, int y){
  if ((tipoPeca != 'B') &&
    (tipoPeca != 'P') &&
    (tipoPeca != 'F') &&
    (x > 10 ) &&
    (y == 0)){
    gotoxy(34,0);
    printf("Jogada Invalida!\n");
    return;
  }
  x = x * 3;
  y = (y - 1) * 7 + 3;

  x--;
  y--;

  if (tipoPeca == 'B'){
    gotoxy(x,y);
    x++;
    printf("_/\\_\n");
    gotoxy(x,y);
    printf(" \\/ \n");
  }
  else {
    if (tipoPeca == 'P'){
      gotoxy(x,y);
      x++;
      printf("/||\\\n");
      gotoxy(x,y);
      printf(" \\/ \n");
    }
    else{
      if (tipoPeca == 'F'){
        gotoxy(x,y);
        x++;
        printf("/|\\\n");
        gotoxy(x,y);
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

void montaPecas(char amaz[10][10]){
  int i, j;

  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      if (amaz[i][j] != ' '){
        imprimePecas(amaz[i][j],i+1,j+1);
      }
    }
  }
}


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
	system("cls");
	imprimeTabuleiro();
	montaPecas(amazonas);
	gotoxy(33,0);
	if (vezJogador){ /* se for 1, imprime brancas, senao imprime pretas */
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
		return 0;
	}
	return 1;
}


/* valida jogadas verificando posicoes, intervalo da movimentacao e coisas do tipo */
int validaMovimentacao(int xi, char yi, int xf, char yf){
	int i = 0;
	int yni = 0;
	int ynf = 0;

	char texto[3]; /* variavel para esperar a interacao do usuario */

	yni = trocaTipo(yi);
	ynf = trocaTipo(yf);
	xi--;
	xf--;
	yni--;
	ynf--;

	printf("XI: %i, YI: %i, XF: %i, YF: %i", xi, yni, xf, ynf);
	scanf("%s", texto);

	if(vezJogador){
		/* Jogada das pecas Brancas, testa se peca selecionada e branca*/
		if(amazonas[xi][yni] != 'B'){
			printf("Peca selecionada nao e Branca. Selecione uma peca Branca!\n");
			scanf("%s", texto);
			return 0;
		}
	}
	else {
		/* Jogada das pecas Pretas, testa se peca selecionada e preta */
		if(amazonas[xi][yni] != 'P'){
			printf("Peca selecionada nao e Preta. Selecione uma peca Preta!\n");
			scanf("%s", texto);
			return 0;
		}
	}

	/* testa se posicao final ja esta ocupada */
	if(amazonas[xf][ynf] != ' '){
		printf("Destino ja esta ocupado. Selecione outro destino!\n");
		scanf("%s", texto);
		return 0;
	}
	if ((xi == xf) && (yni == ynf)){
		printf("Coordenadas iguais. Defina um destino diferente do inicio!\n");
		scanf("%s", texto);
		return 0;
	}

	if (xi == xf){
		if (yni > ynf){
			for (i = yni - 1; i > ynf; i--){
				if (amazonas[xi][i] != ' '){
					printf("%c\n",amazonas[xi][i]);
					break;
				}
			}
		}
		else {
			for (i = yni + 1; i < ynf; i++){
				if (amazonas[xi][i] != ' '){
					printf("%c\n",amazonas[xi][i]);
					break;
				}
			}
		}
		printf("I:%i YNF:%i\n",i, ynf);
		if (i != ynf){
			printf("Existe uma peca entre o movimento selecionado.\n");
			scanf("%s", texto);
			return 0;
		}
	}
	else{
		if (yni == ynf){
			if (xi > xf){
				for (i = xi - 1; i > xf; i--){
					if (amazonas[i][yni] != ' '){
						printf("%c\n",amazonas[xi][i]);
						break;
					}
				}
			}
			else {
				for (i = xi + 1; i < xf; i++){
					if (amazonas[i][yni] != ' '){
						printf("%c\n",amazonas[xi][i]);
						break;
					}
				}
			}
			printf("I:%i YNF:%i\n",i, ynf);
			if (i != xf){
				printf("Existe uma peca entre o movimento selecionado.\n");
				scanf("%s", texto);
				return 0;
			}
		}
		else {
			if ((xi - xf) == (yni - ynf)){
				if (xi > xf){
					for (i = xi - 1; i < xf; i--){
						if (amazonas[i][yni - (xi - i)] != ' '){
							printf("%c\n",amazonas[xi][i]);
							break;
						}
					}
				}
				else {
					for (i = xi + 1; i > xf; i++){
						if (amazonas[i][yni + (i - xi)] != ' '){
							printf("%c\n",amazonas[xi][i]);
							break;
						}
					}
				}
				printf("I:%i YNF:%i\n",i, ynf);
				if (i != xf){
					printf("Existe uma peca entre o movimento selecionado.\n");
					scanf("%s", texto);
					return 0;
				}
			}
			else {
				if((xi - xf) == ((yni - ynf) * -1)){
					if (xi > xf){
						for (i = xi - 1; i < xf; i--){
							if (amazonas[i][yni + (xi - i)] != ' '){
								printf("%c\n",amazonas[xi][i]);
								break;
							}
						}
					}
					else {
						for (i = xi + 1; i > xf; i++){
							if (amazonas[i][yni - (i - xi)] != ' '){
								printf("%c\n",amazonas[xi][i]);
								break;
							}
						}
					}
					printf("I:%i YNF:%i\n",i, ynf);
					if (i != xf){
						printf("Existe uma peca entre o movimento selecionado.\n");
						scanf("%s", texto);
						return 0;
					}
				}
				else {
					printf("Movimentacao invalida\n");
					scanf("%s", texto);
					return 0;
				}
			}
		}
	}

	/* movimentacao */


	/*
	testa todos os sentidos de movimentacoes possiveis:
		Horizontal: XI = XF ===> 1,2 -> 1,4
		Vertical: YNI = YNF ===> 2,3 -> 4,3
		Diagonal esquerda: (XI - XF) = (YNI - YNF) ===> 0,1 -> 2,3
		Diagonal Direita: (XI - XF) = ((YNI - YNF) * -1) ===> 9,5 -> 7,7

	Depois de verificar o sentido da movimentacao, ver se nao existe nada no meio da movimentacao
	Se existir, mensagem na tela que nao pode pular sobre pecas.
	*/

	scanf("%s", texto);

	/* Se estiver todo certo, nesse mesmo processo ele executa a movimentacao, definindo sua nova
	posicao e limpando a poscao anterior. O movimento seguinte sera o lancamento da flecha, seguindo
	as mesmas regras que a movimentacao */

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
			/* testar validacao para executar movimentacao de forma correta. */
			if (validaMovimentacao(numIni, caracIni, numFim, caracFim)){
				printf("Movimentacao OK\n");
			}
			else {
				goto INICIAL;
			}

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

int main(){
	system("cls");
	imprimeTabuleiro();
	montaPecas(amazonas);

	while (!fimJogo){
		leCoordPeca();
		trocaJogador();
	}

	return 0;
}

