/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_3.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 01.05.2022

 Description    : Affichage de plusieurs personnes

 Remarque(s)    : Faire 2 fonctions pour afficherPersonnne

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef const char* Nom;
typedef uint8_t Taille;
typedef enum {BLEU, VERT, GRIS, MARRON, NOIR} CouleurYeux;

typedef struct {
	Nom nom;
	Taille taille; // en cm
	CouleurYeux couleurYeux;
} Personne;

const char* const COULEUR_YEUX[] = {"bleus", "verts", "gris", "marron", "noirs"};


void afficherPersonnne(const Personne* p);
void afficherPersonnnes(const Personne tab[], size_t n);

int main(void) {
	Personne PERSONNES[] = {
		{.nom = "Paul", .taille=180, .couleurYeux=BLEU},
		{.nom = "Pierre", .taille=175, .couleurYeux=VERT},
		{.nom = "Jean-Jacques", .taille=182, .couleurYeux=MARRON}
	};
	const size_t TAILLE = sizeof(PERSONNES) / sizeof(Personne);
	afficherPersonnnes(PERSONNES, TAILLE);
	return EXIT_SUCCESS;
}

void afficherPersonnne(const Personne* p) {
	printf("Nom : %s\nTaille : %" PRIu8 "\nYeux : %s\n\n", p->nom, p->taille,
			 COULEUR_YEUX[p->couleurYeux]);
}

void afficherPersonnnes(const Personne tab[], size_t n) {
	for (size_t i = 0; i < n; i++) {
		afficherPersonnne(&tab[i]); // tab + i fonctionne aussi
	}
}

