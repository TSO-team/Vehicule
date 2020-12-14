//Programme: testeServiceTensionLimitee
//Historique:
// 2020-11-15, Yves Roy, creation

//INCLUSIONS
#include <Wire.h>
#include <dummy.h>
#include "main.h"
#include "piloteTicker.h"
#include "piloteEntreeLimiteBasse.h"
#include "piloteSortieDEL.h"
#include "pilotePWM.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL.h"
#include "interfaceDEL1.h"
#include "interfaceDEL2.h"
#include "interfaceDEL3.h"
#include "interfaceDEL4.h"
#include "interfaceTS1508S.h"
#include "interfaceMX612E.h"
#include "interfaceLignes.h"
#include "interfaceWifi.h"
#include "interfaceLimiteBasse.h"
#include "serviceTensionLimiteeTS1508SAB.h"
#include "serviceTensionLimiteeTS1508SCD.h"
#include "serviceTensionLimiteeMX612E.h"
#include "processusBenne.h"

//Definitions privees

//Declarations de fonctions privees:
void main_teste(void);
void main_initialise(void);

//Definitions de variables privees:

//pas de variables privees

//Definitions de fonctions privees:
void main_teste(void)
{
    //interfaceMX612E_rapportEnPourcentageSigne = Valeur;
    //if (piloteEntreeLimiteBasse_lit() == 0)
    //{
    //    DejaBaissee = 'Y';
    //    Valeur = 0;
    //    interfaceDEL4_etatRequis = INTERFACEDEL4_ALLUME;
    //    interfaceDEL3_etatRequis = INTERFACEDEL3_ETEINT;
    //    TemoinBenne++;
    //}

    //if (DejaBaissee == 'Y' && TemoinBenne > 2000 )
    //{
    //    //TemoinBenne++;
    //    interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
    //    Valeur = -100;
    //    TemoinBenne++;
    //    if (TemoinBenne > 3800 )
    //    {
    //        Valeur = 0;
    //        interfaceDEL4_etatRequis = INTERFACEDEL4_ALLUME;
    //    }
    //}
    //if (TemoinBenne > 4500)
    //{
    //    interfaceDEL3_etatRequis = INTERFACEDEL3_ALLUME;
    //    TemoinBenne = 0;
    //    Valeur = -100;
    //}   
}

void main_initialise(void)
{
  piloteTicker_initialise();
  piloteEntreeLimiteBasse_initialise();
  pilotePWM_initialise();
  piloteSortieDEL_initialise();
  piloteSortieDEL1_initialise();
  piloteSortieDEL2_initialise();
  piloteSortieDEL3_initialise();
  piloteSortieDEL4_initialise();
  serviceBaseDeTemps_initialise();
  interfaceTS1508S_initialise();
  interfaceMX612E_initialise();
  interfaceDEL_initialise();
  interfaceDEL1_initialise();
  interfaceDEL2_initialise();
  interfaceDEL3_initialise();
  interfaceDEL4_initialise();
  interfaceLignes_initialise();
  serviceTensionLimiteeTS1508SAB_initialise();
  serviceTensionLimiteeTS1508SCD_initialise();
  serviceTensionLimiteeMX612E_initialise(); 

  //On enlève peut-être
  //processusBenne_initialise();
  interfaceWifi_initialise();
  delay(5000);
  processusConduite_initialise();
  interfaceLignes_initialise();
  interfaceLimiteBasse_initialise();

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
  Serial.begin(115200);
  piloteSortieDEL_metAZero();

  interfaceDEL_etatRequis = INTERFACEDEL_ETEINT;
  interfaceDEL1_etatRequis = INTERFACEDEL1_ETEINT;
  interfaceDEL2_etatRequis = INTERFACEDEL2_ETEINT;
  interfaceDEL3_etatRequis = INTERFACEDEL3_ETEINT;
  interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;

  interfaceTS1508S_rapportEnPourcentageSignePourAB = 0;    
  interfaceTS1508S_rapportEnPourcentageSignePourCD = 0;    
  interfaceMX612E_rapportEnPourcentageSigne = 0;  
  serviceBaseDeTemps_execute[MAIN_TEST_PHASE] = main_teste;  
  piloteTicker_lanceLeTickerALaTouteFinDeSetup();
}

void loop()
{
}
