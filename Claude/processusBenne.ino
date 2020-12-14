//processusBenne:
//Historique: 
// 2018-09-30, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL1.h"
#include "interfaceDEL2.h"
#include "interfaceDEL3.h"
#include "interfaceDEL4.h"
#include "interfaceMX612E.h"
#include "interfaceWifi.h"
#include "serviceTensionLimiteeMX612E.h"
#include "piloteEntreeLimiteBasse.h"
#include "processusBenne.h"

//Definitions privees


//Declarations de fonctions privees:
void processusBenne_attendLimiteBasse(void);
void processusBenne_attendUneDemande(void);
void processusBenne_attendActivation(void);
void processusBenne_attendFinDAjustement(void);
void processusBenne_attendUneRequete(void);
void processusBenne_gere(void);

//Definitions de variables privees:
unsigned long processusBenne_compteur = 0;
unsigned long processusBenne_compteurTemoinBenne = 0;
signed int processusBenne_valeurPMW = 80;
unsigned char DejaBaissee = 'N';


//Definitions de fonctions privees:
void processusBenne_attendLimiteBasse(void)
{
	if (interfaceLimiteBasse.etatDuModule == MODULE_PAS_EN_FONCTION)
	{
		return;
	}
	if (processusBenne_compteur++ < 2000)
	{
		interfaceMX612E_rapportEnPourcentageSigne = 0;
		return;
	}
	interfaceMX612E_rapportEnPourcentageSigne = 100;
	serviceBaseDeTemps_execute[PROCESSUSBENNE_PHASE] =
		processusBenne_attendUneDemande;
}

void processusBenne_attendUneDemande(void)
{
	interfaceMX612E_rapportEnPourcentageSigne = 0;
	if (piloteEntreeLimiteBasse_lit() == INACTIVE)
	{
		serviceBaseDeTemps_execute[PROCESSUSBENNE_PHASE] =
			processusBenne_attendActivation;
	}
	if (piloteEntreeLimiteBasse_lit() == ACTIVE)
	{
		serviceBaseDeTemps_execute[PROCESSUSBENNE_PHASE] =
			processusBenne_attendFinDAjustement;
	}
}

void processusBenne_attendActivation(void)
{
	if (piloteEntreeLimiteBasse_lit() == INACTIVE)
	{
		return;
		interfaceMX612E_rapportEnPourcentageSigne = 100;
	}
	serviceBaseDeTemps_execute[PROCESSUSBENNE_PHASE] =
		processusBenne_attendFinDAjustement;
}

void processusBenne_attendFinDAjustement(void)
{
	if (piloteEntreeLimiteBasse_lit() == ACTIVE)
	{
		return;
		processusBenne_valeurPMW = 100;
	}
	serviceBaseDeTemps_execute[PROCESSUSBENNE_PHASE] =
		processusBenne_attendUneRequete;
}

void processusBenne_attendUneRequete (void)
{
	if (processusBenne_Requete == INACTIVE)
	{
		return;
	}
	serviceBaseDeTemps_execute[PROCESSUSBENNE_PHASE] =
		processusBenne_attendActivation;
}

void processusBenne_gere(void)
{
	interfaceMX612E_rapportEnPourcentageSigne = processusBenne_valeurPMW;

	if (processusBenne_commandeBenne == ACTIVE)
	{
		Serial.write('Y');
		DejaBaissee = 'Y';
	}
	else if (processusBenne_commandeBenne == INACTIVE)
	{
		DejaBaissee = 'N';
	}

	if (DejaBaissee == 'Y')
	{
		processusBenne_compteurTemoinBenne ++;
		if (piloteEntreeLimiteBasse_lit() == 0)
		{

		}
		processusBenne_valeurPMW = -100;
		if (processusBenne_compteurTemoinBenne > 1200)
		{
			DejaBaissee = 'N';
			processusBenne_compteurTemoinBenne = 0;
			processusBenne_valeurPMW = 0;
			interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
		}
	}


	if (DejaBaissee == 'N')
	{
		processusBenne_valeurPMW = 0;
	}

}


//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void processusBenne_initialise(void)
{
	processusBenne_valeurPMW = 100;
	processusBenne_compteur = 0;
	processusBenne_commandeBenne = INACTIVE;
	processusBenne_Requete = INACTIVE;
	serviceBaseDeTemps_execute[PROCESSUSBENNE_PHASE] = processusBenne_gere;
}
