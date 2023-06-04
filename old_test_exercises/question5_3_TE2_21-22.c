#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NB_MAX_FRUITS 3

typedef enum {BANANE, ORANGE, POMME, PAMPLEMOUSSE} Fruit;
typedef enum {CHIMPANZE, GORILLE} Espece;

const char* const ESPECES[] = {"Chimpanze", "Gorille"};
const char* const FRUITS[] = {"Banane", "Orange", "Pomme", "Pamplemousse"};

typedef struct {
	const char* nom;
	Espece espece;
	union {
		struct {
			uint16_t poids;
			struct {
				uint8_t nb_fruits;
				Fruit fruits[NB_MAX_FRUITS];
			} fruitspreferes;
		} gorille;
		struct {
			uint8_t age;
			bool estAgressif;
		} chimpanze;
	} specificites;
} Singe;

void afficher(const Singe* s, const char* const especes[], const char* const fruits[]);

int main(void){
	Singe chita = {"Chita", CHIMPANZE, {.chimpanze = {12, false}}};
	Singe bobo = {"Bobo", GORILLE, {{250, {2, {BANANE, POMME}}}}};

	afficher(&chita, ESPECES, FRUITS);
	afficher(&bobo, ESPECES, FRUITS);

	return EXIT_SUCCESS;
}

void afficher(const Singe* s, const char* const especes[], const char* const fruits[]){
	// version probablement pas optimal de ce code
	printf("%s est un %s", s->nom, especes[s->espece]);
	if(s->espece == CHIMPANZE){
		printf(" qui a %" PRIu8 " ans et qui %s aggressif\n\n", s->specificites.chimpanze.age, s->specificites.chimpanze.estAgressif ? "est" : "n'est pas");
	}else{
		printf(" qui a un poids de %" PRIu16 " kg\n", s->specificites.gorille.poids);
		printf("Fruit(s) prefere(s): \n");
		for(uint8_t i = 0; i < s->specificites.gorille.fruitspreferes.nb_fruits; ++i){
			printf("- %s\n", FRUITS[s->specificites.gorille.fruitspreferes.fruits[i]]);
		}
		printf("\n");
	}
}
