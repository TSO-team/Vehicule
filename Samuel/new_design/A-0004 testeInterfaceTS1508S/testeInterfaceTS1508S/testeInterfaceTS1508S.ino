//Programme: testeInterfaceTS1508S
//Historique:
// 2020-11-14, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteTicker.h"
#include "piloteEntreeLimiteBasse.h"
#include "piloteSortieDEL.h"
#include "pilotePWM.h"
#include "serviceBaseDeTemps.h"
#include "interfaceTS1508S.h"

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
    interfaceTS1508S_rapportEnPourcentageSignePourAB = 99;//60;
    interfaceTS1508S_rapportEnPourcentageSignePourCD = 1;//40;    
    piloteSortieDEL_metAUn();
    return;
  }
  interfaceTS1508S_rapportEnPourcentageSignePourAB = -1; //-100;//-20;
  interfaceTS1508S_rapportEnPourcentageSignePourCD = -99;//100;//+50;  
  piloteSortieDEL_metAZero();
}

void main_initialise(void)
{
  piloteTicker_initialise();
  piloteEntreeLimiteBasse_initialise();
  piloteSortieDEL_initialise();
  pilotePWM_initialise();
  serviceBaseDeTemps_initialise();
  interfaceTS1508S_initialise();
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
  interfaceTS1508S_rapportEnPourcentageSignePourAB = 0;  
  interfaceTS1508S_rapportEnPourcentageSignePourCD = 0;
  serviceBaseDeTemps_execute[MAIN_TEST_PHASE] = main_teste;  
  piloteTicker_lanceLeTickerALaTouteFinDeSetup();
}

void loop()
{
}
