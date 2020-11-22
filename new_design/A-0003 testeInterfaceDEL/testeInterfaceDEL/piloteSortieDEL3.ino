//piloteSortieDEL3:
//Historique: 
// 2020-11-15, Yves Roy, creation a partir de piloteSortieDEL

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL3.h"

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
void piloteSortieDEL3_metAUn(void)
{
  digitalWrite(PILOTESORTIEDEL3_BROCHE, HIGH);
}

void piloteSortieDEL3_metAZero(void)
{
  digitalWrite(PILOTESORTIEDEL3_BROCHE, LOW);
}

void piloteSortieDEL3_change(void)
{
  digitalWrite(PILOTESORTIEDEL3_BROCHE, !digitalRead(PILOTESORTIEDEL3_BROCHE));
}

void piloteSortieDEL3_initialise(void)
{
#ifdef PILOTESORTIEDEL3_ETAT_INITIAL_A_UN
	digitalWrite(PILOTESORTIEDEL3_BROCHE, HIGH);
#endif

#ifdef PILOTESORTIEDEL3_ETAT_INITIAL_A_ZERO
	digitalWrite(PILOTESORTIEDEL3_BROCHE, LOW);
#endif
  pinMode(PILOTESORTIEDEL3_BROCHE, OUTPUT); 
}
