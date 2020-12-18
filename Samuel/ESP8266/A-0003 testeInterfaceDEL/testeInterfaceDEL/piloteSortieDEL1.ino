//piloteSortieDEL1:
//Historique: 
// 2020-11-15, Yves Roy, creation a partir de piloteSortieDEL

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL1.h"

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
void piloteSortieDEL1_metAUn(void)
{
  digitalWrite(PILOTESORTIEDEL1_BROCHE, HIGH);
}

void piloteSortieDEL1_metAZero(void)
{
  digitalWrite(PILOTESORTIEDEL1_BROCHE, LOW);
}

void piloteSortieDEL1_change(void)
{
  digitalWrite(PILOTESORTIEDEL1_BROCHE, !digitalRead(PILOTESORTIEDEL1_BROCHE));
}

void piloteSortieDEL1_initialise(void)
{
#ifdef PILOTESORTIEDEL1_ETAT_INITIAL_A_UN
	digitalWrite(PILOTESORTIEDEL1_BROCHE, HIGH);
#endif

#ifdef PILOTESORTIEDEL1_ETAT_INITIAL_A_ZERO
	digitalWrite(PILOTESORTIEDEL1_BROCHE, LOW);
#endif
  pinMode(PILOTESORTIEDEL1_BROCHE, OUTPUT); 
}
