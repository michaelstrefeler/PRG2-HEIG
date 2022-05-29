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

char* strncpy(char* to, const char* from, size_t size);

int main(void) {
	{
		// Code trouvé sur https://www.cplusplus.com/reference/cstring/strncpy/
		char str1[] = "To be or not to be";
		char str2[40];
		char str3[40];

		/* copy to sized buffer (overflow safe): */
		strncpy(str2, str1, sizeof(str2));

		/* partial copy (only 5 chars): */
		strncpy(str3, str2, 5);
		str3[5] = '\0';   /* null character manually added */

		puts(str1);
		puts(str2);
		puts(str3);
	}
	return EXIT_SUCCESS;
}

char* strncpy(char* to, const char* from, size_t size) {
	for (size_t i = 0; i < size; i++) {
		to[i] = from[i];
	}
	return to;
}
