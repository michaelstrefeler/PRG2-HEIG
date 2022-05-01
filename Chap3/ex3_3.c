/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_3.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 01.05.2022

 Description    : Affichage de plusieurs personnes

 Remarque(s)    : <a completer>

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
	char nom[20];
	uint8_t taille;
	enum {
		BLEU, VERT, GRIS, MARRON, NOIR
	} couleur_yeux;
} Personne;

static const char* const couleurs[] = {
	[BLEU] = "bleus",
	[VERT] = "verts",
	[GRIS] = "gris",
	[MARRON] = "marron",
	[NOIR] = "noirs"
};


void afficher(Personne* p);

void afficher_liste(Personne p[], size_t taille);

int main(void) {
	Personne Paul = {.nom = "Paul", .taille=180, .couleur_yeux=BLEU};
	Personne Pierre = {.nom = "Pierre", .taille=175, .couleur_yeux=VERT};
	Personne Jean_Jacques = {.nom = "Jean-Jacques", .taille=182, .couleur_yeux=MARRON};
	Personne personnes[] = {Paul, Pierre, Jean_Jacques};
	afficher_liste(personnes, 3);
	return EXIT_SUCCESS;
}

void afficher(Personne* p) {
	printf("%s mesure %d cm et a les yeux %s\n", p->nom, p->taille,
			 couleurs[p->couleur_yeux]);
}

void afficher_liste(Personne p[], size_t taille) {
	for (size_t i = 0; i < taille; i++) {
		printf("Nom : %s\nTaille : %d\nYeux : %s\n\n", p[i].nom, p[i].taille,
				 couleurs[p[i].couleur_yeux]);
	}
}

