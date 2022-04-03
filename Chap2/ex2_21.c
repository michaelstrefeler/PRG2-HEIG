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

#include <stdio.h>
#include <stdlib.h>

/**
 * initialise une matrice m x n de int avec des 1 sur les 4 "bords" et des 0
 * partout ailleurs
 * @param adr pointeur sur la matrice
 * @param m nombre de lignes de la matrice
 * @param n nombre de colonnes de la matrice
 */
void init(int* adr, const size_t m, const size_t n){
	for(size_t i = 0; i < m; i++){
		for(size_t j = 0; j < n; j++){
			if(i == 0 || i == m-1 || j == 0 || j == n-1)
				*(adr+i*n+j) = 1;
			else
				*(adr+i*n+j) = 0;
		}
	}
}

void afficher(const int* adr, const size_t m, const size_t n){
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
	init(adr, m,n);
	afficher(adr, m,n);
	return EXIT_SUCCESS;
}
