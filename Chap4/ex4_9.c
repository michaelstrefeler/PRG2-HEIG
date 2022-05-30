/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex4_9.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 30.05.2022

 Description    : Inversion d'une chaîne

 Remarque(s)    : Hormis strlen,
						aucune autre fonction de string.h ne doit être utilisée ici.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverser_1(char* s);

char* inverser_2(const char* s);

int main(void) {
	char* mot = "test123";
	char* mot2 = "123456";
	inverser_1(mot);
	printf("Inverse de %s : %s\n", mot2, inverser_2(mot2));
	return EXIT_SUCCESS;
}

void inverser_1(char* s) {
	char* inverse = (char*) calloc(strlen(s), sizeof(char*));
	int j = 0;
	for (int i = (int) strlen(s) - 1; i > -1; --i) {
		inverse[j] = s[i];
		j++;
	}
	inverse[strlen(s)] = '\0';
	printf("Inverse de %s : %s\n", s, inverse);
}

// Renvoie s en cas de problème
char* inverser_2(const char* s) {
	char* inverse = (char*) calloc(strlen(s), sizeof(char*));
	if (inverse) {
		int j = 0;
		for (int i = (int) strlen(s) - 1; i > -1; --i) {
			inverse[j] = s[i];
			j++;
		}
		inverse[strlen(s)] = '\0';
		return inverse;
	}
	return (char*) s;
}
