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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int* diagonale_1(const int* adr, size_t n);
int* diagonale_2(const int* adr, size_t n);

void afficher(const int* adr, size_t taille);

void test(int* (*f)(const int*, size_t), const int* adr, size_t n);

int main(void){
	#define TAILLE 3
	const int M[TAILLE][TAILLE] = {{1, 2, 3},
											 {4, 5, 6},
											 {7, 8, 9}};

	test(diagonale_1, (int*) M, TAILLE);
	test(diagonale_2, (int*) M, TAILLE);
}

int* diagonale_1(const int* adr, size_t n){
	assert(adr != NULL);
	int* vecteur = (int*) calloc(n, sizeof(int));
	if(vecteur){
		for (size_t i = 0; i < n; ++i)
			vecteur[i] = adr[i * (n + 1)]; // on ne garde que les termes i = j
	}
	return vecteur;
}

int* diagonale_2(const int* adr, size_t n){
	assert(adr != NULL);
	int* vecteur = (int*) calloc(n, sizeof(int));
	if(vecteur){
		const int* const FIN = adr + n * n;
		for(size_t i = 0; adr < FIN; adr += n + 1, ++i)
			vecteur[i] = *adr;
	}
	return vecteur;
}

void afficher(const int* adr, size_t taille){
	printf("[");
	if(adr){
		for(size_t i = 0; i < taille; i++){
			if(i > 0)
				printf("%s", ", ");
			printf("%d", adr[i]); // ou *(adr + i)
		}
	}
	printf("]\n");
}

void test(int* (*f)(const int*, size_t), const int* adr, size_t n){
	assert(f != NULL);
	int* vecteur = f(adr, n);
	printf("Diagonale = ");
	afficher(vecteur, n);
	free(vecteur);
}
