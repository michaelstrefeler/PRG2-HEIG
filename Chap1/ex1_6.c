/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_6.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 08.03.2022

 Description    : Fixer la valeur du nième bit

 Remarque(s)    : Pas le droit d'utiliser des if, utiliser opérateurs bitwise

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE sizeof(int) * 8 // RRH
typedef unsigned short ushort;   // RRH

int* setBit(ushort pos, ushort bitValue, int* n);

int main(void) {
	int n = 0;
	printf("n = %d\n", n);
	printf("n = %d\n", *setBit(0, 1, &n));
	printf("n = %d\n", *setBit(0, 0, &n));
	printf("n = %d\n", *setBit(1, 1, &n));

	for(ushort pos = 0; pos < INT_SIZE; ++pos)
		setBit(pos, 1, &n);
	printf("n = %d\n", n);

	int m = -1;
	printf("m = %d\n", *setBit(31, 0, &m));
   return EXIT_SUCCESS;
}

int* setBit(ushort pos, ushort bitValue, int* n){
	assert(pos < INT_SIZE);
	assert(bitValue == 0 || bitValue == 1);
	const int MASK_1 = 1 << pos,
				 MASK_2 = bitValue << pos;
	*n = (*n & MASK_1) | MASK_2;
	// Variante 2
	//const int MASK = 1 << pos;
	//*n ^= (-bitValue ^ *n) & MASK;
	return n;
}
