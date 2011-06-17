################## Makefile ####################
# Processo de compilacao de todos os arquivos ##
all: tabuleiro
tabuleiro: tabuleiro.o pecas.o amazona.o
	gcc -o amazona tabuleiro.o pecas.o amazona.o
tabuleiro.o: tabuleiro.c
	gcc -o tabuleiro.o -c tabuleiro.c -W -Wall -ansi -pedantic
pecas.o: pecas.c
	gcc -o pecas.o -c pecas.c -W -Wall -ansi -pedantic
amazona.o: amazona.c tabuleiro.h
	gcc -o amazona.o -c amazona.c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o
mrproper: clean
	rm -rf tabuleiro
