//interfaceLimiteBasse:
//Historique: 
// 2018-09-24, Yves Roy, creation

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
unsigned int compteurAvantLecture;
unsigned int compteurAntiRebond;

//Definitions de fonctions privees:
void interfaceLimiteBasse_gere(void)
{
    compteurAvantLecture++;
    if (compteurAvantLecture < INTERFACELIMITEBASSE_COMPTE_MAXIMUM_AVANT_LECTURE)
    {
        return;
    }
    compteurAvantLecture = 0;
    if (piloteEntreeLimiteBasse_lit() == INTERFACELIMITEBASSE_VALEUR_LUE_SI_APPUYE)
    {
        if (compteurAntiRebond == INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION)
        {
            return;
        }
        compteurAntiRebond++;
        if (compteurAntiRebond < INTERFACELIMITEBASSE_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION)
        {
            return;
        }
        interfaceLimiteBasse.etatDuModule = MODULE_EN_FONCTION;
        interfaceLimiteBasse.etatDuBouton = INTERFACELIMITEBASSE_APPUYE;
        interfaceLimiteBasse.information = INFORMATION_DISPONIBLE;
        return;
    }
    if (compteurAntiRebond == 0)
    {
        return;
    }
    compteurAntiRebond--;
    if (compteurAntiRebond > 0)
    {
        return;
    }
    interfaceLimiteBasse.etatDuModule = MODULE_EN_FONCTION;
    interfaceLimiteBasse.etatDuBouton = INTERFACELIMITEBASSE_RELACHE;
    interfaceLimiteBasse.information = INFORMATION_DISPONIBLE;
}

//Definitions de variables publiques:
INTERFACELIMITEBASSE interfaceLimiteBasse;

//Definitions de fonctions publiques:
void interfaceLimiteBasse_initialise(void)
{
    interfaceLimiteBasse.etatDuModule = MODULE_PAS_EN_FONCTION;
    interfaceLimiteBasse.information = INFORMATION_TRAITEE;
    interfaceLimiteBasse.etatDuBouton = INTERFACELIMITEBASSE_INCONNU;
    compteurAvantLecture = 0;
    compteurAntiRebond = INTERFACELIMITEBASSE_COMPTE_INITIAL;
    serviceBaseDeTemps_execute[INTERFACELIMITEBASSE_PHASE] = interfaceLimiteBasse_gere;
}

