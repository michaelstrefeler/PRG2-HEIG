/*
 -----------------------------------------------------------------------------------
 Nom du fichier : <nom du fichier>.<x> (x = h ou c)
 Auteur(s)      : Michael Strefeler
 Date creation  : 12.06.2022

 Description    : Recherche séquentielle dans un fichier binaire

 Remarque(s)    : Chercher si une personne est dans le fichier et donner ses infos
 						si c'est le cas

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/
#include <stdbool.h>
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

void lire(char* chaine, size_t taille);

int main(void) {
	FILE* fichier = fopen(NOM_FICHIER, "rb");
	if (!fichier) {
		printf("Desole! Le fichier \"%s\" n'a pas pu etre ouvert\n", NOM_FICHIER);
		return EXIT_FAILURE;
	} else {
		Personne p;
		Nom nomRecherche;
		printf("Quel nom recherchez-vous ? : ");
		lire(nomRecherche, TAILLE_MAX_NOM);
		bool trouve = false;
		while (!trouve && fread(&p, sizeof(Personne), 1, fichier))
			trouve = strcmp(p.nom, nomRecherche) == 0;
		fclose(fichier);
		if (trouve) printf("%s %s, %hu ans\n", p.prenom, p.nom, p.age);
		else
			printf("Desole! Le nom \"%s\" ne figure pas dans le fichier\n",
					 nomRecherche);
		return EXIT_SUCCESS;
	}
}

void lire(char* chaine, size_t taille) {
	fgets(chaine, (int) taille + 1, stdin);
	fseek(stdin, 0, SEEK_END);
	for (size_t i = 0; i < taille; ++i)
		if (chaine[i] == '\n') {
			chaine[i] = '\0';
			break;
		}
}
