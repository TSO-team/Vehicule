//piloteSortieDEL2:
//Historique: 
// 2020-11-15, Yves Roy, creation a partir de piloteSortieDEL

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL2.h"

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
void piloteSortieDEL2_metAUn(void)
{
  digitalWrite(PILOTESORTIEDEL2_BROCHE, HIGH);
}

void piloteSortieDEL2_metAZero(void)
{
  digitalWrite(PILOTESORTIEDEL2_BROCHE, LOW);
}

void piloteSortieDEL2_change(void)
{
  digitalWrite(PILOTESORTIEDEL2_BROCHE, !digitalRead(PILOTESORTIEDEL2_BROCHE));
}

void piloteSortieDEL2_initialise(void)
{
#ifdef PILOTESORTIEDEL2_ETAT_INITIAL_A_UN
	digitalWrite(PILOTESORTIEDEL2_BROCHE, HIGH);
#endif

#ifdef PILOTESORTIEDEL2_ETAT_INITIAL_A_ZERO
	digitalWrite(PILOTESORTIEDEL2_BROCHE, LOW);
#endif
  pinMode(PILOTESORTIEDEL2_BROCHE, OUTPUT); 
}
