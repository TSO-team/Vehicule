//Programme: testeInterfaceDEL
//Historique:
// 2020-11-14, Yves Roy, creation
// 2020-11-15, Yves Roy, ajoute des DEL 1, 2, 3 et 4

//INCLUSIONS
#include "main.h"
#include "piloteTicker.h"
#include "piloteEntreeLimiteBasse.h"
#include "piloteSortieDEL.h"
#include "piloteSortieDEL1.h"
#include "piloteSortieDEL2.h"
#include "piloteSortieDEL3.h"
#include "piloteSortieDEL4.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL.h"
#include "interfaceDEL1.h"
#include "interfaceDEL2.h"
#include "interfaceDEL3.h"
#include "interfaceDEL4.h"

//Definitions privees
#define MAIN_TEMPS_ETEINT_EN_MS 1000.0
#define MAIN_COMPTE_MAXIMUM_QUAND_ETEINT (MAIN_TEMPS_ETEINT_EN_MS / PILOTETICKER_PERIODE_EN_MS)

//Declarations de fonctions privees:
//machine a etats: serviceBaseDeTemps_execute[MAIN_TEST_PHASE]
void main_eteintLesDELPendantUnTemps(void);
void main_testeLesInterfacesDEL(void);
void main_initialiseLeTestDesInterfacesDEL(void);

void main_initialise(void);

//Definitions de variables privees:
unsigned long main_compteurDInterruptions;

//Definitions de fonctions privees:
//machine a etats: serviceBaseDeTemps_execute[MAIN_PHASE]
void main_eteintLesDELPendantUnTemps(void)
{
  main_compteurDInterruptions++;
  if (main_compteurDInterruptions < MAIN_COMPTE_MAXIMUM_QUAND_ETEINT)
  {
    return;
  }
  serviceBaseDeTemps_execute[MAIN_TEST_PHASE] = main_testeLesInterfacesDEL;
}

void main_testeLesInterfacesDEL(void)
{
  if (piloteEntreeLimiteBasse_lit() == 1)
  {
    interfaceDEL_etatRequis = INTERFACEDEL_ALLUME;
    interfaceDEL1_etatRequis = INTERFACEDEL1_ALLUME;
    interfaceDEL2_etatRequis = INTERFACEDEL2_ALLUME;
    interfaceDEL3_etatRequis = INTERFACEDEL3_ALLUME;
    interfaceDEL4_etatRequis = INTERFACEDEL4_ALLUME;    
    return;
  }
  interfaceDEL_etatRequis = INTERFACEDEL_CLIGNOTANT;
  interfaceDEL1_etatRequis = INTERFACEDEL1_CLIGNOTANT;
  interfaceDEL2_etatRequis = INTERFACEDEL2_CLIGNOTANT;
  interfaceDEL3_etatRequis = INTERFACEDEL3_CLIGNOTANT;
  interfaceDEL4_etatRequis = INTERFACEDEL4_CLIGNOTANT;
}

void main_initialise(void)
{
  piloteTicker_initialise();
  piloteEntreeLimiteBasse_initialise();
  piloteSortieDEL_initialise();
  piloteSortieDEL1_initialise();  
  piloteSortieDEL2_initialise(); 
  piloteSortieDEL3_initialise();
  piloteSortieDEL4_initialise();  
  serviceBaseDeTemps_initialise();
  interfaceDEL_initialise();
  interfaceDEL1_initialise();
  interfaceDEL2_initialise();
  interfaceDEL3_initialise();
  interfaceDEL4_initialise();        
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
  main_compteurDInterruptions = 0;
  interfaceDEL_etatRequis = INTERFACEDEL_ETEINT;
  interfaceDEL1_etatRequis = INTERFACEDEL1_ETEINT;
  interfaceDEL2_etatRequis = INTERFACEDEL2_ETEINT;
  interfaceDEL3_etatRequis = INTERFACEDEL3_ETEINT;
  interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
  serviceBaseDeTemps_execute[MAIN_TEST_PHASE] = main_eteintLesDELPendantUnTemps;  
  piloteTicker_lanceLeTickerALaTouteFinDeSetup();
}

void loop()
{
}
