/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex4_2.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 28.05.2022

 Description    : Implémentation de strcpy

 Remarque(s)    : strcpy fait maison

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

char* strcpy(char* to, const char* from);

int main(void) {
	{
		const char from[] = "Testing";
		char to[] = "Hello world";
		strcpy(to, from);
		printf("|%s|\n", to);
	}

	{
		const char from[] = "";
		char to[] = "Hello world";
		strcpy(to, from);
		printf("|%s|\n", to);
	}

	{
		const char from[20] = "Chaine trop longue non";
		char to[20] = "Dog";
		strcpy(to, from);
		printf("|%s|\n", to);
	}

	{
		// Code trouvé sur https://www.cplusplus.com/reference/cstring/strcpy/
		char str1[] = "Sample string";
		char str2[40];
		char str3[40];
		strcpy(str2, str1);
		strcpy(str3, "copy successful");
		printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	}
	return EXIT_SUCCESS;
}

char* strcpy(char* to, const char* from) {
	size_t i = 0;
	while (from[i] != '\0') {
		++i;
	}
	for (size_t j = 0; j < i; j++) {
		to[j] = from[j];
	}
	to[i] = '\0';
	return to;
}
