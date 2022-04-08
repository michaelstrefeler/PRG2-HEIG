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
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int* initialiser_1(size_t taille, int valeur);
int* initialiser_2(size_t taille, int valeur);
void afficher(const int* ptr, size_t taille);

int main(void) {
	{
		const size_t TAILLE = 3;
		int* p = initialiser_1(TAILLE, 1);
		afficher(p, TAILLE); // Affiche [1, 1, 1]
		free(p);
	}
	{
		const size_t TAILLE = 5;
		int* p = initialiser_2(TAILLE, 2);
		afficher(p, TAILLE); // Affiche [2, 2, 2, 2, 2]
		free(p);
	}
   return EXIT_SUCCESS;
}

int* initialiser_1(size_t taille, int valeur){
	assert(taille > 0);
	int* p = (int*) calloc(taille, sizeof(int));
	if (p)
		for (int* tmp = p; tmp < p + taille; *tmp++ = valeur);
	return p;
}
int* initialiser_2(size_t taille, int valeur){
	assert(taille > 0);
	int* p = (int*) calloc(taille, sizeof(int));
	if (p) {
		const int* const FIN = p + taille;
		for (; p < FIN; *p++ = valeur);
		p -= taille;
	} return p;
}

void afficher(const int* ptr, size_t taille) {
	assert(ptr != NULL);
	printf("[");
	for (size_t i = 0; i < taille; ++i) {
		if (i > 0)
			printf("%s", ", ");
		printf("%d", ptr[i]); // ou *(ptr + i)
	}
	printf("]\n");
}
