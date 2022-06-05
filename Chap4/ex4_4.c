/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex4_4.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 29.05.2022
 Description    : Implémentation de strcat

 Remarque(s)    : strcat fait maison

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define PRINT(STR) printf(#STR " = %s\n", STR)

char* strcat(char* to, const char* from);

int main(void) {
	char to[10] = ""; // obligé d'avoir un '\0' sinon ça ne marche pas
	const char* from = "ABC";
	char* s;

	strcat(to, from);
	PRINT(to);

	s = strcat(to, "DEF");
	PRINT(to);
	PRINT(s);

	return EXIT_SUCCESS;
}

char* strcat(char* to, const char* from) {
	char* tmp = to;
	while (*to) to++; // se positionner sur '\0'
	while ((*to++ = *from++) != '\0'); // idem strcpy
	return tmp;
}
