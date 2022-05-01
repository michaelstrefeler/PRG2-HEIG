/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_4.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 01.05.2022

 Description    : Lendemain d’une date

 Remarque(s)    : Programme qui détermine et affiche le lendemain d’une date donnée.
 						Date sous la forme d’une structure à 3 membres : jour (de type
 						uint_8), mois (de type uint_8) et année (de type uint16_t)
						Structurer le code en fonctions
						Tenir compte des années bissextiles dans le calcul du lendemain
						Afficher les dates au format jj.mm.aaaa

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct Date {
	uint8_t jour;
	uint8_t mois;
	uint16_t annee;
};

int main(void) {
	// code
	return EXIT_SUCCESS;
}
