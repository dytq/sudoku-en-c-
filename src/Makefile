CFLAGS = -g -Wall -c
CFLAGSGR = ${CFLAGS} `sdl-config --cflags`
LFLAGS = -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

run: sudoku
	./sudoku niveau1.sudoku

# Edition de lien du programme principal
sudoku: sudoku.o afficher.o gestion_sudoku.o lire_ecrire.o pile.o
	gcc -o $@ $^ ${LFLAGS}

# Compilation du programme principal
sudoku.o: sudoku.c lire_ecrire.h gestion_sudoku.h constantes.h pile.h
	gcc ${CFLAGSGR} $*.c

# Compilation des différents.o
afficher.o: afficher.c afficher.h gestion_sudoku.h constantes.h pile.h
	gcc ${CFLAGSGR} $*.c

gestion_sudoku.o: gestion_sudoku.c gestion_sudoku.h pile.h
	gcc ${CFLAGS} $*.c

lire_ecrire.o: lire_ecrire.c lire_ecrire.h gestion_sudoku.h
	gcc ${CFLAGS} $*.c

pile.o: pile.c pile.h  constantes.h
	gcc ${CFLAGS} $*.c

# Pour faire un zip
# Mettre son nom à la place de SUDOKU
LENOM=xx_xx
zip:
	rm -rf ${LENOM}
	rm -rf ${LENOM}.zip
	mkdir ${LENOM}
	cp Makefile ${LENOM}
	cp *.h *.c ${LENOM}
	cp help.me ${LENOM}
	zip -r ${LENOM}.zip ${LENOM}
	rm -rf ${LENOM}
	mv  ${LENOM}.zip ..
