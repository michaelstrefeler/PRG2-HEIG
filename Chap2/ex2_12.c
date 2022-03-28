/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_12.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 28.03.2022

 Description    : Inversion d'un tableau 1D (1)

 Remarque(s)    : Il faut inverser avec des pointeurs

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5
void inverser(int* debut, int* fin);

int main(void) {
   int tab[TAILLE] = {3, 0, 2, 7, 4};
	int* debut = &tab[0];
	int* fin = debut + TAILLE - 1;

	printf("Avant: ");
	for(int* ptr = &tab[0]; ptr<= &tab[TAILLE -1]; ++ptr)
		printf("%d ", *ptr);
	printf("\n");

	inverser(debut, fin);

	printf("Apres: ");
	for(int* ptr = &tab[0]; ptr<= &tab[TAILLE -1]; ++ptr)
		printf("%d ", *ptr);
   return EXIT_SUCCESS;
}

void inverser(int* debut, int* fin){
	while(debut<fin)
	{
		int temp = *debut;
		*debut = *fin;
		*fin = temp;
		debut++;
		fin--;
	}
}
