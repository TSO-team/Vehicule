//interfaceDEL3:
//Historique: 
// 2020-11-15, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL3.h"
#include "piloteTicker.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL3.h"

//Definitions privees
#define INTERFACEDEL3_COMPTE_MAXIMUM_POUR_ALLUMER (\
		INTERFACEDEL3_TEMPS_ALLUME_EN_MS / PILOTETICKER_PERIODE_EN_MS)
#define INTERFACEDEL3_COMPTE_MAXIMUM_POUR_ETEINDRE (\
		INTERFACEDEL3_TEMPS_ETEINT_EN_MS / PILOTETICKER_PERIODE_EN_MS)

//Declarations de fonctions privees:
void interfaceDEL3_gereLEtatEteint(void);
void interfaceDEL3_gereLEtatAllume(void);
void interfaceDEL3_gereLEtatClignotantAllume(void);
void interfaceDEL3_gereLEtatClignotantEteint(void);

//Definitions de variables privees:
unsigned long interfaceDEL3_compteurDInterruptions;

//Definitions de fonctions privees:
void interfaceDEL3_gereLEtatEteint(void)
{
	if (interfaceDEL3_etatRequis == INTERFACEDEL3_ETEINT)
	{
		return;
	}
	INTERFACEDEL3_ALLUME_LA_DEL();
	if (interfaceDEL3_etatRequis == INTERFACEDEL3_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatAllume;
		return;
	}
	interfaceDEL3_compteurDInterruptions = 0;
	serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatClignotantAllume;	
}

void interfaceDEL3_gereLEtatAllume(void)
{
	if (interfaceDEL3_etatRequis == INTERFACEDEL3_ETEINT)
	{
		INTERFACEDEL3_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatEteint;
		return;
	}
	if (interfaceDEL3_etatRequis == INTERFACEDEL3_CLIGNOTANT)
	{
		interfaceDEL3_compteurDInterruptions = 0;
		serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatClignotantAllume;
		return;
	}
}

void interfaceDEL3_gereLEtatClignotantAllume(void)
{
	if (interfaceDEL3_etatRequis == INTERFACEDEL3_ETEINT)
	{
		INTERFACEDEL3_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatEteint;
		return;
	}
	if (interfaceDEL3_etatRequis == INTERFACEDEL3_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatAllume;
		return;
	}
	interfaceDEL3_compteurDInterruptions++;
	if (interfaceDEL3_compteurDInterruptions < INTERFACEDEL3_COMPTE_MAXIMUM_POUR_ALLUMER)
	{
		return;
	}
	interfaceDEL3_compteurDInterruptions = 0;
	INTERFACEDEL3_ETEINT_LA_DEL();
  serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatClignotantEteint;
}

void interfaceDEL3_gereLEtatClignotantEteint(void)
{
	if (interfaceDEL3_etatRequis == INTERFACEDEL3_ETEINT)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatEteint;
		return;
	}
	if (interfaceDEL3_etatRequis == INTERFACEDEL3_ALLUME)
	{
		INTERFACEDEL3_ALLUME_LA_DEL();
		serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatAllume;
		return;
	}
	interfaceDEL3_compteurDInterruptions++;
	if (interfaceDEL3_compteurDInterruptions < INTERFACEDEL3_COMPTE_MAXIMUM_POUR_ETEINDRE)
	{
		return;
	}
	interfaceDEL3_compteurDInterruptions = 0;
	INTERFACEDEL3_ALLUME_LA_DEL();			
  serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatClignotantAllume;
}

//Definitions de variables publiques:
unsigned char interfaceDEL3_etatRequis;

//Definitions de fonctions publiques:
void interfaceDEL3_initialise(void)
{
	interfaceDEL3_etatRequis = INTERFACEDEL3_ETEINT;
	INTERFACEDEL3_ETEINT_LA_DEL();
	serviceBaseDeTemps_execute[INTERFACEDEL3_PHASE] = interfaceDEL3_gereLEtatEteint;
}
