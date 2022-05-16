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

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX_NOM 20

typedef char Nom[TAILLE_MAX_NOM + 1];
typedef enum {SUISSE, ETRANGER} Nationalite;
typedef enum {A, B, C} TypePermis;

const char* const NATIONALITES[] = {"Suisse", "Etranger"};
const char* const TYPES_PERMIS[] = {"A", "B", "C"};

typedef struct {
	uint8_t tauxActivite;
}Suisse;

typedef struct {
	TypePermis typePermis;
}Etranger;

typedef union{
	Suisse suisse;
	Etranger etranger;
} Specificites;

typedef struct {
	Nom nom;
	Nationalite nationalite;
	Specificites specificites;
} Personne;

Personne suisse (const char* nom, uint8_t tauxActivite);
Personne etranger (const char* nom, TypePermis typePermis);
void afficher(const Personne* p); // c'est mieux de passer ces types par adresse

int main(void) {
	Personne p1 = suisse("Toto", 80);
	Personne p2 = etranger("Titi", C);
	afficher(&p1); printf("\n");
	afficher(&p2);  printf("\n");
	return EXIT_SUCCESS;
}


Personne suisse (const char* nom, uint8_t tauxActivite){
	Personne p = {"", SUISSE, {.suisse = {tauxActivite}}}; // "" = {} rempli de \o
	strncpy(p.nom, nom, TAILLE_MAX_NOM);
	return p;
}

Personne etranger (const char* nom, TypePermis typePermis){
	Personne p = {"", ETRANGER, {.etranger = {typePermis}}};
	strncpy(p.nom, nom, TAILLE_MAX_NOM);
	return p;
}


void afficher(const Personne* p) {
	printf("Nom             : %s\n", p->nom);
	printf("Nationalite     : %s\n", NATIONALITES[p->nationalite]);
	if(p->nationalite == SUISSE)
		printf("Taux d'activite : %" PRIu8 "%%\n",
				 p->specificites.suisse.tauxActivite);
	else
		printf("Type de permis  : %s\n",
				 TYPES_PERMIS[p->specificites.etranger.typePermis]);
}
