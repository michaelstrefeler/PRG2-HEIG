/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_22.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 03.04.2022

 Description    : Somme des valeurs d'une matrice m x n

 Remarque(s)    : Utiliser une matrice de double

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

double somme1(const double* adr, size_t m, size_t n);
double somme2(const double* adr, size_t m, size_t n);
double somme3(const double* adr, size_t m, size_t n);
double somme4(const double* adr, size_t taille);

int main(void){
	// Obligé de faire des define pour que la taille de la matrice soit connue à la
	// compliation.
	#define NB_LIGNES 3
	#define NB_COLONNES 4
	const double  M[NB_LIGNES][NB_COLONNES] = {{1, 2.5, 3, 4},
															 {5, 6, 7.5, 8},
															 {9.5, 10, 11, 12}};
	// Manière la plus populaire
	printf("somme 1a = %g\n", somme1((double*) M, NB_LIGNES, NB_COLONNES));
	printf("somme 1b = %g\n", somme1(M[0], NB_LIGNES, NB_COLONNES));
	printf("somme 1c = %g\n", somme1(&M[0][0], NB_LIGNES, NB_COLONNES));
	printf("somme 2  = %g\n", somme2((double*) M, NB_LIGNES, NB_COLONNES));
	printf("somme 3  = %g\n", somme3((double*) M, NB_LIGNES, NB_COLONNES));
	printf("somme 4  = %g\n", somme4((double*) M, NB_LIGNES * NB_COLONNES));
	return EXIT_SUCCESS;
}

// J'ai fait ça dans ma solution
double somme1(const double* adr, size_t m, size_t n){
	assert(adr != NULL);
	double somme = 0.0;
	for(size_t i = 0; i < m; ++i)
		for(size_t j = 0; j < n; ++j)
			somme += *(adr + i * n + j); // ou adr[i * n + j];
	return somme;
}

double somme2(const double* adr, size_t m, size_t n) {
	assert(adr != NULL);
	double** ad = (double**) calloc(m, sizeof(double*));
	assert(ad != NULL); // assert car sinon que renvoyer en retour ?
	for(size_t i = 0; i < m; ++i)
		ad[i] = (double*) (adr + i * n);
	double somme = 0.0;
	for(size_t i = 0; i < m; ++i)
		for(size_t j = 0; j < n; ++j)
			somme += ad[i][j];
	free(ad);
	return somme;
}

double somme3(const double* adr, size_t m, size_t n) {
	assert(adr != NULL);
	double somme = 0.0;
	for(size_t i = 0; i < m * n; ++i)
		somme += adr[i]; // ou *(adr + i) ou *adr++
	return somme;
}

// même chose que somme3 mais taille = m * n
double somme4(const double* adr, size_t taille){
	assert(adr != NULL);
	double somme = 0.0;
	for(size_t i = 0; i < taille; ++i)
		somme += adr[i];
	return somme;
}
