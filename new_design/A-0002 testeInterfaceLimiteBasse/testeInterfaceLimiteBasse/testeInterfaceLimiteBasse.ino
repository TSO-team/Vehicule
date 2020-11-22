//Programme: testeInterfaceLimiteBasse
//Historique:
// 2020-11-13, Yves Roy, creation


//INCLUSIONS
#include "main.h"
#include "piloteTicker.h"
#include "piloteEntreeLimiteBasse.h"
#include "serviceBaseDeTemps.h"
#include "interfaceLimiteBasse.h"

//Definitions privees
#define MAIN_DEL 13
#define MAIN_ALLUME 1
#define MAIN_ETEINT 0

//Declarations de fonctions privees:
void main_teste(void);
void main_initialise(void);

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:
void main_teste(void)
{
  if (interfaceLimiteBasse.etatDuModule == INTERFACELIMITEBASSE_MODULE_PAS_EN_FONCTION)
  {
    return;
  }
  if (interfaceLimiteBasse.etatDeLEntree == INTERFACELIMITEBASSE_ACTIVE)
  {
    digitalWrite(MAIN_DEL, MAIN_ALLUME);
    return;
  }
  digitalWrite(MAIN_DEL, MAIN_ETEINT);
}

void main_initialise(void)
{
  piloteTicker_initialise();
  piloteEntreeLimiteBasse_initialise();
  serviceBaseDeTemps_initialise();
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
  digitalWrite(MAIN_DEL, MAIN_ETEINT);
  pinMode(MAIN_DEL, OUTPUT);
  serviceBaseDeTemps_execute[MAIN_TEST_PHASE] = main_teste;
  piloteTicker_lanceLeTickerALaTouteFinDeSetup();
}

void loop()
{
}
