//interfaceMX612E:
//Historique: 
// 2020-11-14, Yves Roy, creation a partir de interfaceTS1508S

//INCLUSIONS
#include "main.h"
#include "piloteTicker.h"
#include "pilotePWM.h"
#include "serviceBaseDeTemps.h"
#include "interfaceMX612E.h"

//Definitions privees
//pas de definitions privees

//Declarations de fonctions privees:
void interfaceMX612E_gere(void);
void interfaceMX612E_appliqueLeRapportEnPourcentageSigne(void);

//Definitions de variables privees:
signed char interfaceMX612E_valeurPrecedente;


//Definitions de fonctions privees:
void interfaceMX612E_gere(void)
{
      if (interfaceMX612E_valeurPrecedente != interfaceMX612E_rapportEnPourcentageSigne)
      {
        interfaceMX612E_valeurPrecedente = interfaceMX612E_rapportEnPourcentageSigne;
        interfaceMX612E_appliqueLeRapportEnPourcentageSigne();    
      }

}

void interfaceMX612E_appliqueLeRapportEnPourcentageSigne(void)
{
	if (interfaceMX612E_rapportEnPourcentageSigne == 0)
	{
#ifdef INTERFACEMX612E_OPTION_FREIN_ACTIF_POUR_AB  //0 et 0 entraine de la haute impedance 
		INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(0);
		INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(0);
#endif

#ifdef INTERFACEMX612E_OPTION_FREIN_INACTIF_POUR_AB //1 et 1 entraine une connexion a la masse
		INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(100);
		INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(100);
#endif
		return;
	}
	if (interfaceMX612E_rapportEnPourcentageSigne > 0)
	{
		INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(interfaceMX612E_rapportEnPourcentageSigne);
    INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(0);
		return;
	}
	INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_A(0);	
	INTERFACEMX612E_MODIFIE_LE_RAPPORT_CYCLIQUE_DE_B(
    (unsigned int)(-interfaceMX612E_rapportEnPourcentageSigne));
}

//Definitions de variables publiques:
signed char interfaceMX612E_rapportEnPourcentageSigne;

//Definitions de fonctions publiques:
void interfaceMX612E_initialise(void)
{
  interfaceMX612E_rapportEnPourcentageSigne = 0;
  interfaceMX612E_valeurPrecedente = 0;
    
	interfaceMX612E_appliqueLeRapportEnPourcentageSigne();
  serviceBaseDeTemps_execute[INTERFACEMX612E_PHASE] = interfaceMX612E_gere;
}
