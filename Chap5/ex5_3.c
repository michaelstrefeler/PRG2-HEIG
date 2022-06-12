/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex5_2.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 12.06.2022

 Description    : Lecture intégrale d'un fichier binaire

 Remarque(s)    : Lire contenu et aligner correctement

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define NOM_FICHIER_BINAIRE "..\\Chap5\\personnes.dat"
#define NOM_FICHIER_TEXTE "..\\Chap5\\personnes.txt"
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

int main(void) {
	FILE* fichier_binaire = fopen(NOM_FICHIER_BINAIRE, "rb");
	if (!fichier_binaire) {
		printf("Desole! Le fichier \"%s\" n'a pas pu etre ouvert\n",
				 NOM_FICHIER_BINAIRE);
		return EXIT_FAILURE;
	} else {
		FILE* fichier_texte = fopen(NOM_FICHIER_TEXTE, "w");
		if (!fichier_texte) {
			printf("Desole! Le fichier \"%s\" n'a pas pu etre ouvert\n",
					 NOM_FICHIER_TEXTE);
			fclose(fichier_binaire);
			return EXIT_FAILURE;
		} else {
			Personne p;
			fprintf(fichier_texte, "%-*s %-*s %s\n", TAILLE_MAX_NOM, "Nom",
					  TAILLE_MAX_PRENOM, "Prenom", "Age");
			while (fread(&p, sizeof(Personne), 1, fichier_binaire)) {
				fprintf(fichier_texte, "%-*s %-*s %3hu\n", TAILLE_MAX_NOM, p.nom,
						  TAILLE_MAX_PRENOM, p.prenom, p.age);
			}
			fclose(fichier_binaire);
			fclose(fichier_texte);
			printf("C'est fini!");
			return EXIT_SUCCESS;
		}
	}
	return EXIT_SUCCESS;
}
