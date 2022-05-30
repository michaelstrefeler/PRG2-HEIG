/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex4_8.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 30.05.2022

 Description    : Prénom et nom

 Remarque(s)    : concat deux strings

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lireChaine(const char* msgInvite, const char* msgErreur);

char* fusion(const char* prenom, const char* nom);

int main(void) {
	const char* const MSG_PRENOM
		= "Donnez-moi votre prenom sans accents/caracteres speciaux : ";
	const char* const MSG_NOM
		= "Donnez-moi votre nom sans accents/caracteres speciaux : ";
	const char* const MSG_ERREUR
		= "Saisie incorrecte. Veuillez SVP recommencer.";
	char* prenom = lireChaine(MSG_PRENOM, MSG_ERREUR);
	char* nom = lireChaine(MSG_NOM, MSG_ERREUR);
	fusion(prenom, nom);
	//fusion("James", "Bond");
	return EXIT_SUCCESS;
}

char* lireChaine(const char* msgInvite, const char* msgErreur) {
#define TAILLE_MAX_CHAINE 40
	char* chaine = calloc(TAILLE_MAX_CHAINE + 1, sizeof(char*));
	do {
		bool ok = false;
		printf(msgInvite);
		scanf("%s", chaine);
		fseek(stdin, 0, SEEK_END); // portable
		for (size_t i = 0; i < strlen(chaine); ++i) {
			if (strlen(chaine) >= TAILLE_MAX_CHAINE) {
				ok = false;
				break;
			} else if (isalpha(chaine[i]) || isblank(chaine[i]) || chaine[i] == '\0' ||
						  chaine[i] == '-') {
				ok = true;
			} else {
				ok = false;
				break;
			}
		}
		if (ok)
			return chaine;
		puts(msgErreur);
	} while (true);
}

char* fusion(const char* prenom, const char* nom) {
	char* out = (char*) calloc(strlen(prenom) + strlen(nom), sizeof(char*));
	sprintf(out, "%s%s%s", prenom, " ", nom);
	printf("La chaine \"%s\" comporte %llu caracteres.\n", out, strlen(out));
	return out;
}
