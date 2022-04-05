/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_15.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 04.04.2022

 Description    : Utilisation de calloc

 Remarque(s)    : Faire une fonction, pour créer un tableau de taille donnée,
 						composé d'entiers (de type int) et pour initialiser à une valeur
 						donnée tous les éléments de ce tableau.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int* initialiser(size_t taille, int valeur);

int main(void) {
	const size_t TAILLE = 10;
   int* ptr = initialiser(TAILLE, 12);

	// Teste que le pointeur existe. Si c'est le cas tout afficher
	if(ptr){
		printf("[");
		for(size_t i = 0; i < TAILLE; i++)
			printf("%d%s", ptr[i], ", ");
		printf("%s", "\b\b]"); // ça peut potentiellement causer des problèmes sans %s
	}
	free(ptr); // Ne pas oublier de libérer
   return EXIT_SUCCESS;
}

int* initialiser(size_t taille, int valeur){
	assert(taille > 0); // Car calloc(0, ...) comportement indéfini
	int* ptr_tab = (int*)calloc(taille, sizeof(int));
	// c'est bien de cast (int*)calloc
	if(ptr_tab){
		for(int* tmp = ptr_tab; tmp < ptr_tab + taille; *tmp++ = valeur);
		// utiliser ptr temporaire pour ne pas avoir des fuites de mémoire
		// *tmp++ affecte d'abord et incrémente après
	}
	return ptr_tab;
}
