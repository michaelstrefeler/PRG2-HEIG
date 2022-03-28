/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_5.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 08.03.2022

 Description    : Récupérer la valeur du nième bit

 Remarque(s)    : Pas le droit d'utiliser des if, utiliser opérateurs bitwise

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE sizeof(int) * 8 // RRH
typedef unsigned short ushort;   // RRH

ushort getBit(ushort pos, int n);

int main(void) {
	for(ushort pos = 0; pos < INT_SIZE; ++pos)
		printf("bit %hu = %hu\n", pos, getBit(pos, 10));
		//%hu = short unsigned
   return EXIT_SUCCESS;
}

ushort getBit(ushort pos, int n){
	assert(pos < INT_SIZE);
	return n >> pos & 1; // NB Ici, >> pas dangereux
}
