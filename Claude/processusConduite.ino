/**************************************************************************************************
   Nom du fichier : processusConduite.c
   Auteur : Ayé Claude BROU
   Date de création : 2020-11-18
     Version 1.2

     Ce programme gère le transport des bloc dans le cadre du projet de centre de tri,
         projet de fin de cinquième session

    Versions:
    1.0:  Version IAR,

***************************************************************************************************/


//Inclusions
#include "main.h"
#include "serviceBaseDeTemps.h"
#include "interfaceDEL.h"
#include "interfaceDEL1.h"
#include "interfaceDEL2.h"
#include "interfaceDEL3.h"
#include "interfaceDEL4.h"
#include "interfaceLignes.h"
#include "interfaceWifi.h"
#include "interfaceTS1508S.h"
#include "serviceBaseDeTemps.h"
#include "processusConduite.h"


//Declarations de fonctions privees:
void processusConduite_deplacement(void);
void processusConduite_gere(void);
void processusConduite_arret(void);
void processusConduite_avance(void);
void processusConduite_recule(void);
void processusConduite_VireVersLaGauche(void);
void processusConduite_VireVersLaDroite(void);
void processusConduite_tourneUnPeuVersLaDroite(void);
void processusConduite_tourneUnPeuVersLaGauche(void);


//Definitions de variables privees:
unsigned long processusConduite_compteur;
unsigned char processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_ARRET;
unsigned char processusConduite_direction = PROCESSUSCONDUITE_DIRECTION_AVANT;
unsigned char processusConduite_etatConduite = ARRET;

//Definitions de fonctions privees:
void processusConduite_gere(void)
{
    //printf("\n%d", processusConduite_modeDeDeplacement);

    if (interfaceWifi_gereVehicule == ARRET)
    {
        processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_ARRET;
        return;
    }

    else if (interfaceLignes_litPCF() == 0X00)
    {
    
            processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_VIRE_DROITE;      
    }

    else if (interfaceLignes_litPCF() == 0X19 || interfaceLignes_litPCF() == 0x10 
            || interfaceLignes_litPCF() == 0X18 || interfaceLignes_litPCF() == 0x1C)
    {
        processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_DEMI_GAUCHE;
    }

    else if (interfaceLignes_litPCF() == 0X13 || interfaceLignes_litPCF() == 0x17 
            || interfaceLignes_litPCF() == 0X03 || interfaceLignes_litPCF() == 0x07)
    {
        processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_DEMI_DROITE;
    } 
    else if (interfaceLignes_litPCF() == 0X1E)
    {
        processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_VIRE_GAUCHE;
    }
    else if (interfaceLignes_litPCF() == 0XF)
    {
        processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_VIRE_DROITE;
    }
    else if (interfaceLignes_litPCF() == 0x1F || interfaceLignes_litPCF() == 0xFF)
    {
        processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_VIRE_DROITE;
    }
    else
    {
        if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_ARRIERE)
        {
            processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_RECULE;
        }
        else
        {
            processusConduite_modeDeDeplacement = PROCESSUSCONDUITE_MODE_AVANCE;
        }
        
    }
    serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE_ACTION] = processusConduite_deplacement;
}


void processusConduite_deplacement(void)
{
    
    if (processusConduite_modeDeDeplacement == PROCESSUSCONDUITE_MODE_ARRET)
    {
        serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE_DEPLACEMENT] = processusConduite_arret;
        return;
    }

    if (processusConduite_modeDeDeplacement == PROCESSUSCONDUITE_MODE_AVANCE)
    {
        serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE_DEPLACEMENT] = processusConduite_avance;
        return;
    }
    if (processusConduite_modeDeDeplacement == PROCESSUSCONDUITE_MODE_RECULE)
    {
        serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE_DEPLACEMENT] = processusConduite_recule;
        return;
    }
    if (processusConduite_modeDeDeplacement == PROCESSUSCONDUITE_MODE_DEMI_GAUCHE)
    {
        serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE_DEPLACEMENT] = processusConduite_tourneUnPeuVersLaGauche;
        return;
    }
    if (processusConduite_modeDeDeplacement == PROCESSUSCONDUITE_MODE_DEMI_DROITE)
    {
        serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE_DEPLACEMENT] = processusConduite_tourneUnPeuVersLaDroite;
        return;
    }
    if (processusConduite_modeDeDeplacement == PROCESSUSCONDUITE_MODE_VIRE_GAUCHE)
    {
        serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE_DEPLACEMENT] = processusConduite_VireVersLaGauche;
        return;
    }
    if (processusConduite_modeDeDeplacement == PROCESSUSCONDUITE_MODE_VIRE_DROITE)
    {
        serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE_DEPLACEMENT] = processusConduite_VireVersLaDroite;
        return;
    }
    serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE] = processusConduite_gere;
}




void processusConduite_arret(void)
{
    interfaceTS1508S_rapportEnPourcentageSignePourAB = 0;
    interfaceTS1508S_rapportEnPourcentageSignePourCD = 0;
    interfaceDEL_etatRequis = INTERFACEDEL_ETEINT;
    interfaceDEL1_etatRequis = INTERFACEDEL1_ETEINT;
    interfaceDEL2_etatRequis = INTERFACEDEL2_ETEINT;
    interfaceDEL3_etatRequis = INTERFACEDEL3_ETEINT;
    interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
}

