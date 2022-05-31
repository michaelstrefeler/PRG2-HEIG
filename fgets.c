//
// Created by mstre on 31/05/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saisie(char* texte, size_t taille);
#define LG_MAX 8

int main(void){

	char texte[LG_MAX + 1];
	for(int i = 0; i < 2; ++i){
		printf("Tapez votre texte > ");
		saisie(texte, LG_MAX);
		printf("%s\n", texte);
	}
	return EXIT_SUCCESS;
}

void saisie(char* texte, size_t taille){
	fgets(texte, (int)taille+1, stdin);
	fseek(stdin, 0, SEEK_END); // vide le buffer

	/*for(size_t i = 0; i < taille; ++i){
		if(texte[i] == '\n'){
			texte[i] = '\0';
			break;
		}
	}*/

	// On pourrait aussi écrire
	char* adrFinLigne = strchr(texte, '\n');
	if(adrFinLigne)
		*adrFinLigne = '\0';
}
