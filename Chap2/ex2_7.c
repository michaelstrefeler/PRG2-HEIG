/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_7.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 28.03.2022

 Description    : Arithmétique des pointeurs (1)

 Remarque(s)    : Que va afficher le programme main ci-dessous?

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <inttypes.h>
#include <stddef.h> // pour ptrdiff_t
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int a[] = {10, 20, 30, 40, 50};
	int* p[] = {a, a+1, a+2, a+3, a+4};
	int** pp = &p[2];
	int*** ppp = &pp;
	printf("1) %d\n", *a);
	printf("2) %d\n", **p);
	printf("3) %d\n", **pp++);
	printf("4) %d\n", ***ppp);
	pp = p;
	printf("5) %d\n", **++pp);
	pp = p;
	printf("6) %d\n", ++**pp);
	pp = p;
	printf("7) %d\n", *pp[1]);
	pp = p;
	printf("8) %" PRIdPTR "\n", (ptrdiff_t) (*(p+1) - *pp));
	return EXIT_SUCCESS;
}
