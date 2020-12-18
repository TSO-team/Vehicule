//Programme: testeServiceTensionLimitee
//Historique:
// 2020-11-15, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteTicker.h"
#include "piloteEntreeLimiteBasse.h"
#include "piloteSortieDEL.h"
#include "pilotePWM.h"
#include "serviceBaseDeTemps.h"
#include "interfaceTS1508S.h"
#include "interfaceMX612E.h"
#include "serviceTensionLimiteeTS1508SAB.h"
#include "serviceTensionLimiteeTS1508SCD.h"
#include "serviceTensionLimiteeMX612E.h"
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
    serviceTensionLimiteeTS1508SAB_rapportRequisEnPourcentageSigne = 100; //changer pour 0 ou autres pour bien tester    
    serviceTensionLimiteeTS1508SCD_rapportRequisEnPourcentageSigne = 100; //changer pour 0 ou autres pour bien tester    
    serviceTensionLimiteeMX612E_rapportRequisEnPourcentageSigne = 80; //changer pour 0 ou autres pour bien tester        
    piloteSortieDEL_metAUn();
    return;
  }
  serviceTensionLimiteeTS1508SAB_rapportRequisEnPourcentageSigne = -100; //changer pour 0 ou autres pour bien tester    
  serviceTensionLimiteeTS1508SCD_rapportRequisEnPourcentageSigne = -100; //changer pour 0 ou autres pour bien tester    
  serviceTensionLimiteeMX612E_rapportRequisEnPourcentageSigne = 20; //changer pour 0 ou autres pour bien tester        
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
  interfaceMX612E_initialise();
  serviceTensionLimiteeTS1508SAB_initialise();
  serviceTensionLimiteeTS1508SCD_initialise();
  serviceTensionLimiteeMX612E_initialise();  
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
  interfaceMX612E_rapportEnPourcentageSigne = 0;  
  serviceBaseDeTemps_execute[MAIN_TEST_PHASE] = main_teste;  
  piloteTicker_lanceLeTickerALaTouteFinDeSetup();
}

void loop()
{
}
