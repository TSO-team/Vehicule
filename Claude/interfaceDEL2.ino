//interfaceDEL2:
//Historique: 
// 2020-11-15, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL2.h"
#include "piloteTicker.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL2.h"

//Definitions privees
#define INTERFACEDEL2_COMPTE_MAXIMUM_POUR_ALLUMER (\
		INTERFACEDEL2_TEMPS_ALLUME_EN_MS / PILOTETICKER_PERIODE_EN_MS)
#define INTERFACEDEL2_COMPTE_MAXIMUM_POUR_ETEINDRE (\
		INTERFACEDEL2_TEMPS_ETEINT_EN_MS / PILOTETICKER_PERIODE_EN_MS)

//Declarations de fonctions privees:
void interfaceDEL2_gereLEtatEteint(void);
void interfaceDEL2_gereLEtatAllume(void);
void interfaceDEL2_gereLEtatClignotantAllume(void);
void interfaceDEL2_gereLEtatClignotantEteint(void);

//Definitions de variables privees:
unsigned long interfaceDEL2_compteurDInterruptions;

//Definitions de fonctions privees:
void interfaceDEL2_gereLEtatEteint(void)
{
	if (interfaceDEL2_etatRequis == INTERFACEDEL2_ETEINT)
	{
		return;
	}
	INTERFACEDEL2_ALLUME_LA_DEL();
	if (interfaceDEL2_etatRequis == INTERFACEDEL2_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatAllume;
		return;
	}
	interfaceDEL2_compteurDInterruptions = 0;
	serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatClignotantAllume;	
}

void interfaceDEL2_gereLEtatAllume(void)
{
	if (interfaceDEL2_etatRequis == INTERFACEDEL2_ETEINT)
	{
		INTERFACEDEL2_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatEteint;
		return;
	}
	if (interfaceDEL2_etatRequis == INTERFACEDEL2_CLIGNOTANT)
	{
		interfaceDEL2_compteurDInterruptions = 0;
		serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatClignotantAllume;
		return;
	}
}

void interfaceDEL2_gereLEtatClignotantAllume(void)
{
	if (interfaceDEL2_etatRequis == INTERFACEDEL2_ETEINT)
	{
		INTERFACEDEL2_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatEteint;
		return;
	}
	if (interfaceDEL2_etatRequis == INTERFACEDEL2_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatAllume;
		return;
	}
	interfaceDEL2_compteurDInterruptions++;
	if (interfaceDEL2_compteurDInterruptions < INTERFACEDEL2_COMPTE_MAXIMUM_POUR_ALLUMER)
	{
		return;
	}
	interfaceDEL2_compteurDInterruptions = 0;
	INTERFACEDEL2_ETEINT_LA_DEL();
  serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatClignotantEteint;
}

void interfaceDEL2_gereLEtatClignotantEteint(void)
{
	if (interfaceDEL2_etatRequis == INTERFACEDEL2_ETEINT)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatEteint;
		return;
	}
	if (interfaceDEL2_etatRequis == INTERFACEDEL2_ALLUME)
	{
		INTERFACEDEL2_ALLUME_LA_DEL();
		serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatAllume;
		return;
	}
	interfaceDEL2_compteurDInterruptions++;
	if (interfaceDEL2_compteurDInterruptions < INTERFACEDEL2_COMPTE_MAXIMUM_POUR_ETEINDRE)
	{
		return;
	}
	interfaceDEL2_compteurDInterruptions = 0;
	INTERFACEDEL2_ALLUME_LA_DEL();			
  serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatClignotantAllume;
}

//Definitions de variables publiques:
unsigned char interfaceDEL2_etatRequis;

//Definitions de fonctions publiques:
void interfaceDEL2_initialise(void)
{
	interfaceDEL2_etatRequis = INTERFACEDEL2_ETEINT;
	INTERFACEDEL2_ETEINT_LA_DEL();


	serviceBaseDeTemps_execute[INTERFACEDEL2_PHASE] = interfaceDEL2_gereLEtatEteint;
}
