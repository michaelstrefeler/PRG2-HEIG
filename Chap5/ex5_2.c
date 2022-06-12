/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex5_2.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 12.06.2022

 Description    : Ecriture d'un fichier binaire

 Remarque(s)    : Une personne doit écrire son nom, prénom et age

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_FICHIER "..\\Chap5\\personnes.dat"
#define TAILLE_MAX_NOM 20
#define TAILLE_MAX_PRENOM 15

typedef char Nom[TAILLE_MAX_NOM + 1];
typedef char Prenom[TAILLE_MAX_PRENOM + 1];
typedef unsigned short Age;

typedef struct {
	Nom nom;
	Prenom prenom;
	Age age;
} Personne;

void saisie(char* chaine, size_t taille);

void clear_stdin(void);

int main(void) {
	FILE* fichier = fopen(NOM_FICHIER, "ab+");
	if (!fichier) {
		printf("Desole! Le fichier \"%s\" n'a pas pu etre ouvert", NOM_FICHIER);
		return EXIT_FAILURE;
	}
	Personne p;
	printf("--- Pour finir la saisie, donnez un nom 'vide' ---\n");
	do {
		printf("\nNom: ");
		saisie(p.nom, TAILLE_MAX_NOM);
		if (strlen(p.nom) == 0) break;
		printf("Prenom : ");
		saisie(p.prenom, TAILLE_MAX_PRENOM);
		printf("Age: ");
		scanf("%hu", &p.age);
		clear_stdin();
		fwrite(&p, sizeof(Personne), 1, fichier);
	} while (1);
	fclose(fichier);
	return EXIT_SUCCESS;
}

void saisie(char* chaine, size_t taille) {
	fgets(chaine, (int) taille + 1, stdin);
	clear_stdin();
	for (size_t i = 0; i < taille; ++i)
		if (chaine[i] == '\n') {
			chaine[i] = '\0';
			break;
		}
}

void clear_stdin(void) {
	fseek(stdin, 0, SEEK_END);
}
