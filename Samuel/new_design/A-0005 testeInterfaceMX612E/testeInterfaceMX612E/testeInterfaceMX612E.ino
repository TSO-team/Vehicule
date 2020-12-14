//Programme: testeInterfaceMX612E
//Historique:
// 2020-11-14, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteTicker.h"
#include "piloteEntreeLimiteBasse.h"
#include "piloteSortieDEL.h"
#include "pilotePWM.h"
#include "serviceBaseDeTemps.h"
#include "interfaceMX612E.h"

//Definitions privees

//Declarations de fonctions privees:
void main_teste(void);
void main_initialise(void);

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:
void main_teste(void)
{
  if (piloteEntreeLimiteBasse_lit() == 1)
  {
    interfaceMX612E_rapportEnPourcentageSignePourAB = 100;
    piloteSortieDEL_metAUn();
    return;
  }
  interfaceMX612E_rapportEnPourcentageSignePourAB = 0;
  piloteSortieDEL_metAZero();
}

void main_initialise(void)
{
  piloteTicker_initialise();
  piloteEntreeLimiteBasse_initialise();
  piloteSortieDEL_initialise();
  pilotePWM_initialise();
  serviceBaseDeTemps_initialise();
  interfaceMX612E_initialise();
}

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void neFaitRien(void)
{
}

void setup()
{
  main_initialise();
  piloteSortieDEL_metAZero();
  interfaceMX612E_rapportEnPourcentageSignePourAB = 0;  
  serviceBaseDeTemps_execute[MAIN_TEST_PHASE] = main_teste;  
  piloteTicker_lanceLeTickerALaTouteFinDeSetup();
}

void loop()
{
}
