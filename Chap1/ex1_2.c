/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_2.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 28.02.2022

 Description    : Exercice 1.2

 Remarque(s)    : Macros (1)

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define A 2
#define B ((A)+1)
#define PLUS(X,Y) ((X)+(Y))
#define MOINS(X,Y) ((X)-(Y))

int main(void) {

	printf("%d %d\n", 5*PLUS(A,B), MOINS(A+1,B+1));

	return EXIT_SUCCESS;
}
