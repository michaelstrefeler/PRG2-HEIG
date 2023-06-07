/*
 -----------------------------------------------------------------------------------
 Nom du fichier : question5_TE2_20-21.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 25.06.2022

 Description    : Faire ce qu'il faut pour qu'on puisse créér des vaisseaux spatiaux
 		          Qui suivent un cahier des charges

 Remarque(s)    : Fonction afficher pas demandée mais faite pour tester le bon
 		          fonctionnement

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMBRES 5

typedef struct {
	unsigned poids;
	bool lasers;
} Combat;

typedef struct {
	double rayon_action;
} Exploration;

typedef enum {
	COMBAT, EXPLORATION
} Type;
typedef union {
	Combat combat;
	Exploration exploration;
} Specificites;

typedef struct {
	const char* nom;
} Membre;

typedef struct {
	size_t nbMembre;
	Membre equipe[MAX_MEMBRES];
} Equipage;

typedef struct {
	const char* nom;
	Equipage equipage;
	Type type;
	Specificites specificites;
} Vaisseau;

// Pas demandé dans l'exercice du test
void afficher(Vaisseau* v) {
	printf("Vaisseau : %s\n", v->nom);
	printf("Membres de l'equipage : ");
	for (size_t i = 0; i < v->equipage.nbMembre; ++i) {
		if (v->equipage.equipe[i].nom && i == 0)
			printf("%s", v->equipage.equipe[i].nom);
		else {
			printf(", %s", v->equipage.equipe[i].nom);
		}
	}
	if (v->equipage.nbMembre == 0)
		printf("Aucun");
	if (v->type == COMBAT) {
		printf("\nPoids : %u [kg]\nLasers : %s\n\n", v->specificites.combat.poids,
				 v->specificites.combat.lasers ? "Oui" : "Non");
	} else {
		printf("\nRayon d'action : %g [milliards de km]\n\n",
				 v->specificites.exploration.rayon_action);
	}
}

int main(void) {
	Vaisseau starfighter = {"Starfighter", {2, {{"Joe"}, {"Jack"}}},COMBAT, {{2500, 1}}};
	Vaisseau x_wing = {"X-Wing", {0, {}},EXPLORATION, {.exploration={63.2}}};
	afficher(&starfighter);
	afficher(&x_wing);

	return EXIT_SUCCESS;
}
