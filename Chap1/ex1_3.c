/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_3.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 28.02.2022

 Description    : Exercice 1.3

 Remarque(s)    : Macros (2)

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define GENERIC_ABS(type) \
type type##_abs(type x) { \
   return x > 0 ? x: -x;  \
}

GENERIC_ABS(int)

int main(void) {
	/* Programme original affiche:
	 * 1. 2
	 * 2. 2
	 * 3. 65
	 * 4. 3
	 * 5. 1 0
	 * 6. 0 0
	 * 7. 1 -1
	 */

	int n;
	printf("1. %d\n", int_abs(2));
	printf("2. %d\n", int_abs(-2));
	printf("3.  %d\n", int_abs('A'));

	n = -2;
	printf("4.  %d\n", int_abs(n+1));

	n = -2;
	printf("5.  %d\n", int_abs(n++)); printf(" %d\n", n);

	n = -2;
	printf("6.  %d\n", int_abs(++n)); printf(" %d\n", n);

	n = -2;
	printf("7.  %d\n", abs(++n)); printf(" %d\n", n);
}
