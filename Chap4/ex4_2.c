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

#define PRINT(STR) printf(#STR " = %s\n", STR)

char* strcpy(char* to, const char* from);

int main(void) {
	char s1[10];
	char* s2;
	const char* s3;

	s2 = strcpy(s1, "");
	PRINT(s1);
	PRINT(s2);

	strcpy(s1, "ABC");
	PRINT(s1);
	PRINT(s2);

	s3 = "DEF"; // littéral
	strcpy(s1, s3);
	PRINT(s1);

	strcpy(s1, strcpy(s1, "ABC"));
	PRINT(s1);

//	 char* msg = "ABC";
//	 strcpy(msg, ""); // provoquerait un crash à l'exécution, car msg pointe
//							// sur chaîne constante ("ABC"), donc non modifiable
	return EXIT_SUCCESS;
}

char* strcpy(char* to, const char* from) {
	char* tmp = to;
	while ((*to++ = *from++) != '\0');
	return tmp;
}
