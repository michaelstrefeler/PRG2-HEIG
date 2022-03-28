/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex1_12.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 15.03.2022

 Description    : scanf

 Remarque(s)    : Corriger code

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int n;
	char c;
	printf("Donnez un nombre entier et un caractere : ");
	scanf("%d %c", &n, &c);
	printf("n = %d, c = %c\n", n, c);
   return EXIT_SUCCESS;
}
