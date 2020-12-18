//piloteSortieDEL:
//Historique: 
// 2020-11-14, Yves Roy, creation a partir de piloteSortieDEL pour STM8

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL.h"

//Definitions privees
//pas de definitions privees

//Declarations de fonctions privees:
//pas de fonctions privees

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:
//pas de fonctions privees

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void piloteSortieDEL_metAUn(void)
{
  digitalWrite(PILOTESORTIEDEL_BROCHE, HIGH);
}

void piloteSortieDEL_metAZero(void)
{
  digitalWrite(PILOTESORTIEDEL_BROCHE, LOW);
}

void piloteSortieDEL_change(void)
{
  digitalWrite(PILOTESORTIEDEL_BROCHE, !digitalRead(PILOTESORTIEDEL_BROCHE));
}

void piloteSortieDEL_initialise(void)
{
#ifdef PILOTESORTIEDEL_ETAT_INITIAL_A_UN
	digitalWrite(PILOTESORTIEDEL_BROCHE, HIGH);
#endif

#ifdef PILOTESORTIEDEL_ETAT_INITIAL_A_ZERO
	digitalWrite(PILOTESORTIEDEL_BROCHE, LOW);
#endif
  pinMode(PILOTESORTIEDEL_BROCHE, OUTPUT); 
}
