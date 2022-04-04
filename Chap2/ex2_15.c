/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_15.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 04.04.2022

 Description    : Utilisation de calloc

 Remarque(s)    : Faire 2 fonctions, pour créer un tableau de taille donnée,
 						composé d'entiers (de type int) et pour initialiser à une valeur
 						donnée tous les éléments de ce tableau.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int* faire_tableau(size_t size, int valeur);

int main(void) {
	size_t size = 10;
	int valeur = 12;
   int* ptr = faire_tableau(size, valeur);

	// Teste que le pointeur existe et que la valeur a changé dans toutes les cases
	if(ptr){
		printf("[");
		for(size_t i = 0; i < size; i++)
			printf("%d, ", ptr[i]);
		printf("\b\b]");
	}
   return EXIT_SUCCESS;
}

int* faire_tableau(size_t size, int valeur){
	int* ptr_tab = calloc(size, sizeof(int));
	if(!ptr_tab)
		return NULL;
	for(size_t i = 0; i < size; i++)
		ptr_tab[i] = valeur;
	return ptr_tab;
}
