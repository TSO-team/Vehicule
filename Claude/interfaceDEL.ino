//interfaceDEL:
//Historique: 
// 2020-11-14, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL.h"
#include "piloteTicker.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL.h"

//Definitions privees
#define INTERFACEDEL_COMPTE_MAXIMUM_POUR_ALLUMER (\
		INTERFACEDEL_TEMPS_ALLUME_EN_MS / PILOTETICKER_PERIODE_EN_MS)
#define INTERFACEDEL_COMPTE_MAXIMUM_POUR_ETEINDRE (\
		INTERFACEDEL_TEMPS_ETEINT_EN_MS / PILOTETICKER_PERIODE_EN_MS)

//Declarations de fonctions privees:
void interfaceDEL_gereLEtatEteint(void);
void interfaceDEL_gereLEtatAllume(void);
void interfaceDEL_gereLEtatClignotantAllume(void);
void interfaceDEL_gereLEtatClignotantEteint(void);

//Definitions de variables privees:
unsigned long interfaceDEL_compteurDInterruptions;

//Definitions de fonctions privees:
void interfaceDEL_gereLEtatEteint(void)
{
	if (interfaceDEL_etatRequis == INTERFACEDEL_ETEINT)
	{
		return;
	}
	INTERFACEDEL_ALLUME_LA_DEL();
	if (interfaceDEL_etatRequis == INTERFACEDEL_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatAllume;
		return;
	}
	interfaceDEL_compteurDInterruptions = 0;
	serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatClignotantAllume;	
}

void interfaceDEL_gereLEtatAllume(void)
{
	if (interfaceDEL_etatRequis == INTERFACEDEL_ETEINT)
	{
		INTERFACEDEL_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatEteint;
		return;
	}
	if (interfaceDEL_etatRequis == INTERFACEDEL_CLIGNOTANT)
	{
		interfaceDEL_compteurDInterruptions = 0;
		serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatClignotantAllume;
		return;
	}
}

void interfaceDEL_gereLEtatClignotantAllume(void)
{
	if (interfaceDEL_etatRequis == INTERFACEDEL_ETEINT)
	{
		INTERFACEDEL_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatEteint;
		return;
	}
	if (interfaceDEL_etatRequis == INTERFACEDEL_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatAllume;
		return;
	}
	interfaceDEL_compteurDInterruptions++;
	if (interfaceDEL_compteurDInterruptions < INTERFACEDEL_COMPTE_MAXIMUM_POUR_ALLUMER)
	{
		return;
	}
	interfaceDEL_compteurDInterruptions = 0;
	INTERFACEDEL_ETEINT_LA_DEL();
  serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatClignotantEteint;
}

void interfaceDEL_gereLEtatClignotantEteint(void)
{
	if (interfaceDEL_etatRequis == INTERFACEDEL_ETEINT)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatEteint;
		return;
	}
	if (interfaceDEL_etatRequis == INTERFACEDEL_ALLUME)
	{
		INTERFACEDEL_ALLUME_LA_DEL();
		serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatAllume;
		return;
	}
	interfaceDEL_compteurDInterruptions++;
	if (interfaceDEL_compteurDInterruptions < INTERFACEDEL_COMPTE_MAXIMUM_POUR_ETEINDRE)
	{
		return;
	}
	interfaceDEL_compteurDInterruptions = 0;
	INTERFACEDEL_ALLUME_LA_DEL();			
  serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatClignotantAllume;
}

//Definitions de variables publiques:
unsigned char interfaceDEL_etatRequis;

//Definitions de fonctions publiques:
void interfaceDEL_initialise(void)
{
	interfaceDEL_etatRequis = INTERFACEDEL_ETEINT;
	INTERFACEDEL_ETEINT_LA_DEL();
	serviceBaseDeTemps_execute[INTERFACEDEL_PHASE] = interfaceDEL_gereLEtatEteint;
}
