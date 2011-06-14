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

/* Aqui main */
int main(){
  imprimeTabuleiro();
  montaPecas(amazonas); 
  return 0;
}

