/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_23
 Auteur(s)      : Michael Strefeler
 Date creation  : 04.04.2022

 Description    : Diagonale d'une matrice carrée

 Remarque(s)    : Faire une fonction qui renvoie la diagonale d'une matrice carrée
 						sous forme de tableau

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define N 3

int* diagonale(const int* adr, const size_t n);
void afficher(const int* adr, const size_t n);

int main(void) {
	int matrice[N][N] = {{1, 2, 3},
								{4, 5, 6},
								{7, 8, 9}};
	const int* const adr = (int*)matrice;
	int* diag = diagonale(adr, N);
	if(diag) {
		printf("[");
		for(size_t i = 0; i < N; i++)
			printf("%d, ", diag[i]);
		printf("\b\b]\n");
	}
   return EXIT_SUCCESS;
}

int* diagonale(const int* adr, const size_t n){
	int* diag = calloc(n, sizeof(int));
	if(!diag)
		return NULL;
	size_t pos = 1;
	diag[0] = adr[0];
	for(size_t i = 0; i < n; i++){
		for(size_t j = 0; j < n; j++){
			if(i==j && i==pos){
				diag[pos] = *(adr+i*n+j);
				pos++;
			}
		}
	}
	return diag;
}

