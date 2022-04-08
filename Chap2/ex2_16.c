/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_16.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 04.04.2022

 Description    : Inversion d'un tableau 1D (2)

 Remarque(s)    : Renvoie le tableau inverse du tableau 1D défini par début et fin où
 						début, resp. fin, désigne l'adresse du premier, resp. du dernier,
 						élément du tableau à inverser.

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int* inverse(const int* debut, const int* fin);
void afficher(const int tab[], size_t taille);
void test(const int tab[], size_t taille);

int main(void) {
	{
		const int TAB[] = {1};
		test(TAB, sizeof(TAB) / sizeof(int));
	}

	{
		const int TAB[] = {1, 2};
		test(TAB, sizeof(TAB) / sizeof(int));
	}

	{
		const int TAB[] = {1, 2, 3};
		test(TAB, sizeof(TAB) / sizeof(int));
	}

	{
		const int TAB[] = {1, 2, 3};
		test(TAB, 0);
	}
	return EXIT_SUCCESS;
}

int* inverse(const int* debut, const int* fin){
	assert(debut != NULL);
	assert(fin != NULL);
	assert(fin - debut + 1 > 0); // pour garantir que (cf ci-dessous) TAILLE > 0
	const size_t TAILLE = (size_t) (fin - debut + 1);
	int* ptr = (int*) calloc(TAILLE, sizeof(int));
	if (ptr)
		for (size_t i = 0; i < TAILLE; ++i)
			ptr[TAILLE - 1 - i] = debut[i]; // ou ptr[i] = *fin--;
	return ptr;
}

void afficher(const int tab[], size_t taille){
	assert(tab != NULL);
	printf("[");
	for (size_t i = 0; i < taille; ++i){
		if (i > 0)
			printf("%s", ", ");
		printf("%d", tab[i]);
	}
	printf("]\n");
}


void test(const int tab[], size_t taille){
	printf("Avant inversion: \n");
	afficher(tab, taille);
	int* ptr = inverse(tab, tab + taille - 1);
	printf("Apres inversion: \n");
	afficher(ptr, taille);
	free(ptr);
}
