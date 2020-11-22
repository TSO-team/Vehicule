//serviceTensionLimiteeTS1508SCD:
//Historique: 
// 2018-12-15, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "interfaceTS1508S.h"
#include "serviceTensionLimiteeTS1508SCD.h"

//Definitions privees
#define SERVICETENSIONLIMITEETS1508SCD_COMPTE_POUR_CHANGEMENT  ((unsigned int)\
  ((SERVICEBASEDETEMPS_FREQUENCE_EN_HZ*SERVICETENSIONLIMITEETS1508SCD_DUREE_DES_PAS_EN_MS)/1000.0))

//Declarations de fonctions privees:
void serviceTensionLimiteeTS1508SCD_gereUnRapportRequisAtteint(void);
void serviceTensionLimiteeTS1508SCD_gereUnRapportRequisNonAtteint(void);

//Definitions de variables privees:
unsigned int serviceTensionLimiteeTS1508SCD_compteurAvantChangement;
signed char serviceTensionLimiteeTS1508SCD_rapportEnCours;

//Definitions de fonctions privees:
//machine a etats: serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SCD_PHASE]
void serviceTensionLimiteeTS1508SCD_gereUnRapportRequisAtteint(void)
{
	if (serviceTensionLimiteeTS1508SCD_rapportRequisEnPourcentageSigne
			== serviceTensionLimiteeTS1508SCD_rapportEnCours)
	{
		return;
	}
	serviceTensionLimiteeTS1508SCD_compteurAvantChangement = 0;	
  serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SCD_PHASE] =
			serviceTensionLimiteeTS1508SCD_gereUnRapportRequisNonAtteint;	
}

void serviceTensionLimiteeTS1508SCD_gereUnRapportRequisNonAtteint(void)
{
signed int Requis;
signed int EnCours;

if (serviceTensionLimiteeTS1508SCD_rapportRequisEnPourcentageSigne == 0)
	{
		interfaceTS1508S_rapportEnPourcentageSignePourCD = 0;	
		serviceTensionLimiteeTS1508SCD_rapportEnCours = 0;		
		serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SCD_PHASE] =
				serviceTensionLimiteeTS1508SCD_gereUnRapportRequisAtteint;
		return;
	}

	serviceTensionLimiteeTS1508SCD_compteurAvantChangement++;
  if (serviceTensionLimiteeTS1508SCD_compteurAvantChangement
			< SERVICETENSIONLIMITEETS1508SCD_COMPTE_POUR_CHANGEMENT)
  {
    return;
  }
  serviceTensionLimiteeTS1508SCD_compteurAvantChangement = 0;
	
	Requis = (signed int)serviceTensionLimiteeTS1508SCD_rapportRequisEnPourcentageSigne;
	EnCours = (signed int)serviceTensionLimiteeTS1508SCD_rapportEnCours;
	if (Requis > EnCours)
	{
		EnCours += SERVICETENSIONLIMITEETS1508SCD_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT;
		if (EnCours > (Requis -1))
		{
			EnCours = Requis;
			serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SCD_PHASE] =
					serviceTensionLimiteeTS1508SCD_gereUnRapportRequisAtteint;			
		}
	}
	else
	{
		EnCours -= SERVICETENSIONLIMITEETS1508SCD_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT;
		if (EnCours < (Requis +1))
		{
			EnCours = Requis;
			serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SCD_PHASE] =
					serviceTensionLimiteeTS1508SCD_gereUnRapportRequisAtteint;						
		}
	}
	serviceTensionLimiteeTS1508SCD_rapportEnCours = (signed char)EnCours;
	interfaceTS1508S_rapportEnPourcentageSignePourCD = serviceTensionLimiteeTS1508SCD_rapportEnCours;
}

//Definitions de variables publiques:
signed char serviceTensionLimiteeTS1508SCD_rapportRequisEnPourcentageSigne;

//Definitions de fonctions publiques:
void serviceTensionLimiteeTS1508SCD_initialise(void)
{
	serviceTensionLimiteeTS1508SCD_compteurAvantChangement = 0;	
	serviceTensionLimiteeTS1508SCD_rapportRequisEnPourcentageSigne = 0;
	serviceTensionLimiteeTS1508SCD_rapportEnCours = 0;
	interfaceTS1508S_rapportEnPourcentageSignePourCD = 0;	
  serviceBaseDeTemps_execute[SERVICETENSIONLIMITEETS1508SCD_PHASE] =
			serviceTensionLimiteeTS1508SCD_gereUnRapportRequisAtteint;
}
