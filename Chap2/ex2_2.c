/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_2.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 22.03.2022

 Description    : Paramètres d'entrée-sortie

 Remarque(s)    : Faire fonction C void qui change des valeurs

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

void carree_cube(double x, double* ptr_carre, double* ptr_cube){
	*ptr_carre = x * x;
	*ptr_cube = x * *ptr_carre;
}

int main(void) {
   double x = 123.456;
	double carre;
	double cube;
	double* ptr_carre = &carre;
	double* ptr_cube = &cube;
	carree_cube(x, ptr_carre, ptr_cube);
	printf("Valeur: %g\nCarre: %g\nCube: %g", x, *ptr_carre, *ptr_cube);
   return EXIT_SUCCESS;
}


