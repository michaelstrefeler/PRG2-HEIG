/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex2_14.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 28.03.2022

 Description    : Pointeurs, tableaux et fonctions

 Remarque(s)    : Que va afficher le programme main ci-dessous ?

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

void f(int* p1, int p2);
int main(void) {
	int a = 5, b = 6;
	int t[2] = {3, 4};
	int *p = NULL, *q = NULL;
	f(&a, b);
	printf("1) %d, %d\n", a, b); // 12, 6
	p = &a;
	q = &b;
	f(q, *p);
	printf("2) %d, %d\n", *p, *q); // 12, 24
	f(t + 1, *t);
	printf("3) %d, %d\n", t[0], t[1]); // 3, 6
	f((int*)(&p), b);
	printf("4) %d, %d\n", a, b); // 12, 24
   return EXIT_SUCCESS;
}

void f(int* p1, int p2) {
	*p1 = 2 * p2;
}
