//piloteEntreeLimiteBasse:
//Historique: 
// 2020-11-13, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteEntreeLimiteBasse.h"

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
unsigned char piloteEntreeLimiteBasse_lit(void)
{
  return digitalRead(PILOTEENTREELIMITEBASSE_BROCHE);
}

void piloteEntreeLimiteBasse_initialise(void)
{
	pinMode(PILOTEENTREELIMITEBASSE_BROCHE, INPUT);
}
