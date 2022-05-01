/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_1.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 01.05.2022

 Description    : Correction d'erreurs

 Remarque(s)    : Erreurs avec types composés pas d'ajout/suppression de ligne

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

struct S {
	int a; // il faut séparer les membres par ;
	char b[3];
}; // ; à la fin obligatoire

void afficher(struct S* s); // manquait struct ici

int main(void) {
	struct S s = {.a = 1, .b = "ABC"}; // keyword struct obligatoire, .a = 1 pas a = 1
	afficher(&s); // besoin du &
	return EXIT_SUCCESS;
}

void afficher(struct S* s) { // keyword struct manque
	// mettre \ pour afficher " dans printf
	printf("a = %d, b = \"%s\"\n", s->a, s->b); // s->a pas s.a car pointeur
}
