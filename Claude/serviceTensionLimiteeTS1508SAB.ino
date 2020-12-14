//serviceTensionLimiteeTS1508SAB:
//Historique: 
// 2018-12-15, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "interfaceTS1508S.h"
#include "serviceTensionLimiteeTS1508SAB.h"

//Definitions privees
#define SERVICETENSIONLIMITEETS1508SAB_COMPTE_POUR_CHANGEMENT  ((unsigned int)\
  ((SERVICEBASEDETEMPS_FREQUENCE_EN_HZ*SERVICETENSIONLIMITEETS1508SAB_DUREE_DES_PAS_EN_MS)/1000.0))

//Declarations de fonctions privees:
void serviceTensionLimiteeTS1508SAB_gereUnRapportRequisAtteint(void);
void serviceTensionLimiteeTS1508SAB_gereUnRapportRequisNonAtteint(void);

//Definitions de variables privees:
unsigned int serviceTensionLimiteeTS1508SAB_compteurAvantChangement;
signed char serviceTensionLimiteeTS1508SAB_rapportEnCours;

//Definitions de fonctions privees:
//machine a etats: serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SAB_PHASE]
void serviceTensionLimiteeTS1508SAB_gereUnRapportRequisAtteint(void)
{
	if (serviceTensionLimiteeTS1508SAB_rapportRequisEnPourcentageSigne
			== serviceTensionLimiteeTS1508SAB_rapportEnCours)
	{
		return;
	}
	serviceTensionLimiteeTS1508SAB_compteurAvantChangement = 0;	
  serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SAB_PHASE] =
			serviceTensionLimiteeTS1508SAB_gereUnRapportRequisNonAtteint;	
}

void serviceTensionLimiteeTS1508SAB_gereUnRapportRequisNonAtteint(void)
{
signed int Requis;
signed int EnCours;

if (serviceTensionLimiteeTS1508SAB_rapportRequisEnPourcentageSigne == 0)
	{
		interfaceTS1508S_rapportEnPourcentageSignePourAB = 0;	
		serviceTensionLimiteeTS1508SAB_rapportEnCours = 0;		
		serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SAB_PHASE] =
				serviceTensionLimiteeTS1508SAB_gereUnRapportRequisAtteint;
		return;
	}

	serviceTensionLimiteeTS1508SAB_compteurAvantChangement++;
  if (serviceTensionLimiteeTS1508SAB_compteurAvantChangement
			< SERVICETENSIONLIMITEETS1508SAB_COMPTE_POUR_CHANGEMENT)
  {
    return;
  }
  serviceTensionLimiteeTS1508SAB_compteurAvantChangement = 0;
	
	Requis = (signed int)serviceTensionLimiteeTS1508SAB_rapportRequisEnPourcentageSigne;
	EnCours = (signed int)serviceTensionLimiteeTS1508SAB_rapportEnCours;
	if (Requis > EnCours)
	{
		EnCours += SERVICETENSIONLIMITEETS1508SAB_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT;
		if (EnCours > (Requis -1))
		{
			EnCours = Requis;
			serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SAB_PHASE] =
					serviceTensionLimiteeTS1508SAB_gereUnRapportRequisAtteint;			
		}
	}
	else
	{
		EnCours -= SERVICETENSIONLIMITEETS1508SAB_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT;
		if (EnCours < (Requis +1))
		{
			EnCours = Requis;
			serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SAB_PHASE] =
					serviceTensionLimiteeTS1508SAB_gereUnRapportRequisAtteint;						
		}
	}
	serviceTensionLimiteeTS1508SAB_rapportEnCours = (signed char)EnCours;
	interfaceTS1508S_rapportEnPourcentageSignePourAB = serviceTensionLimiteeTS1508SAB_rapportEnCours;
}

//Definitions de variables publiques:
signed char serviceTensionLimiteeTS1508SAB_rapportRequisEnPourcentageSigne;

//Definitions de fonctions publiques:
void serviceTensionLimiteeTS1508SAB_initialise(void)
{
	serviceTensionLimiteeTS1508SAB_compteurAvantChangement = 0;	
	serviceTensionLimiteeTS1508SAB_rapportRequisEnPourcentageSigne = 0;
	serviceTensionLimiteeTS1508SAB_rapportEnCours = 0;
	interfaceTS1508S_rapportEnPourcentageSignePourAB = 0;	
  serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SAB_PHASE] =
			serviceTensionLimiteeTS1508SAB_gereUnRapportRequisAtteint;
}
