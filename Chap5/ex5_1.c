/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex5_1.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 12.06.2022

 Description    : Lecture intégrale d'un fichier texte

 Remarque(s)    : on fournit un fichier contenant 1 à 5 (un chiffre par ligne)

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define NOM_FICHIER "..\\Chap5\\fichier.txt" \
// Obligé de mettre ça car clion cherche
// le fichier à l'endroit où on lance le .exe pas le .c

int main(void) {
	FILE* f;
	f = fopen(NOM_FICHIER, "r");
	if (f) {
		int n;
		while (fscanf(f, "%d", &n) != EOF)
			printf("%d\n", n);
		fclose(f);
		return EXIT_SUCCESS;
	} else {
		printf("Ouverture du fichier \"%s\" impossible.\n", NOM_FICHIER);
		return EXIT_FAILURE;
	}
}
