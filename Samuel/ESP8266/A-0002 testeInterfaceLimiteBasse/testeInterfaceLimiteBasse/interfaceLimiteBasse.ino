//interfaceLimiteBasse:
//Historique:
// 2020-11-13, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteEntreeLimiteBasse.h"
#include "serviceBaseDeTemps.h"
#include "interfaceLimiteBasse.h"

//Definitions privees
#define INTERFACELIMITEBASSE_COMPTE_MAXIMUM_AVANT_LECTURE  (\
  SERVICEBASEDETEMPS_FREQUENCE_EN_HZ/INTERFACELIMITEBASSE_FREQUENCE_DES_LECTURES_EN_HZ)
#define INTERFACELIMITEBASSE_COMPTE_INITIAL (\
  INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION/2)

//Declarations de fonctions privees:
void interfaceLimiteBasse_gere(void);

//Definitions de variables privees:
unsigned int interfaceLimiteBasse_compteurAvantLecture;
unsigned int interfaceLimiteBasse_compteurAntiRebond;

//Definitions de fonctions privees:
void interfaceLimiteBasse_gere(void)
{
  interfaceLimiteBasse_compteurAvantLecture++;
  if (interfaceLimiteBasse_compteurAvantLecture < INTERFACELIMITEBASSE_COMPTE_MAXIMUM_AVANT_LECTURE)
  {
    return;
  }
  interfaceLimiteBasse_compteurAvantLecture = 0;
  if (piloteEntreeLimiteBasse_lit() == INTERFACELIMITEBASSE_VALEUR_LUE_SI_ACTIVE)
  {
    if (interfaceLimiteBasse_compteurAntiRebond ==
				INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION)
    {
      return;
    }
    interfaceLimiteBasse_compteurAntiRebond++;
    if (interfaceLimiteBasse_compteurAntiRebond <
				INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION)
    {
      return;
    }    
    interfaceLimiteBasse.etatDuModule = INTERFACELIMITEBASSE_MODULE_EN_FONCTION;
    interfaceLimiteBasse.etatDeLEntree = INTERFACELIMITEBASSE_ACTIVE;
    interfaceLimiteBasse.information = INTERFACELIMITEBASSE_INFORMATION_DISPONIBLE;       
    return;
  }
  if (interfaceLimiteBasse_compteurAntiRebond == 0)
  {
    return; 
  }
  interfaceLimiteBasse_compteurAntiRebond--;
  if (interfaceLimiteBasse_compteurAntiRebond > 0)
  {
    return;
  }
  interfaceLimiteBasse.etatDuModule = INTERFACELIMITEBASSE_MODULE_EN_FONCTION;  
  interfaceLimiteBasse.etatDeLEntree = INTERFACELIMITEBASSE_INACTIVE;
  interfaceLimiteBasse.information = INTERFACELIMITEBASSE_INFORMATION_DISPONIBLE;
}

//Definitions de variables publiques:
INTERFACELIMITEBASSE interfaceLimiteBasse;

//Definitions de fonctions publiques:
void interfaceLimiteBasse_initialise(void)
{
  interfaceLimiteBasse.etatDuModule = INTERFACELIMITEBASSE_MODULE_PAS_EN_FONCTION;
  interfaceLimiteBasse.information = INTERFACELIMITEBASSE_INFORMATION_TRAITEE;
  interfaceLimiteBasse.etatDeLEntree = INTERFACELIMITEBASSE_INCONNUE;
	interfaceLimiteBasse_compteurAvantLecture = 0;
  interfaceLimiteBasse_compteurAntiRebond = INTERFACELIMITEBASSE_COMPTE_INITIAL;
  serviceBaseDeTemps_execute[INTERFACELIMITEBASSE_PHASE] = interfaceLimiteBasse_gere;
}
