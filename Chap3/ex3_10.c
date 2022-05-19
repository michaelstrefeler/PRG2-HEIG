/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_10.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 19.05.2022

 Description    : Pile dynamique

 Remarque(s)    : Code à compléter

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Info;

typedef struct Elem {
	Info info;
	struct Elem* suivant;
} Element;

typedef Element* Pile;

bool empiler(Pile* pile, Info info) {
	Element* tmp = (Element*) malloc(sizeof(Element));
	if (tmp) {
		*tmp = (Element) {info, *pile};
		*pile = tmp;
		return true;
	}
	return false;
}

bool desempiler(Pile* pile, Info* info) {
	if (*pile != NULL) { // Si la pile n'est pas vide
		Element* tmp = *pile;
		*info = tmp->info;
		*pile = tmp->suivant;
		free(tmp);
		return true;
	}
	return false;
}

bool estVide(Pile pile) {
	return pile == NULL;
}

int main(void) {
	Pile pile = NULL;
	Info info;

	// Saisie utilisateur
	do {
		printf("Donnez un entier (0 pour terminer) : ");
		scanf("%d", &info);
		if (info != 0)
			empiler(&pile, info);
	} while (info != 0);

	// Affichage dans l'ordre inverse des valeurs saisies par l'utilisateur
	printf("\n");
	while (!estVide(pile)) {
		desempiler(&pile, &info);
		printf("%d\n", info);
	}
	return EXIT_SUCCESS;
}
