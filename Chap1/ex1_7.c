/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_7.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 08.03.2022

 Description    : Position du bit à 1 de plus faible poids

 Remarque(s)    : Retourne la position du bit à 1 de plus faible poids. -1 si aucun

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

short lowestOrderSetBit(int n){
	int pos = -1;
	for(unsigned i = 0u; i < 16u; i++){
		unsigned bit = i;
		unsigned shift = n >> bit;
		unsigned checkBit = (n >> bit) & 1u;
		if(checkBit){
			pos = i;
			break;
		}
	}
	return pos;
}

int main(void) {
   printf("Test avec 0: %d\n", lowestOrderSetBit(0)); // 0000
	printf("Test avec 8: %d\n", lowestOrderSetBit(8)); // 1000
	printf("Test avec 6: %d\n", lowestOrderSetBit(6)); // 0110
	printf("Test avec 5: %d\n", lowestOrderSetBit(5)); // 0101
   return EXIT_SUCCESS;
}
