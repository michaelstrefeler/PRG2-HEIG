/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_13.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 21.03.2022

 Description    : Lire au maximum n caractères d'une chaîne

 Remarque(s)    : Trouver défauts majeurs du code (3) et les corriger

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#define TAILLE_NOM 100

int main(void) {
	char nom[TAILLE_NOM + 1];
	printf("Entrez votre nom (%d caract. max) : ", TAILLE_NOM);
	scanf(" %100[^\n]", nom);
	printf("Votre nom est \"%s\"\n", nom);
	return EXIT_SUCCESS;
}
