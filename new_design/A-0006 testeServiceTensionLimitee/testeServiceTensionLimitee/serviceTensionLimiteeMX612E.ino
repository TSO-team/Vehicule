//serviceTensionLimiteeMX612E:
//Historique: 
// 2018-12-15, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "interfaceMX612E.h"
#include "serviceTensionLimiteeMX612E.h"

//Definitions privees
#define SERVICETENSIONLIMITEEMX612E_COMPTE_POUR_CHANGEMENT  ((unsigned int)\
  ((SERVICEBASEDETEMPS_FREQUENCE_EN_HZ*SERVICETENSIONLIMITEEMX612E_DUREE_DES_PAS_EN_MS)/1000.0))

//Declarations de fonctions privees:
void serviceTensionLimiteeMX612E_gereUnRapportRequisAtteint(void);
void serviceTensionLimiteeMX612E_gereUnRapportRequisNonAtteint(void);

//Definitions de variables privees:
unsigned int serviceTensionLimiteeMX612E_compteurAvantChangement;
signed char serviceTensionLimiteeMX612E_rapportEnCours;

//Definitions de fonctions privees:
//machine a etats: serviceBaseDeTemps_execute[SERVICETENSIONLIMITEEMX612E_PHASE]
void serviceTensionLimiteeMX612E_gereUnRapportRequisAtteint(void)
{
	if (serviceTensionLimiteeMX612E_rapportRequisEnPourcentageSigne
			== serviceTensionLimiteeMX612E_rapportEnCours)
	{
		return;
	}
	serviceTensionLimiteeMX612E_compteurAvantChangement = 0;	
  serviceBaseDeTemps_execute[SERVICETENSIONLIMITEEMX612E_PHASE] =
			serviceTensionLimiteeMX612E_gereUnRapportRequisNonAtteint;	
}

void serviceTensionLimiteeMX612E_gereUnRapportRequisNonAtteint(void)
{
signed int Requis;
signed int EnCours;

if (serviceTensionLimiteeMX612E_rapportRequisEnPourcentageSigne == 0)
	{
		interfaceMX612E_rapportEnPourcentageSigne = 0;	
		serviceTensionLimiteeMX612E_rapportEnCours = 0;		
		serviceBaseDeTemps_execute[SERVICETENSIONLIMITEEMX612E_PHASE] =
				serviceTensionLimiteeMX612E_gereUnRapportRequisAtteint;
		return;
	}

	serviceTensionLimiteeMX612E_compteurAvantChangement++;
  if (serviceTensionLimiteeMX612E_compteurAvantChangement
			< SERVICETENSIONLIMITEEMX612E_COMPTE_POUR_CHANGEMENT)
  {
    return;
  }
  serviceTensionLimiteeMX612E_compteurAvantChangement = 0;
	
	Requis = (signed int)serviceTensionLimiteeMX612E_rapportRequisEnPourcentageSigne;
	EnCours = (signed int)serviceTensionLimiteeMX612E_rapportEnCours;
	if (Requis > EnCours)
	{
		EnCours += SERVICETENSIONLIMITEEMX612E_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT;
		if (EnCours > (Requis -1))
		{
			EnCours = Requis;
			serviceBaseDeTemps_execute[SERVICETENSIONLIMITEEMX612E_PHASE] =
					serviceTensionLimiteeMX612E_gereUnRapportRequisAtteint;			
		}
	}
	else
	{
		EnCours -= SERVICETENSIONLIMITEEMX612E_ECART_MAXIMAL_DE_RAPPORT_EN_POURCENT;
		if (EnCours < (Requis +1))
		{
			EnCours = Requis;
			serviceBaseDeTemps_execute[SERVICETENSIONLIMITEEMX612E_PHASE] =
					serviceTensionLimiteeMX612E_gereUnRapportRequisAtteint;						
		}
	}
	serviceTensionLimiteeMX612E_rapportEnCours = (signed char)EnCours;
	interfaceMX612E_rapportEnPourcentageSigne = serviceTensionLimiteeMX612E_rapportEnCours;
}

//Definitions de variables publiques:
signed char serviceTensionLimiteeMX612E_rapportRequisEnPourcentageSigne;

//Definitions de fonctions publiques:
void serviceTensionLimiteeMX612E_initialise(void)
{
	serviceTensionLimiteeMX612E_compteurAvantChangement = 0;	
	serviceTensionLimiteeMX612E_rapportRequisEnPourcentageSigne = 0;
	serviceTensionLimiteeMX612E_rapportEnCours = 0;
	interfaceMX612E_rapportEnPourcentageSigne = 0;	
  serviceBaseDeTemps_execute[SERVICETENSIONLIMITEEMX612E_PHASE] =
			serviceTensionLimiteeMX612E_gereUnRapportRequisAtteint;
}
