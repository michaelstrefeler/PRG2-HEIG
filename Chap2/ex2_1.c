/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_1.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 22.03.2022

 Description    : Les bases avec les pointeurs

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int n = 1;
	int* ptr = NULL;
	ptr = &n;
	printf("Valeur de l'objet pointe par ptr: %d\n", *ptr);
	printf("Valeur de l'adresse contenue dans ptr: %p\n", (void *)&n);
	printf("Valeur de l'adresse du ptr: %p\n", (void *)&ptr);

   return EXIT_SUCCESS;
}
