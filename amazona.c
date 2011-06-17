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
int 

/* Troca jogador */
int trocaJogador(){
  if (vezJogador == 1) {
    return 0;
  }
  else {
    return 1;
  }
}


/* le posicoes iniciais de movimentacoes e finais para pecas */

/* le posicao final da flecha. Posicao inicial e a posicao final da peca */

/* valida jogadas verificando posicoes e blablabla */

/* processo que monta as mensagens para executar no jogo */



int main(){
  imprimeTabuleiro();
  montaPecas(amazonas); 

  return 0;
}

