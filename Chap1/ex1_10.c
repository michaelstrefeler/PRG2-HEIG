/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_10.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 15.03.2022

 Description    : printf(2)

 Remarque(s)    : Code à compléter

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int n = 255;
	double x = 12.345;

	printf("%#o\n", n); // 0377
	printf("%X\n", n); //FF
	printf("%+07d\n", n); // +###255
	printf("%.3e\n", x); // 1.235e+001 (pas possible) 1.235e+01
	printf("%g\n", x); // 12.345
	printf("%.4f\n", x); // 12.345
   return EXIT_SUCCESS;
}
