/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_8.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 28.03.2022

 Description    : Arithmétique des pointeurs (2)

 Remarque(s)    : Que va afficher le programme main ci-dessous ?

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int t[6], i, *p;
	for (p = &t[5]; p > &t[-1]; p--)
		*p = (int) (p - t);

	for (i = 0; i < 6; i++)
		printf("%d ", t[i]);
	printf("\n");

	for (i = 0, ++p; i < 6; i++)
		printf("%d ", *p++/2);
	printf("\n");
	return EXIT_SUCCESS;
}
