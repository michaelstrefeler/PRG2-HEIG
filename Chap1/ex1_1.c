/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_1.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 28.02.2022

 Description    : Exercice 1.1

 Remarque(s)    : Substitutions

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define A 1
#define B 2
#define AB 3
#define F(X,Y) X##Y

int main(void) {
	int n = AB;

	printf("%d\n", n); // %d car c'est un entier
	printf("%s\n", "AB"); // %s car c'est un string
	printf("%d\n", F(A,B)); // %d car c'est un entier. Affiche la valeur de AB
	/* le programme va afficher:
	 * 3
	 * AB
	 * 3
	 */

	/* Si AB n'avait pas été défini, le programme aurait levé une erreur à la
	 * compilation error 'AB' undeclared
	 */
	return EXIT_SUCCESS;
}
