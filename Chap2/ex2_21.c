/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_21.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 03.04.2022

 Description    : Initialisation d'une matrice

 Remarque(s)    : Vérifier le fonctionnement

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * initialise une matrice m x n de int avec des 1 sur les 4 "bords" et des 0
 * partout ailleurs
 * @param adr pointeur sur la matrice
 * @param m nombre de lignes de la matrice
 * @param n nombre de colonnes de la matrice
 */
void init_1(int* adr, size_t m, size_t n){ // peu efficace
	assert(adr != NULL);
	assert(m > 0);
	assert(n > 0);
	for(size_t i = 0; i < m; i++){
		for(size_t j = 0; j < n; j++){
			*(adr + i * n + j) = i == 0 || i == m-1 || j == 0 || j == n-1; //ou *adr++
			/* ma variante qui fonctionne aussi
			 * if(i == 0 || i == m-1 || j == 0 || j == n-1)
				*(adr+i*n+j) = 1;
			else
				*(adr+i*n+j) = 0;*/
		}
	}
}

void init_2(int* adr, size_t m, size_t n){
	assert(adr != NULL);
	assert(m > 0);
	assert(n > 0);
	// Mise à zéro
	memset(adr, 0, m * n * sizeof(int));
	// Bords inf et sup à 1
	for(size_t j = 0; j < n; ++j)
		adr[j] = adr[n * (m - 1) + j] = 1;
	// Bords gauche et droit à 1
	for(size_t i = 1; i < n - 1; ++i)
		adr[i] = adr[n * i + n - 1] = 1;
}

void init_3(int* adr, size_t m, size_t n){
	assert(adr != NULL);
	assert(m > 0);
	assert(n > 0);
	int** ad = (int**) calloc(m, sizeof(int*));
	assert(ad != NULL);
	for(size_t i = 0; i < m; ++i)
		ad[i] = &adr[i * n];
	memset(adr, 0, m* n * sizeof(int));
	for(size_t j = 0; j < n; ++j)
		ad[0][j] = ad[m - 1][j] = 1;
	for(size_t i = 0; i < n; ++i)
		ad[i][0] = ad[i][m-1] = 1;
	free(ad);
}

void afficher(const int* adr, size_t m, size_t n){
	for(size_t i = 0; i < m; i++){
		for(size_t j = 0; j < n; j++){
			printf("%d",*(adr+i*n+j)); // utilisée pour accéder à matrice[i][j]
		}
		printf("\n");
	}
}

int main(void) {
	size_t m = 4;
	size_t n = 16;
	int matrice[m][n];
	int* adr = (int*)matrice;
	init_1(adr, m, n);
	afficher(adr, m,n);
	return EXIT_SUCCESS;
}
