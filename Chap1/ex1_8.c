/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_8.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 08.03.2022

 Description    : Représentation binaire d'un entier

 Remarque(s)    : Convertit en binaire le nombre entier et place dans un tableau

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int32_t n, int8_t binary[]){
	for(unsigned i = 0u; i < 32u; i++){
		unsigned bit = i;
		unsigned shift = n >> bit;
		unsigned checkBit = (n >> bit) & 1u;
		binary[i] = checkBit;
	}

	// Boucle pour inverser les éléments du tableau
	for(int i = 0; i < 16; i++){
		int8_t temp = binary[i];
		binary[i] = binary[31-i];
		binary[31-i] = temp;
	}
}

int main(void) {
   int8_t binary[32];
	decimalToBinary(217, binary);

	// Boucle pour afficher les éléments du tableau
	for(int8_t *b = binary; b < (&binary)[1]; b++){
		printf("%d ", *b);
	}
   return EXIT_SUCCESS;
}
