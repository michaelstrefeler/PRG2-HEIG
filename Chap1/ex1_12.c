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

#include <stdlib.h>
#include <stdio.h>

void clear_stdin(void);
int main(void) {
	int n;
	char c;
	printf("%s", "Donnez un nombre entier et un caractere : ");
	if (scanf("%d %c", &n, &c) == 2)
		printf("n = %d, c = %c\n", n, c);
	clear_stdin();
	return EXIT_SUCCESS;
}
void clear_stdin(void) {
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

/* clear_stdin ne fonctionne que si le buffer n'est pas initialement vide.
 * Une autre variante, fonctionnant dans tous les cas, consisterait à écrire
 */
//void clear_stdin(void) { fseek(stdin, 0, SEEK_END); }