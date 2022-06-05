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
	char s1[] = "ABCD";
	printf("s1 avant inversion = %s\n", s1);
	inverser_1(s1);
	printf("s1 apres inversion = %s\n", s1);
	const char* s2 = "ABCD";
	char* s3 = inverser_2(s2);
	printf("\ns2 avant inversion = %s\n", s2);
	printf("inverse de s2 = %s\n", s3);
	printf("s2 apres inversion = %s\n", s2);
	free(s3);
	inverser_1(NULL); // Ne doit pas "planter" le programme
	inverser_2(NULL); // Idem
	return EXIT_SUCCESS;
}

void inverser_1(char* s) {
	if (s != NULL) {
		char c, * ptr = s + strlen(s) - 1;
		while (s < ptr) {
			c = *s;
			*s++ = *ptr;
			*ptr-- = c;
		}
	}
}

// Renvoie s en cas de problème
char* inverser_2(const char* s) {
	if (s != NULL) {
		const size_t TAILLE = strlen(s);
		char* r = (char*) calloc(TAILLE + 1, sizeof(char));
		if (r != NULL) {
			char* ptr = r + TAILLE - 1;
			for (; *s; s++) *ptr-- = *s;
			return r;
		}
	}
	return (char*) s;
}
