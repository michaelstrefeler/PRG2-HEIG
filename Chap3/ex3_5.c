/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_5.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 09.05.2022

 Description    : Taille d'un structure

 Remarque(s)    : en 32 et en 64 bits

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
	struct S1 {
		int* ptr;
		int32_t a;
		int64_t b;
	};
	/* Taille en bytes de S1
	 * 32 bits:
	 * int* taille de 4 bytes
	 * int32_t 4 bytes
	 * int64_t 8 bytes
	 *	--> 16 bytes
	 * 64 bits:
	 * int* 8 bytes
	 * int32_t 4 bytes
	 * int64_t 8 bytes
	 * --> 24 bytes
	 */

	//printf("sizeof(S1) = %lld", sizeof(struct S1)); // affiche 24 car 64 bits

	struct S2 {
		int8_t a;
		int16_t b;
		char c;
		double* ptr;
	};
	/* Taille en bytes de S2
	 * 32 bits:
	 * int8_t 1 bytes
	 * int16_t 2 bytes
	 * char 1 bytes
	 * double* 4 bytes
	 *	--> 8 bytes
	 *	64 bits:
	 * int8_t 1 bytes
	 * int16_t 2 bytes
	 * char 1 bytes
	 * double* 8 bytes
	 * --> 16 bytes
	 */

	//printf("sizeof(S1) = %lld", sizeof(struct S2)); // affiche 16 car 64 bits
	return EXIT_SUCCESS;
}
