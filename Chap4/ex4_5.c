/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex4_5.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 29.05.2022

 Description    : Implémentation de strncat

 Remarque(s)    : strncat fait maison

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define PRINT(STR) printf(#STR " = %s\n", STR)

char* strncat(char* to, const char* from, size_t size);

int main(void) {
	char to[10] = ""; // besoin d'avoir un '\0'
	const char* from = "ABC";

	for (size_t i = 1; i <= 4; ++i) {
		strncat(to, from, i);
		PRINT(to);
	}
	return EXIT_SUCCESS;
}

char* strncat(char* to, const char* from, size_t size) {
	char* tmp = to;
	if (size) {
		while (*to) to++;
		while ((*to++ = *from++) != '\0') {
			if (--size == 0) {
				*to = '\0';
				break;
			}
		}
	}
	return tmp;
}
