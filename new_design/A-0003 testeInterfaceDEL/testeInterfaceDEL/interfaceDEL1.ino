//interfaceDEL1:
//Historique: 
// 2020-11-15, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL.h"
#include "piloteTicker.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL1.h"

//Definitions privees
#define INTERFACEDEL1_COMPTE_MAXIMUM_POUR_ALLUMER (\
		INTERFACEDEL1_TEMPS_ALLUME_EN_MS / PILOTETICKER_PERIODE_EN_MS)
#define INTERFACEDEL1_COMPTE_MAXIMUM_POUR_ETEINDRE (\
		INTERFACEDEL1_TEMPS_ETEINT_EN_MS / PILOTETICKER_PERIODE_EN_MS)

//Declarations de fonctions privees:
void interfaceDEL1_gereLEtatEteint(void);
void interfaceDEL1_gereLEtatAllume(void);
void interfaceDEL1_gereLEtatClignotantAllume(void);
void interfaceDEL1_gereLEtatClignotantEteint(void);

//Definitions de variables privees:
unsigned long interfaceDEL1_compteurDInterruptions;

//Definitions de fonctions privees:
void interfaceDEL1_gereLEtatEteint(void)
{
	if (interfaceDEL1_etatRequis == INTERFACEDEL1_ETEINT)
	{
		return;
	}
	INTERFACEDEL1_ALLUME_LA_DEL();
	if (interfaceDEL1_etatRequis == INTERFACEDEL1_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatAllume;
		return;
	}
	interfaceDEL1_compteurDInterruptions = 0;
	serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatClignotantAllume;	
}

void interfaceDEL1_gereLEtatAllume(void)
{
	if (interfaceDEL1_etatRequis == INTERFACEDEL1_ETEINT)
	{
		INTERFACEDEL1_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatEteint;
		return;
	}
	if (interfaceDEL1_etatRequis == INTERFACEDEL1_CLIGNOTANT)
	{
		interfaceDEL1_compteurDInterruptions = 0;
		serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatClignotantAllume;
		return;
	}
}

void interfaceDEL1_gereLEtatClignotantAllume(void)
{
	if (interfaceDEL1_etatRequis == INTERFACEDEL1_ETEINT)
	{
		INTERFACEDEL1_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatEteint;
		return;
	}
	if (interfaceDEL1_etatRequis == INTERFACEDEL1_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatAllume;
		return;
	}
	interfaceDEL1_compteurDInterruptions++;
	if (interfaceDEL1_compteurDInterruptions < INTERFACEDEL1_COMPTE_MAXIMUM_POUR_ALLUMER)
	{
		return;
	}
	interfaceDEL1_compteurDInterruptions = 0;
	INTERFACEDEL1_ETEINT_LA_DEL();
  serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatClignotantEteint;
}

void interfaceDEL1_gereLEtatClignotantEteint(void)
{
	if (interfaceDEL1_etatRequis == INTERFACEDEL1_ETEINT)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatEteint;
		return;
	}
	if (interfaceDEL1_etatRequis == INTERFACEDEL1_ALLUME)
	{
		INTERFACEDEL1_ALLUME_LA_DEL();
		serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatAllume;
		return;
	}
	interfaceDEL1_compteurDInterruptions++;
	if (interfaceDEL1_compteurDInterruptions < INTERFACEDEL1_COMPTE_MAXIMUM_POUR_ETEINDRE)
	{
		return;
	}
	interfaceDEL1_compteurDInterruptions = 0;
	INTERFACEDEL1_ALLUME_LA_DEL();			
  serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatClignotantAllume;
}

//Definitions de variables publiques:
unsigned char interfaceDEL1_etatRequis;

//Definitions de fonctions publiques:
void interfaceDEL1_initialise(void)
{
	interfaceDEL1_etatRequis = INTERFACEDEL1_ETEINT;
	INTERFACEDEL1_ETEINT_LA_DEL();
	serviceBaseDeTemps_execute[INTERFACEDEL1_PHASE] = interfaceDEL1_gereLEtatEteint;
}
