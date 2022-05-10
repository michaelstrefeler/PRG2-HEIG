/*
 -----------------------------------------------------------------------------------
 Nom du fichier : ex3_4.c
 Auteur(s)      : Michael Strefeler
 Date creation  : 01.05.2022

 Description    : Lendemain d’une date

 Remarque(s)    : Programme qui détermine et affiche le lendemain d’une date donnée.
 						Date sous la forme d’une structure à 3 membres : jour (de type
 						uint_8), mois (de type uint_8) et année (de type uint16_t)
						Structurer le code en fonctions
						Tenir compte des années bissextiles dans le calcul du lendemain
						Afficher les dates au format jj.mm.aaaa

 Compilateur    : Mingw-w64 gcc 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Format d'affichage d'une date (jj.mm.aaaa)
#define FORMAT_DATE "%02" PRIu8 ".%02" PRIu8 ".%04" PRIu16

typedef struct {
	uint8_t jour;
	uint8_t mois;
	uint16_t annee;
} Date;

bool estBissextile(uint16_t annee);
uint8_t nbJoursDansMois(uint8_t mois, uint16_t annee);
const char* toString(const Date* d);
Date lendemain(const Date* d);
void test(const Date* d);

int main(void) {
	test(&(Date) {28, 2, 2000});
	test(&(Date) {29, 2, 2000});
	test(&(Date) {30, 11, 2000});
	test(&(Date) {31, 12, 2000});
	return EXIT_SUCCESS;
}

bool estBissextile(uint16_t annee){
	return annee % 400 == 0 || (annee % 4 == 0 && annee % 100);
}

uint8_t nbJoursDansMois(uint8_t mois, uint16_t annee) {
	static const uint8_t NB_JOURS_DANS_MOIS[] = {31, 29, 31, 30, 31, 30,
																31, 31, 30,	31,30,31};
	if(mois == 2 && estBissextile(annee))
		return (uint8_t) (NB_JOURS_DANS_MOIS[1] + 1);
	else
		return (uint8_t) (NB_JOURS_DANS_MOIS[mois - 1]);
}

const char* toString(const Date* d){
	char* str = (char*) calloc(11, sizeof(char));
	if (str)
		sprintf(str, FORMAT_DATE, d->jour, d->mois, d->annee);
	return str;
}

Date lendemain(const Date* d){
	Date lendemain;
	if(d->jour != nbJoursDansMois(d->mois, d->annee))
		lendemain = (Date) {(uint8_t) (d->jour+1), d->mois, d->annee};
	else if (d->mois < 12)
		lendemain = (Date) {1, (uint8_t) (d->mois + 1), d->annee};
	else
		lendemain = (Date) {1,1, (uint16_t) (d->annee + 1)};
	return lendemain;
}

/*
// Variante sans restitution explicite de la mémoire
void test(const Date* d) {
	Date leLendemain = lendemain(d);
	printf("Le lendemain du %s est le %s\n", toString(d), toString(&leLendemain));
}
*/

// Variante avec restitution explicite de la mémoire
void test(const Date* d){
	Date leLendemain = lendemain(d);
	const char* str1 = toString(d);
	const char* str2 = toString(&leLendemain);
	printf("Le lendemain du %s est le %s\n", str1, str2);
	free((char*)str1);
	free((char*)str2);
}
