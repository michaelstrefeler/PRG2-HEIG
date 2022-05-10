/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_6.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 09.05.2022

 Description    : Affichage d'une personne (2)

 Remarque(s)    : Utiliser enum pour savoir si Suisse ou étranger

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX_NOM 20

typedef char Nom[TAILLE_MAX_NOM + 1];
const char* const NATIONALITE[] = {"Suisse", "Etranger"};

typedef struct {
	Nom nom;
	enum {
		SUISSE, ETRANGER
	} nationalite;
	union {
		int taux;
		char permis;
	} special;
} Personne;

void afficher(Personne p);

int main(void) {
	Personne toto = {.nom = "Toto", .nationalite=0, {.taux=80}};
	Personne titi = {.nom = "Titi", .nationalite=1, {.permis='C'}};
	afficher(toto);
	afficher(titi);
	return EXIT_SUCCESS;
}

void afficher(Personne p) {
	if (p.nationalite)
		printf("Nom : %s\nNationalite : %s\nType permis : %c\n\n", p.nom,
				 NATIONALITE[p.nationalite], p.special.taux);
	else
		printf("Nom : %s\nNationalite : %s\nTaux activite : %d%c\n\n", p.nom,
				 NATIONALITE[p.nationalite], p.special.permis, '%');
}
