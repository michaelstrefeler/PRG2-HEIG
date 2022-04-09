/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_19.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 09.04.2022

 Description    : Manipulation de la mémoire (2)

 Remarque(s)    : Compléter le code fourni pour afficher
 						[0, 0, 0]
 						[1, 1, 1]
 						[2, 2, 2]

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

void afficher(const int *adr, size_t n);

int main(void) {
	int tab[SIZE] = {0};
	afficher(tab, SIZE);
	for (size_t i = 0; i < SIZE; ++i)
		tab[i]++;
	afficher(tab, SIZE);
	memset(tab, 0, sizeof(tab)); // ligne ajoutée
	for (size_t i = 0; i < SIZE; ++i)
		tab[i] += 2;
	afficher(tab, SIZE);
	return EXIT_SUCCESS;
}

// Ajouté pour que le code fonctionne (code omis originalement)
void afficher(const int *adr, size_t n) {
	assert(adr != NULL);
	printf("[");
	for (size_t i = 0; i < n; ++i) {
		if (i > 0)
			printf(", ");
		printf("%d", *(adr + i));
	}
	printf("]\n");
}
