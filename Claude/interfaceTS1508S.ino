//interfaceTS1508S:
//Historique: 
// 2020-11-14, Yves Roy, creation a partir de interfaceTS1508S pour STM8

//INCLUSIONS
#include "main.h"
#include "piloteTicker.h"
#include "pilotePWM.h"
#include "serviceBaseDeTemps.h"
#include "interfaceTS1508S.h"

//Definitions privees
//pas de definitions privees

//Declarations de fonctions privees:
void interfaceTS1508S_gere(void);
void interfaceTS1508S_appliqueLeRapportEnPourcentageSignePourAB(void);
void interfaceTS1508S_appliqueLeRapportEnPourcentageSignePourCD(void);

//Definitions de variables privees:
signed char interfaceTS1508S_valeurPrecedentePourAB;
signed char interfaceTS1508S_valeurPrecedentePourCD;


//Definitions de fonctions privees:
void interfaceTS1508S_gere(void)
{
	if (interfaceTS1508S_valeurPrecedentePourAB != interfaceTS1508S_rapportEnPourcentageSignePourAB)
	{
		interfaceTS1508S_valeurPrecedentePourAB = interfaceTS1508S_rapportEnPourcentageSignePourAB;
		interfaceTS1508S_appliqueLeRapportEnPourcentageSignePourAB();
	}
	if (interfaceTS1508S_valeurPrecedentePourCD != interfaceTS1508S_rapportEnPourcentageSignePourCD)
	{
		interfaceTS1508S_valeurPrecedentePourCD = interfaceTS1508S_rapportEnPourcentageSignePourCD;
		interfaceTS1508S_appliqueLeRapportEnPourcentageSignePourCD();
	}
}

void interfaceTS1508S_appliqueLeRapportEnPourcentageSignePourAB(void)
{
	if (interfaceTS1508S_rapportEnPourcentageSignePourAB == 0)
	{
#ifdef INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_AB  //0 et 0 entraine de la haute impedance 
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(0);
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(0);
#endif
#ifdef INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_AB //1 et 1 entraine une connexion a la masse
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(100);
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(100);
#endif
		return;
	}
	if (interfaceTS1508S_rapportEnPourcentageSignePourAB > 0)
	{
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(interfaceTS1508S_rapportEnPourcentageSignePourAB);
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(0);
		return;
	}
	INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(0);
	INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(
		(unsigned int)(-interfaceTS1508S_rapportEnPourcentageSignePourAB));
}

void interfaceTS1508S_appliqueLeRapportEnPourcentageSignePourCD(void)
{
	if (interfaceTS1508S_rapportEnPourcentageSignePourCD == 0)
	{
#ifdef INTERFACETS1508S_OPTION_FREIN_ACTIF_POUR_CD  //0 et 0 entraine de la haute impedance 
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_C(0);
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_D(0);
#endif
#ifdef INTERFACETS1508S_OPTION_FREIN_INACTIF_POUR_CD //1 et 1 entraine une connexion a la masse
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_C(100);
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_D(100);
#endif
		return;
	}
	if (interfaceTS1508S_rapportEnPourcentageSignePourCD > 0)
	{
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_C(interfaceTS1508S_rapportEnPourcentageSignePourCD);
		INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_D(0);
		return;
	}
	INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_C(0);
	INTERFACETS1508S_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_D(
		(unsigned int)(-interfaceTS1508S_rapportEnPourcentageSignePourCD));
}

//Definitions de variables publiques:
signed char interfaceTS1508S_rapportEnPourcentageSignePourAB;
signed char interfaceTS1508S_rapportEnPourcentageSignePourCD;

//Definitions de fonctions publiques:
void interfaceTS1508S_initialise(void)
{
	interfaceTS1508S_rapportEnPourcentageSignePourAB = 0;
	interfaceTS1508S_rapportEnPourcentageSignePourCD = 0;
	interfaceTS1508S_valeurPrecedentePourAB = 0;
	interfaceTS1508S_valeurPrecedentePourCD = 0;

	interfaceTS1508S_appliqueLeRapportEnPourcentageSignePourAB();
	interfaceTS1508S_appliqueLeRapportEnPourcentageSignePourCD();
	serviceBaseDeTemps_execute[INTERFACETS1508S_PHASE] = interfaceTS1508S_gere;
}