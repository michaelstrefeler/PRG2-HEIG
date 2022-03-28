/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_11.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 15.03.2022

 Description    : printf(3)

 Remarque(s)    : Code à compléter

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
   size_t i = 1;
	uint32_t j = UINT32_MAX;

	printf("i = %" PRIu64, i); // i = 1
	printf("\nj = %" PRIuMAX, j); // j = 4294967295
   return EXIT_SUCCESS;
}
