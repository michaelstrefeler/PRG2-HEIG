/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_9.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 19.05.2022

 Description    : Affichage des jours de la semaine (2)

 Remarque(s)    : Contôler la saisie

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toLower(char* s);

int lireChaine(const char* const tab[], size_t n,
					const char* msgInvite, const char* msgErreur);

void afficher(const char* const tab[], size_t n, size_t pos);

int main(void) {
	typedef enum {
		LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE
	} Jour;
	const char* const JOURS[] = {"lundi", "mardi", "mercredi", "jeudi",
										  "vendredi", "samedi", "dimanche"};

	const size_t NB_JOURS = sizeof(JOURS) / sizeof(char*);

	const char* const MSG_INVITE
		= "Donnez un jour de la semaine en toutes lettres et en minuscules : ";
	const char* const MSG_ERREUR
		= "Saisie incorrecte. Veuillez SVP recommencer.";

	// Saisie, par l'utilisateur, d'un jour de la semaine
	Jour jour = lireChaine(JOURS, NB_JOURS, MSG_INVITE, MSG_ERREUR);

	// Affichage (cyclique) des jours de la semaine à partir du jour saisi
	afficher(JOURS, NB_JOURS, jour);

	printf("\n");
	return EXIT_SUCCESS;
}

void toLower(char* s) {
	if (s != NULL) {
		const size_t TAILLE = strlen(s);
		for (size_t i = 0; i < TAILLE; ++i)
			s[i] = (char) tolower(s[i]);
	}
}

int lireChaine(const char* const tab[], size_t n,
					const char* msgInvite, const char* msgErreur) {
#define TAILLE_MAX_CHAINE 8
	char chaineControle[4];
	sprintf(chaineControle, "%%%ds", TAILLE_MAX_CHAINE);
	char chaine[TAILLE_MAX_CHAINE + 1];
	do {
		printf(msgInvite);
		scanf(chaineControle, chaine);
		fflush(stdin); // ou fseek(stdin, 0, SEEK_END); // portable
		toLower(chaine);
		// Vérifier si chaine correspond à l'un des noms de jour
		for (size_t i = 0; i < n; ++i)
			if (strcmp(chaine, tab[i]) == 0)
				return i;
		puts(msgErreur);
	} while (true);
}

void afficher(const char* const tab[], size_t n, size_t pos) {
	for (size_t i = 0; i < n; ++i)
		puts(tab[(pos + i) % n]); // ou printf("%s\n", tab[(pos+i) % n];
}
