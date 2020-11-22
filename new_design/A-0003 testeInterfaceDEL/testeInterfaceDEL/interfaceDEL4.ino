//interfaceDEL4:
//Historique: 
// 2020-11-15, Yves Roy, creation

//INCLUSIONS
#include "main.h"
#include "piloteSortieDEL4.h"
#include "piloteTicker.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL4.h"

//Definitions privees
#define INTERFACEDEL4_COMPTE_MAXIMUM_POUR_ALLUMER (\
		INTERFACEDEL4_TEMPS_ALLUME_EN_MS / PILOTETICKER_PERIODE_EN_MS)
#define INTERFACEDEL4_COMPTE_MAXIMUM_POUR_ETEINDRE (\
		INTERFACEDEL4_TEMPS_ETEINT_EN_MS / PILOTETICKER_PERIODE_EN_MS)

//Declarations de fonctions privees:
void interfaceDEL4_gereLEtatEteint(void);
void interfaceDEL4_gereLEtatAllume(void);
void interfaceDEL4_gereLEtatClignotantAllume(void);
void interfaceDEL4_gereLEtatClignotantEteint(void);

//Definitions de variables privees:
unsigned long interfaceDEL4_compteurDInterruptions;

//Definitions de fonctions privees:
void interfaceDEL4_gereLEtatEteint(void)
{
	if (interfaceDEL4_etatRequis == INTERFACEDEL4_ETEINT)
	{
		return;
	}
	INTERFACEDEL4_ALLUME_LA_DEL();
	if (interfaceDEL4_etatRequis == INTERFACEDEL4_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatAllume;
		return;
	}
	interfaceDEL4_compteurDInterruptions = 0;
	serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatClignotantAllume;	
}

void interfaceDEL4_gereLEtatAllume(void)
{
	if (interfaceDEL4_etatRequis == INTERFACEDEL4_ETEINT)
	{
		INTERFACEDEL4_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatEteint;
		return;
	}
	if (interfaceDEL4_etatRequis == INTERFACEDEL4_CLIGNOTANT)
	{
		interfaceDEL4_compteurDInterruptions = 0;
		serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatClignotantAllume;
		return;
	}
}

void interfaceDEL4_gereLEtatClignotantAllume(void)
{
	if (interfaceDEL4_etatRequis == INTERFACEDEL4_ETEINT)
	{
		INTERFACEDEL4_ETEINT_LA_DEL();		
		serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatEteint;
		return;
	}
	if (interfaceDEL4_etatRequis == INTERFACEDEL4_ALLUME)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatAllume;
		return;
	}
	interfaceDEL4_compteurDInterruptions++;
	if (interfaceDEL4_compteurDInterruptions < INTERFACEDEL4_COMPTE_MAXIMUM_POUR_ALLUMER)
	{
		return;
	}
	interfaceDEL4_compteurDInterruptions = 0;
	INTERFACEDEL4_ETEINT_LA_DEL();
  serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatClignotantEteint;
}

void interfaceDEL4_gereLEtatClignotantEteint(void)
{
	if (interfaceDEL4_etatRequis == INTERFACEDEL4_ETEINT)
	{
		serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatEteint;
		return;
	}
	if (interfaceDEL4_etatRequis == INTERFACEDEL4_ALLUME)
	{
		INTERFACEDEL4_ALLUME_LA_DEL();
		serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatAllume;
		return;
	}
	interfaceDEL4_compteurDInterruptions++;
	if (interfaceDEL4_compteurDInterruptions < INTERFACEDEL4_COMPTE_MAXIMUM_POUR_ETEINDRE)
	{
		return;
	}
	interfaceDEL4_compteurDInterruptions = 0;
	INTERFACEDEL4_ALLUME_LA_DEL();			
  serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatClignotantAllume;
}

//Definitions de variables publiques:
unsigned char interfaceDEL4_etatRequis;

//Definitions de fonctions publiques:
void interfaceDEL4_initialise(void)
{
	interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
	INTERFACEDEL4_ETEINT_LA_DEL();
	serviceBaseDeTemps_execute[INTERFACEDEL4_PHASE] = interfaceDEL4_gereLEtatEteint;
}
