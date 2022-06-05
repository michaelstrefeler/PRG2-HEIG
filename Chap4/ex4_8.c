/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex4_8.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 30.05.2022

 Description    : Prénom et nom

 Remarque(s)    : concat deux strings

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saisie(char* chaine, size_t taille);

char* concat(const char* prenom, const char* nom);

void clear_stdin(void);

int main(void) {
#define TAILLE_MAX_PRENOM 20
#define TAILLE_MAX_NOM 30
	char prenom[TAILLE_MAX_PRENOM + 1];
	char nom[TAILLE_MAX_NOM + 1];
	printf("Entrer le prenom (max %u caract.) : ", TAILLE_MAX_PRENOM);
	saisie(prenom, TAILLE_MAX_PRENOM);
	printf("Entrer le nom (max %u caract.) : ", TAILLE_MAX_NOM);
	saisie(nom, TAILLE_MAX_NOM);
	char* prenom_nom = concat(prenom, nom);
	if (prenom_nom) {
		printf("La chaine \"%s\" comporte %u caracteres.\n", prenom_nom,
				 (unsigned) strlen(prenom_nom));
		free(prenom_nom);
	}
	return EXIT_SUCCESS;
}

void saisie(char* chaine, size_t taille) {
	fgets(chaine, (int) taille + 1, stdin);
	clear_stdin();
	// Remplace la marque de fin de ligne ('\n') év présente dans la chaîne
	// par une marque de fin de chaîne ('\0')
	for (size_t i = 0; i < taille; ++i)
		if (chaine[i] == '\n') {
			chaine[i] = '\0';
			break;
		}
}

char* concat(const char* prenom, const char* nom) {
	// Construire un tableau dynamique de la taille nécessaire
	// stockage du prénom, d'un espace, du nom et du caractère '\0'
	char* resultat = (char*) calloc(strlen(prenom) + strlen(nom) + 2, sizeof(char));
	if (resultat) {
		strcpy(resultat, prenom);
		strcat(resultat, " ");
		strcat(resultat, nom);
	}
	return resultat;
}

void clear_stdin(void) {
	fseek(stdin, 0, SEEK_END);
}
