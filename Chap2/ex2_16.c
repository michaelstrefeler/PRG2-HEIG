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

#include <stdio.h>
#include <stdlib.h>
#define TAILLE 8


int* inverse(const int* debut, const int* fin);

int main(void) {
	int tableau[TAILLE] = {0,1,2,3,4,5,6,7};
	const int* debut = &tableau[0];
	const int* fin = debut + TAILLE - 1;

	printf("Avant: [");
	for(size_t i = 0; debut+i != fin+1; i++)
		printf("%d, ", debut[i]);
	printf("\b\b]\n");

	int* ptr_inverse = inverse(debut, fin);
	if(ptr_inverse){
		printf("Apres: [");
		for(size_t i = 0; i < TAILLE; i++)
			printf("%d, ", ptr_inverse[i]);
		printf("\b\b]\n");
	}
	return EXIT_SUCCESS;
}

int* inverse(const int* debut, const int* fin){
	int* ptr = calloc((unsigned long long int) (fin - debut+1),
							  sizeof(int));
	if(!ptr)
		return NULL;
	for(size_t i = 0; (fin-i) != debut-1; i++){
		ptr[i] = *(fin-i);
	}
	return ptr;
}