void processusConduite_avance(void)
{
    interfaceTS1508S_rapportEnPourcentageSignePourAB = 80;
    interfaceTS1508S_rapportEnPourcentageSignePourCD = -80;

    interfaceDEL1_etatRequis = INTERFACEDEL1_ALLUME;
    interfaceDEL2_etatRequis = INTERFACEDEL2_ALLUME;
    interfaceDEL3_etatRequis = INTERFACEDEL3_ETEINT;
    interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
}

void processusConduite_recule(void)
{
    interfaceTS1508S_rapportEnPourcentageSignePourAB = -80;
    interfaceTS1508S_rapportEnPourcentageSignePourCD = 80;

    interfaceDEL1_etatRequis = INTERFACEDEL1_ETEINT;
    interfaceDEL2_etatRequis = INTERFACEDEL2_ETEINT;
    interfaceDEL3_etatRequis = INTERFACEDEL3_ALLUME;
    interfaceDEL4_etatRequis = INTERFACEDEL4_ALLUME;

}

void processusConduite_tourneUnPeuVersLaDroite(void)
{
    if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_AVANT)
    {
        interfaceTS1508S_rapportEnPourcentageSignePourAB = 100;
        interfaceTS1508S_rapportEnPourcentageSignePourCD = -80;

        interfaceDEL1_etatRequis = INTERFACEDEL1_ETEINT;
        interfaceDEL2_etatRequis = INTERFACEDEL2_ALLUME;
        interfaceDEL3_etatRequis = INTERFACEDEL3_ETEINT;
        interfaceDEL4_etatRequis = INTERFACEDEL4_ALLUME;
    }
    else if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_ARRIERE)
    {
        interfaceTS1508S_rapportEnPourcentageSignePourAB = -80;
        interfaceTS1508S_rapportEnPourcentageSignePourCD = 100;

        interfaceDEL1_etatRequis = INTERFACEDEL1_ALLUME;
        interfaceDEL2_etatRequis = INTERFACEDEL2_ETEINT;
        interfaceDEL3_etatRequis = INTERFACEDEL3_ALLUME;
        interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
    }
   
}

void processusConduite_tourneUnPeuVersLaGauche(void)
{
    if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_AVANT)
    {
        interfaceTS1508S_rapportEnPourcentageSignePourAB = 80;
        interfaceTS1508S_rapportEnPourcentageSignePourCD = -100;

        interfaceDEL1_etatRequis = INTERFACEDEL1_ALLUME;
        interfaceDEL2_etatRequis = INTERFACEDEL2_ETEINT;
        interfaceDEL3_etatRequis = INTERFACEDEL3_ALLUME;
        interfaceDEL4_etatRequis = INTERFACEDEL4_ETEINT;
    }
    else if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_ARRIERE)
    {
        interfaceTS1508S_rapportEnPourcentageSignePourAB = -100;
        interfaceTS1508S_rapportEnPourcentageSignePourCD = 80;

        interfaceDEL1_etatRequis = INTERFACEDEL1_ETEINT;
        interfaceDEL2_etatRequis = INTERFACEDEL2_ALLUME;
        interfaceDEL3_etatRequis = INTERFACEDEL3_ETEINT;
        interfaceDEL4_etatRequis = INTERFACEDEL4_ALLUME;
    }

}

void processusConduite_VireVersLaGauche(void)
{
    if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_AVANT)
    {
        interfaceTS1508S_rapportEnPourcentageSignePourAB = -100;
        interfaceTS1508S_rapportEnPourcentageSignePourCD = -100;

        interfaceDEL1_etatRequis = INTERFACEDEL1_CLIGNOTANT;
        interfaceDEL2_etatRequis = INTERFACEDEL2_ALLUME;
        interfaceDEL3_etatRequis = INTERFACEDEL3_CLIGNOTANT;
        interfaceDEL4_etatRequis = INTERFACEDEL4_ALLUME;
    }
   
    else if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_ARRIERE)
    {
        processusConduite_VireVersLaDroite();
    }
}

void processusConduite_VireVersLaDroite(void)
{
    if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_AVANT)
    {
        interfaceTS1508S_rapportEnPourcentageSignePourAB = 100;
        interfaceTS1508S_rapportEnPourcentageSignePourCD = 100;

        interfaceDEL1_etatRequis = INTERFACEDEL1_ALLUME;
        interfaceDEL2_etatRequis = INTERFACEDEL2_CLIGNOTANT;
        interfaceDEL3_etatRequis = INTERFACEDEL3_ALLUME;
        interfaceDEL4_etatRequis = INTERFACEDEL4_CLIGNOTANT;
    }


    else if (processusConduite_direction == PROCESSUSCONDUITE_DIRECTION_ARRIERE)
    {
        processusConduite_VireVersLaGauche();
    }
}


void processusConduite_initialise(void)
{
    processusConduite_compteur = 0;
    serviceBaseDeTemps_execute[PROCESSUSCONDUITE_PHASE] = processusConduite_gere;

}

