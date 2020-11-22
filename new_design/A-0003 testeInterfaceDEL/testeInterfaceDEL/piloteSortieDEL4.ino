//piloteSortieDEL4:
//Historique: 
// 2020-11-15, Yves Roy, creation a partir de piloteSortieDEL

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL4.h"

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
void piloteSortieDEL4_metAUn(void)
{
  digitalWrite(PILOTESORTIEDEL4_BROCHE, HIGH);
}

void piloteSortieDEL4_metAZero(void)
{
  digitalWrite(PILOTESORTIEDEL4_BROCHE, LOW);
}

void piloteSortieDEL4_change(void)
{
  digitalWrite(PILOTESORTIEDEL4_BROCHE, !digitalRead(PILOTESORTIEDEL4_BROCHE));
}

void piloteSortieDEL4_initialise(void)
{
#ifdef PILOTESORTIEDEL4_ETAT_INITIAL_A_UN
	digitalWrite(PILOTESORTIEDEL4_BROCHE, HIGH);
#endif

#ifdef PILOTESORTIEDEL4_ETAT_INITIAL_A_ZERO
	digitalWrite(PILOTESORTIEDEL4_BROCHE, LOW);
#endif
  pinMode(PILOTESORTIEDEL4_BROCHE, OUTPUT); 
}
