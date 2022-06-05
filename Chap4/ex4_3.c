/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex4_3.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 25.05.2022

 Description    : Implémentation de strncpy

 Remarque(s)    : strncpy fait maison

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define PRINT(STR) printf(#STR " = %s\n", STR)

char* strncpy(char* to, const char* from, size_t size);

int main(void) {
	{
		const char* from = "AB";
		char to[] = "XXXXXX";
		for (size_t i = 0; i <= 3; ++i) {
			strncpy(to, from, i);
			PRINT(to);
		}
	}

	{
		const char* from = "AB";
		char to[] = "XXXXXX";
		const size_t TAILLE = 6;
		strncpy(to, from, 4);
		for (size_t i = 0; i <= TAILLE; ++i)
			printf("%d ", (int) to[i]);
		printf("\n");
	}
	return EXIT_SUCCESS;
}

char* strncpy(char* to, const char* from, size_t size) {
	size_t i;
	for (i = 0; i < size && from[i] != '\0'; ++i)
		to[i] = from[i];
	for (; i < size; ++i)
		to[i] = '\0';
	return to;
}
