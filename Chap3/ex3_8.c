/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_8.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 16.05.2022

 Description    : Affichage des jours de la semaine (1)

 Remarque(s)    : Pas de vérification de la saisie

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Si l'utilisateur saisit une chaîne correspondant à l'une des châines figurant
 *	dans le tableau tab, alors la fonction renvoie le rang de cette chaine
 *	Renvoie -1 sinon
 */
int lireChaine(const char*const tab[], size_t n, const char* msgInvite);

int main(void) {
	typedef enum {LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE} Jour;
	const char* const JOURS[] = {"lundi", "mardi", "mercredi", "jeudi", "vendredi",
										  "samedi", "dimanche"};
	const size_t NB_JOURS = sizeof(JOURS) / sizeof(char*);
	const char* const MSG_INVITE = "Donnez un jour de la semaine en toutes lettres "
											 "et en minuscules : ";

	Jour jour = (Jour)lireChaine(JOURS, NB_JOURS, MSG_INVITE);
	if((int) jour != -1)
		for(size_t i = 0; i < NB_JOURS; ++i)
			printf("%s\n", JOURS[(jour + i) % NB_JOURS]);
	else
		printf("Saisie incorrecte. Desole!\n");

   return EXIT_SUCCESS;
}

int lireChaine(const char* const tab[], size_t n, const char* msgInvite){
	#define TAILLE_MAX_CHAINE 8
	char chaineControle[4];
	sprintf(chaineControle, "%%%ds", TAILLE_MAX_CHAINE);
	char chaine[TAILLE_MAX_CHAINE + 1];
	printf(msgInvite);
	scanf(chaineControle, chaine);
	fflush(stdin);
	for (size_t i = 0; i < n; ++i)
		if(strcmp(chaine, tab[i]) == 0)
			return (int) i;
	return -1;
}
