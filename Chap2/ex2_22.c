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

#include <stdio.h>
#include <stdlib.h>


double somme_matrice(const double* const adr, const size_t m, const size_t n){
	double somme = 0.0;
	for(size_t i = 0; i < m; i++){
		for(size_t j = 0; j < n; j++){
			somme += *(adr+i*n+j); // utilisée pour accéder à matrice[i][j]
		}
	}
	return somme;
}

int main(void) {
	double matrice[3][4] = {{1.0, 1.25, 3.0,  4.0},
									{5.0, 6.0,  7.5,  8.0},
									{9.5, 10.0, 11.0, 12}};
	const double* const adr = (double*)matrice;
	printf("%g", somme_matrice(adr, 3,4));
   return EXIT_SUCCESS;
}


