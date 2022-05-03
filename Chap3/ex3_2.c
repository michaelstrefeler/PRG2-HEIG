/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_2.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 01.05.2022

 Description    : Affichage d'une personne (1)

 Remarque(s)    : Faire 2 fonctions d'affichage 1 par valeur et 1 par adresse

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define TAILLE_MAX_NOM 20
typedef char Nom[TAILLE_MAX_NOM + 1];
typedef uint8_t Taille;
typedef enum {BLEU, VERT, GRIS, MARRON, NOIR} CouleurYeux;

typedef struct {
	Nom nom;
	Taille taille;
	CouleurYeux couleur_yeux;
} Personne;

const char* const COULEUR_YEUX[] = {"bleus", "verts", "gris", "marron", "noirs"};

void afficher_1(Personne p);

void afficher_2(Personne* p);

int main(void) {
	Personne p = {.nom = "Toto", .taille=180, .couleur_yeux=BLEU};
	afficher_1(p);
	afficher_2(&p);
	return EXIT_SUCCESS;
}

void afficher_1(Personne p) {
	printf("%s mesure %" PRIu8 " cm et a les yeux %s\n", p.nom, p.taille,
			 COULEUR_YEUX[p.couleur_yeux]);
}

void afficher_2(Personne* p) {
	printf("%s mesure %" PRIu8 " cm et a les yeux %s\n", p->nom, p->taille,
			 COULEUR_YEUX[p->couleur_yeux]);
}
